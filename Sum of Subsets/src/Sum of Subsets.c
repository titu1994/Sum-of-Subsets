#include <stdio.h>
#include <stdlib.h>

void sumOfSub(int,int,int);

static int m=0;
int*w;
int*x;

int main() {
	int i=0,sum=0,n=0;

	setbuf(stdout, NULL);

	printf("Enter size of array: ");
	scanf("%d",&n);
	w=(int*)calloc(n+1, sizeof(int));
	x=(int*)calloc(n+1, sizeof(int));
	printf("Enter %d elements: ",n);
	for(i=1;i <= n;i++) {
		scanf("%d",&w[i]);
		sum+=w[i];
		x[i]=0;
	}
	printf("Enter the sum to be obtained: ");
	scanf("%d",&m);
	if(sum < m)
	{
		printf("Not possible to obtain any subset !!! ");
	}
	else {
		printf("Possible Subsets are( 0 indicates exclusion and 1 indicates inclusion) : ");
		sumOfSub(0,1,sum);
	}
	return 0;
}

void sumOfSub(int s,int k,int r) {
	int i=0;
	x[k]=1;
	if(s+w[k]==m) {
		printf("\n");
		for(i=1;i <= k; i++)
			printf("\t%d",x[i]);
	}
	else if((s+w[k]+w[k+1]) <= m) {
		sumOfSub(s+w[k],k+1,r-w[k]);
	}
	if((s+r-w[k]) >= m  && (s+w[k+1]) <= m)
	{
		x[k]=0;
		sumOfSub(s,k+1,r-w[k]);
	}
}

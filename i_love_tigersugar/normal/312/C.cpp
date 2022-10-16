#include<stdio.h>
int i,n,t;
int main(void) {
	scanf("%d",&n);
	scanf("%d",&t);
	if (n*(n-1)<=2*t) {
		printf("no solution");
		return 0;
	}
	for (i=1;i<=n;i=i+1) printf("0 %d\n",i);
	return 0;
}
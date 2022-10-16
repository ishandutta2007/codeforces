#include<cstdio>
int main(void) {
	int i,j,n;
	scanf("%d",&n);
	if (n%2==0) {
		printf("-1");
		return 0;
	}
	for (i=0;i<n;i=i+1) printf("%d ",i); printf("\n");
	for (i=0;i<n;i=i+1) printf("%d ",i); printf("\n");
	for (i=0;i<n;i=i+1) printf("%d ",(2*i)%n); printf("\n");
	return 0;
}
#include<cstdio>
#define MAX   111
int a[MAX];
int c[3][MAX];
int n,r;
int max(const int &x,const int &y) {
	if (x>y) return (x); else return (y);
}
int main(void) {
	int i,j;
	scanf("%d",&n);
	c[0][0]=0;
	c[1][0]=0;
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&a[i]);
		for (j=0;j<2;j=j+1) c[j][i]=c[j][i-1]+(a[i]==j);		
	}
	r=-1;
	for (i=1;i<=n;i=i+1)
		for (j=i;j<=n;j=j+1)
			r=max(r,c[1][n]-(c[1][j]-c[1][i-1])+c[0][j]-c[0][i-1]);
	printf("%d",r);
	return 0;
}
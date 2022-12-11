#include <cstdio>

int main()
{
	int n,a[15][15];
	scanf("%d",&n);
	for (int i=0;i<n;i++) a[i][0]=a[0][i]=1;
	for (int i=1;i<n;i++)
		for (int j=1;j<n;j++)
			a[i][j]=a[i-1][j]+a[i][j-1];
	printf("%d",a[n-1][n-1]);
	return 0;
}
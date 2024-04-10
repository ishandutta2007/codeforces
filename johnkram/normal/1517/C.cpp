#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,i,j,k,a[505][505];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a[i]+i);
	for(i=1;i<=n;i++)
	{
		for(j=1;j+i-1<=n;j++)if(a[j+i-1][j]==i)break;
		for(k=1;k<j;k++)a[k+i][k]=a[k+i-1][k];
		for(;k+i<=n;k++)a[k+i][k]=a[k+i][k+1];
	}
	for(i=1;i<=n;i++)for(j=1;j<=i;j++)printf("%d%c",a[i][j],j==i?'\n':' ');
	return 0;
}
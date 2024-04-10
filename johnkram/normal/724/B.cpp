#include<bits/stdc++.h>
using namespace std;
int a[50][50],n,m,i,j,k;
bool check()
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1,k=0;j<=m;j++)if(a[i][j]!=j)k++;
		if(k>2)return 0;
	}
	return 1;
}
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>a[i][j];
	if(check())
	{
		puts("YES");
		return 0;
	}
	for(i=1;i<m;i++)for(j=i+1;j<=m;j++)
	{
		for(k=1;k<=n;k++)swap(a[k][i],a[k][j]);
		if(check())
		{
			puts("YES");
			return 0;
		}
		for(k=1;k<=n;k++)swap(a[k][i],a[k][j]);
	}
	puts("NO");
	return 0;
}
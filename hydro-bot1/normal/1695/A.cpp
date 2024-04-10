// Hydro submission #62c817ee8672efa577c13ba5@1657280494508
#include<bits/stdc++.h>
using namespace std;
int a[50][50];
int t; 
int main() 
{
	scanf("%d",&t); 
	while (t--) 
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int ans=1e9;
		int maxn=-1e9-5;
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=m;j++) 
			{
				cin>>a[i][j];
				if(a[i][j]>maxn) maxn = a[i][j];
			}
		}
		for(int i=1;i<=n;i++) 
		{
			for(int j = 1; j <= m; j++) 
			{
				if(a[i][j]==maxn) ans=min(ans,max(i,n-i+1)*max(j,m-j+1));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
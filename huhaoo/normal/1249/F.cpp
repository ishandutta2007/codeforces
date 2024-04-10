/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-10-22 22:50:54
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define int long long
const int N=210,inf=1e8;
int n,f[N][N],a[N],k,g[N];
#include<vector>
vector<int>e[N];
void dfs(int u,int F)
{
	fr(i,1,k)
		f[u][i]=-inf;
	f[u][0]=a[u];
	for(auto v:e[u])
		if(v!=F)
		{
			dfs(v,u);
			fr(j,0,k)
				g[j]=f[u][j];
			fr(j,0,k)
				fr(l,0,k)
					if(j+l>=k)
						f[u][min(j+1,l)]=max(f[u][min(j+1,l)],g[l]+f[v][j]);
			fr(j,0,k-1)
				f[u][j+1]=max(f[u][j+1],f[v][j]);
			f[u][0]=max(f[u][0],f[v][k]+a[u]);
			f[u][k]=max(f[u][k],f[v][k]);
		}
//	printf("%d\n",u);
//	fr(i,0,k)
//		printf("%d%c",f[u][i],i==k?'\n':' ');
}
signed main()
{
	n=read();
	k=read();
	fr(i,1,n)
		a[i]=read();
	fr(i,1,n-1)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	int ans=-inf;
	fr(i,0,k)
		ans=max(ans,f[1][i]);
	printf("%d\n",(signed)ans);
	return 0;
}
/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-01-05 22:14:20
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
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
#include<vector>
const int N=2010;
int n,ans[N][N],w[N],a[N],Ans[N];
std::vector<int> e[N];
void dfs(int u)
{
	for(auto v:e[u])
	{
		dfs(v);
		fr(i,1,w[v]) ans[u][++w[u]]=ans[v][i];
	}
	if(a[u]>w[u]){ printf("NO\n"); exit(0); }
	fd(i,w[u],a[u]+1) ans[u][i+1]=ans[u][i];
	ans[u][a[u]+1]=u; w[u]++;
}
int main()
{
	n=read();
	fr(i,1,n){ e[read()].push_back(i); a[i]=read(); }
	dfs(e[0][0]);
	printf("YES\n");
	fr(i,1,n) Ans[ans[e[0][0]][i]]=i;
	fr(i,1,n) printf("%d%c",Ans[i],i==n?'\n':' ');
	return 0;
}
/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-12-19 22:45:33
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
const int N=2000010;
int n,vis[N],ans[N],m;
std::vector<int> E[N],Ans[N];
void solve(int u)
{
	vis[u]=1;
	fr(i,0,E[u].size()-1) if(!vis[E[u][i]]) ans[++m]=E[u][i];
	ans[++m]=u;
	fd(i,E[u].size()-1,0) if(!vis[E[u][i]]) solve(E[u][i]);
}
int main()
{
	n=read();
	fr(i,1,n-1){ int u=read(),v=read(); E[u].push_back(v); E[v].push_back(u); }
	ans[++m]=1;
	solve(1);
	fr(i,1,m) Ans[ans[i]].push_back(i);
	fr(i,1,n) printf("%d %d\n",Ans[i][0],Ans[i][1]);
	return 0;
}
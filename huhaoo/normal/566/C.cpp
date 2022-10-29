/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-03-06 20:44:08
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
#define f80 long double
#define info std::pair<f80,f80>
#define pii std::pair<int,int>
info operator+(info a,info b){ return info(a.first+b.first,a.second+b.second); }
const int N=200010;
int n,v[N],m,p[N],vis[N],w[N],sw,rt,Rt;
f80 ans;
int Ans;
info I[N];
std::vector<pii> e[N];
void count(int u,int f)
{
	sw++;
	for(auto v:e[u]) if(v.first!=f&&!vis[v.first]) count(v.first,u);
}
void findrt(int u,int f)
{
	int mw=0; w[u]=1;
	for(auto v:e[u]) if(v.first!=f&&!vis[v.first])
	{
		findrt(v.first,u); w[u]+=w[v.first]; mw=std::max(mw,w[v.first]);
	}
	if(!rt||std::max(sw-w[u],mw)<Rt){ rt=u; Rt=std::max(sw-w[u],mw); }
}
info dfs(int u,int f,int l)
{
	info s=info(v[u]*pow(l,1.5),v[u]*pow(l,0.5));
	for(auto v:e[u]) if(v.first!=f) s=s+dfs(v.first,u,l+v.second);
	return s;
}
void solve(int u)
{
	sw=0; count(u,0); rt=0; findrt(u,0); u=rt; m=0;
	vis[u]=1;
	info s;
	for(auto v:e[u])
	{
		m++; p[m]=v.first; s=s+(I[m]=dfs(v.first,u,v.second));
	}
	if(s.first<ans){ ans=s.first; Ans=u; }
	fr(i,1,m) if(!vis[p[i]]&&s.second-2*I[i].second<0) solve(p[i]);
}
int main()
{
	n=read();
	fr(i,1,n) v[i]=read();
	fr(i,1,n-1){ int u=read(),v=read(),w=read(); e[u].push_back(pii(v,w)); e[v].push_back(pii(u,w)); }
	ans=1e100; solve(1);
	printf("%d %.10lf\n",Ans,double(ans));
	return 0;
}
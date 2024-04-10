#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
#define inf 1e9
#define ins insert
#define pb push_back
#define vi vector <int>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

struct node{int to,id;};
vector <node> mp[maxn];
int U[maxn],V[maxn],ind[maxn],ans[maxn];

inline void dfs(int u,int fa,int col)
{
	for(auto v:mp[u])
	{
		if(v.to==fa) continue;
		ans[v.id]=col; dfs(v.to,u,col^1);
	}
}

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(); rep(i,1,n) ind[i]=0,mp[i].clear(),ans[i]=0;
		rep(i,1,n-1)
		{
			int u=read(),v=read(); U[i]=u; V[i]=v;
			ind[u]++; ind[v]++; mp[u].pb({v,i}); mp[v].pb({u,i});
		}
		int F=0;
		rep(i,1,n) if(ind[i]>=3) {F=1; break;}
		if(F) puts("-1");
		else
		{
			int ff=0;
			rep(i,1,n) if(ind[i]==1) {ff=i; break;}
			dfs(ff,0,0);
			rep(i,1,n-1) if(ans[i]) printf("2 "); else printf("5 ");
			puts("");
		}
	}
	return 0;
}
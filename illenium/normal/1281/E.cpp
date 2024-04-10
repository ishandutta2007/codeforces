#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

struct node{int to; ll w;};
vector <node> mp[maxn];
bool vis[maxn],vis1[maxn],vis2[maxn],tp[maxn];
int siz[maxn],sz[maxn],n;
ll ans1,ans2;

inline void dfs(int u)
{
	vis[u]=1; siz[u]=1;
	for(int i=0;i<mp[u].size();i++)
	{
		node v=mp[u][i];
		if(vis[v.to]) continue;
		dfs(v.to);
		siz[u]+=siz[v.to];
	}
}

inline void dfs2(int u)
{
	vis2[u]=1;
	for(int i=0;i<mp[u].size();i++)
	{
		node v=mp[u][i];
		if(vis2[v.to]) continue;
		int tp3=siz[v.to],tp4=n-siz[v.to];
		int tmp=min(tp3,tp4);
		ans2+=(v.w)*tmp;
		dfs2(v.to);
	}
}

inline void dfs1(int u)
{
	vis1[u]=1;
	for(int i=0;i<mp[u].size();i++)
	{
		node v=mp[u][i];
		if(vis1[v.to]) continue;
		dfs1(v.to);
		if(tp[v.to]==0) ans1+=v.w,tp[u]^=1;
	}
}


int main()
{
	int T=read();
	while(T--)
	{
		n=read(); n*=2; ans1=0,ans2=0;
		for(int i=1;i<=n;i++) mp[i].clear(),vis[i]=0,vis1[i]=0,vis2[i]=0,tp[i]=0;
		for(int i=1;i<n;i++)
		{
			int u=read(),v=read(),w=read();
			mp[u].push_back((node){v,w});
			mp[v].push_back((node){u,w});
		}
		dfs(1); dfs1(1); dfs2(1); cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
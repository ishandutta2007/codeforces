#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e18
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int da[maxn],db[maxn],dc[maxn],n,m,a,b,c,C[maxn],vis[maxn];
ll pre[maxn];
vector <int> p[maxn];
queue <int> q;

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); m=read(); a=read(); b=read(); c=read();
		rep(i,1,m) C[i]=read(); sort(C+1,C+m+1);
		rep(i,1,m) pre[i]=pre[i-1]+C[i];
		rep(i,1,m)
		{
			int u=read(),v=read();
			p[u].pb(v); p[v].pb(u);
		}
		
		q.push(a); vis[a]=1;
		while(!q.empty())
		{
			int u=q.front(); q.pop();
			for(int i=0;i<p[u].size();i++)
			{
				int v=p[u][i]; if(vis[v]) continue;
				q.push(v); vis[v]=1; da[v]=da[u]+1;
			}
		}
		rep(i,1,n) vis[i]=0;
		
		q.push(b); vis[b]=1;
		while(!q.empty())
		{
			int u=q.front(); q.pop();
			for(int i=0;i<p[u].size();i++)
			{
				int v=p[u][i]; if(vis[v]) continue;
				q.push(v); vis[v]=1; db[v]=db[u]+1;
			}
		}
		rep(i,1,n) vis[i]=0;
		
		q.push(c); vis[c]=1;
		while(!q.empty())
		{
			int u=q.front(); q.pop();
			for(int i=0;i<p[u].size();i++)
			{
				int v=p[u][i]; if(vis[v]) continue;
				q.push(v); vis[v]=1; dc[v]=dc[u]+1;
			}
		}
		rep(i,1,n) vis[i]=0;
		
		ll ans=inf;
		rep(i,1,n)
		{
			int p1=da[i]+db[i]+dc[i];
			if(p1<=m) ans=min(ans,pre[p1]+pre[db[i]]);
		}
		printf("%lld\n",ans);
		
		rep(i,1,n) p[i].clear(),da[i]=0,db[i]=0,dc[i]=0,vis[i]=0;
	}
	return 0;
}
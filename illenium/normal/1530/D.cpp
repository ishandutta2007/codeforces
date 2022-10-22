#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
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

struct node{ll from,to,cap,flow;};
vector <node> edges;
int n,m,s,t,d[maxn],cur[maxn];
vector <int> mp[maxn];
queue <int> q;

inline void A(int u,int v,int w)
{
	edges.pb({u,v,w,0}); edges.pb({v,u,0,0});
	int pp=edges.size();
	mp[u].pb(pp-2); mp[v].pb(pp-1);
}

inline bool bfs()
{
	rep(i,0,t) d[i]=inf; d[s]=0; q.push(s);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<mp[u].size();i++)
		{
			node v=edges[mp[u][i]]; if(v.cap<=v.flow||d[v.to]!=inf) continue;
			d[v.to]=d[u]+1; q.push(v.to);
		}
	}
	if(d[t]!=inf) return true; return false;
}

inline ll dfs(int u,ll w)
{
	if(u==t||w==0) return w;
	int flow=0; ll r=0;
	for(int &i=cur[u];i<mp[u].size();i++)
	{
		node &v=edges[mp[u][i]];
		if(d[v.to]==d[u]+1&&(r=(dfs(v.to,min(w,v.cap-v.flow))))>0)
		{
			w-=r; v.flow+=r;
			edges[mp[u][i]^1].flow-=r; flow+=r;
			if(w==0) break;
		}
	}
	return flow;
}

inline ll max_flow()
{
	ll flow=0;
	while(bfs())
	{
		rep(i,0,t) cur[i]=0;
		flow+=dfs(s,inf);
	}
	return flow;
}

int ans[maxn],t1[maxn],t2[maxn],c1,c2,P[maxn],fr[maxn],Vis[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); s=0; t=2*n+1; rep(i,1,n) ans[i]=0,fr[i]=0,Vis[i]=0;
		rep(i,1,n)
		{
			int x=read(); P[i]=x;
			A(s,i,1); A(i,x+n,1); A(i+n,t,1);
		}
		printf("%d\n",max_flow()); c1=0; c2=0;
		rep(i,1,n)
		{
			if(edges[mp[i][1]].flow) ans[i]=P[i],fr[P[i]]=i,Vis[P[i]]=1;
			else t1[++c1]=i;
		}
		rep(i,1,n) if(!Vis[i]) t2[++c2]=i;
		//rep(i,1,c1) cout<<t2[i]<<" "; puts("");
		if(c1!=1)
		{
			rep(i,1,c1) ans[t1[i]]=t2[i];
			rep(i,1,c1-1) if(t1[i]==ans[t1[i]]) swap(ans[t1[i]],ans[t1[i+1]]);
			if(t1[c1]==ans[t1[c1]])
			{
				if(t1[c1]==t2[c1]) ans[t1[c1]]=P[t1[c1]],ans[fr[P[t1[c1]]]]=t1[c1];
				else ans[t1[c1]]=t2[c1];
			}
		}
		else
		{
			if(t1[1]==t2[1]) ans[t1[1]]=P[t1[1]],ans[fr[P[t1[1]]]]=t1[1];
			else ans[t1[1]]=t2[1];
		}
		rep(i,1,n) printf("%d ",ans[i]); puts("");
		edges.clear(); rep(i,0,t) mp[i].clear();
	}
	
	return 0;
}
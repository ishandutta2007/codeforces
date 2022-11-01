#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=5e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,m,c[N];
vector<int>e[N];
vector<pair<int,int>>g[N];
map<pair<int,int>,int>vis;
void gfs(int u,int p)
{
	for(int v:e[u])
	if(v!=p)
	{
		if(!vis.count({u,v}))
			vis[{u,v}]=vis[{v,u}]=c[u]^c[v];
		gfs(v,u);
	}
}
int main()
{
	// freopen("1.in","r",stdin);
	int t=1;
	sc(t);
	while(t--)
	{
		sc(n,m);
		vis.clear();
		rep(i,1,n) e[i].clear(),g[i].clear(),c[i]=0;
		rep(i,1,n-1)
		{
			int u,v,w;sc(u,v,w);
			e[u].push_back(v);
			e[v].push_back(u);
			if(w!=-1)
			{ 
				vis[{u,v}]=vis[{v,u}]=w;
				g[u].push_back({v,__builtin_popcount(w)&1});
				g[v].push_back({u,__builtin_popcount(w)&1});
			}
		}
		rep(i,1,m)
		{
			int u,v,w;sc(u,v,w);
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		bool flag=true;
		function<void(int)>dfs=[&](int u)
		{
			for(auto x:g[u])
			if(c[x.first])
			{
				if(x.second) flag&=c[x.first]!=c[u];
				else flag&=c[x.first]==c[u];
			}
			else
			{
				if(x.second) c[x.first]=c[u]==1?2:1;
				else c[x.first]=c[u];
				dfs(x.first);
			}
		};
		rep(i,1,n)
			if(!c[i]) c[i]=1,dfs(i);
		if(!flag) printf("NO\n");
		else
		{
			printf("YES\n");
			rep(i,1,n) c[i]--;
			gfs(1,0);
			for(auto it=vis.begin();it!=vis.end();it++)
				if(it->first.first<it->first.second)
				printf("%d %d %d\n",it->first.first,it->first.second,it->second);
		}
	}
}
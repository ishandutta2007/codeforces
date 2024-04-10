#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
using namespace std;
#define inf 0x3f3f3f3f
#define fi first
#define se second
const int N=55,mod=1e9+7;
int n,k,d[N],sd[N],ud[N],a[N][N];
vector<pair<int,int>>edge,all;
int ans=inf;
struct dsu
{
	vector<int>f;
	void init(int n){f.clear();rep(i,0,n) f.push_back(i);}
	int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
	void uni(int u,int v){f[getf(u)]=getf(v);}
}f1,f2;
vector<pair<int,int>>T,S,x1,x2;
bool vis[N][N];
vector<pair<int,int>>e[N][N];
pair<int,int>dis[N][N];
pair<int,int>pre[N][N];
bool inq[N][N];
bool aug(vector<pair<int,int>>&T)
{
	x1.clear();x2.clear();S.clear();
	f2=f1;
	rep(i,1,n) d[i]=sd[i];
	for(pair<int,int>&x:T)
		assert(!(x.first<=k&&x.second<=k)),f2.uni(x.first,x.second),d[x.first]++,d[x.second]++;
	for(pair<int,int>&g:all)
	{
		int i=g.first,j=g.second;
		if(!vis[i][j])
		{
			S.push_back({i,j});
			if(f2.getf(i)!=f2.getf(j))
				x1.push_back({i,j});
			if(d[i]<ud[i]&&d[j]<ud[j])
				x2.push_back({i,j});
		}
	}
	for(pair<int,int>&g:all)
	{
		int i=g.first,j=g.second;
		e[i][j].clear();
		dis[i][j]={inf,inf};
		pre[i][j]={0,0};
		inq[i][j]=false;
	}
	for(pair<int,int>&x:T)
	{
		f2=f1;
		for(pair<int,int>&y:T)
			if(y!=x) f2.uni(y.fi,y.se);
		for(pair<int,int>&y:S)
		{
			if(f2.getf(y.fi)!=f2.getf(y.se))
				e[x.fi][x.se].push_back({y.fi,y.se});
			d[x.fi]--;d[x.se]--;
			if(d[y.fi]<ud[y.fi]&&d[y.se]<ud[y.se])
				e[y.fi][y.se].push_back({x.fi,x.se});
			d[x.fi]++;d[x.se]++;
		}
	}
	queue<pair<int,int>>q;
	for(pair<int,int>&x:x1)
	{
		inq[x.fi][x.se]=true;
		dis[x.fi][x.se]={a[x.fi][x.se]*(vis[x.fi][x.se]?-1:1),1};
		q.push({x.fi,x.se});
	}
	while(!q.empty())
	{
		pair<int,int>u=q.front();q.pop();
		inq[u.fi][u.se]=false;
		int x=dis[u.fi][u.se].fi,y=dis[u.fi][u.se].se;
		y++;
		for(pair<int,int>&v:e[u.fi][u.se])
		{
			if(dis[v.fi][v.se]>make_pair(x+a[v.fi][v.se]*(vis[v.fi][v.se]?-1:1),y))
			{
				dis[v.fi][v.se]=make_pair(x+a[v.fi][v.se]*(vis[v.fi][v.se]?-1:1),y);
				pre[v.fi][v.se]=u;
				if(!inq[v.fi][v.se])
					q.push({v.fi,v.se}),inq[v.fi][v.se]=true;
			}
		}
	}
	pair<int,int>td;
	pair<int,int>mn={inf,inf};
	for(pair<int,int>&x:x2)
		if(dis[x.fi][x.se]<mn)
		{
			mn=dis[x.fi][x.se];
			td=x;
		}
	if(mn==make_pair(inf,inf)) return false;
	while(td.fi)
	{
		vis[td.fi][td.se]^=1;
		td=pre[td.fi][td.se];
		T.clear();
		for(pair<int,int>&g:all)
		{
			int i=g.first,j=g.second;
			if(vis[i][j]) T.push_back({i,j});
		}
	}
	return true;
}
int sol()
{
	T.clear();
	for(pair<int,int>&g:all)
	{
		int i=g.first,j=g.second;
		vis[i][j]=false;
	}
	while(aug(T));
	f2=f1;
	for(pair<int,int>&x:T) f2.uni(x.first,x.second);
	rep(i,2,n) if(f2.getf(1)!=f2.getf(i)) return inf;
	int res=0;
	for(pair<int,int>&x:T) res+=a[x.first][x.second];
	return res;
}
int dt=0;
void dfs(int p,int res,dsu f)
{
	if(p==edge.size())
	{
		dt++;
		f1=f;
		int sum=sol();
		ans=min(ans,res+sum);
		return;
	}
	dfs(p+1,res,f);
	int x=edge[p].fi,y=edge[p].se;
	if(f.getf(x)!=f.getf(y)&&sd[x]<ud[x]&&sd[y]<ud[y])
	{
		f.uni(x,y);
		sd[x]++;sd[y]++;
		dfs(p+1,res+a[x][y],f);
		sd[x]--;sd[y]--;
	}
}
bool cmp(pair<int,int>&x,pair<int,int>&y)
{
	return a[x.fi][x.se]<a[y.fi][y.se];
}
int main()
{
    scanf("%d%d",&n,&k);
	rep(i,1,k) scanf("%d",&ud[i]);
	rep(i,k+1,n) ud[i]=n;
	rep(i,1,n)
		rep(j,i+1,n)
		scanf("%d",&a[i][j]),a[j][i]=a[i][j];
	rep(i,1,k)
		rep(j,k+1,n)
		all.push_back({i,j});
	vector<pair<int,int>>g;
	f2.init(n);
	rep(i,k+1,n)
		rep(j,i+1,n)
			g.push_back({i,j});
	sort(g.begin(),g.end(),cmp);
	for(pair<int,int>&x:g)
		if(f2.getf(x.fi)!=f2.getf(x.se))
		{
			f2.uni(x.fi,x.se);
			all.push_back(x);
		}
	rep(i,1,k)
		rep(j,i+1,k)
		edge.push_back({i,j});
	dsu f;
	f.init(n);
	dfs(0,0,f);
    printf("%d\n",ans);
}
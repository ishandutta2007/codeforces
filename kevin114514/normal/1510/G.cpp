#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
void die(string S){puts(S.c_str());exit(0);}
vector<int> G[110];
int fa[110];
bool ok[110];
int app[110];
void GetRouteToSingleVertex(vector<int> &route,int target,int u)
{
	int f=fa[u];
	route.pb(u);
	int len=sz(route);
	if(len&&route.back()==target)
		return ;
	for(int i=0;i<sz(G[u]);i++)
	{
		int v=G[u][i];
		if(v==f)
			continue;
		GetRouteToSingleVertex(route,target,v);
		len=sz(route);
		if(len&&route.back()==target)
			return ;
	}
	route.pop_back();
	return ;
}
int depth[110],mdt[110],ver[110],md;
void GetAllDepths(int u)
{
	int f=fa[u];
	depth[u]=depth[f]+1;
	ver[depth[u]]=u;
	md=max(md,depth[u]);
	mdt[u]=depth[u];
	for(int i=0;i<sz(G[u]);i++)
	{
		int v=G[u][i];
		if(v==f)
			continue;
		GetAllDepths(v);
		mdt[u]=max(mdt[u],mdt[v]);
	}
	return ;
}
clock_t st;
void solve()
{
	for(int i=0;i<110;i++)
		G[i].clear();
	memset(ok,false,sizeof(ok));
	memset(app,0,sizeof(app));
	memset(fa,0,sizeof(fa));
	memset(depth,0,sizeof(depth));
	memset(mdt,0,sizeof(mdt));
	memset(ver,0,sizeof(ver));
	md=0;
	int n,k;
	cin>>n>>k;
	for(int i=2;i<=n;i++)
	{
		int f;
		cin>>f;
		G[f].pb(i);
		fa[i]=f;
	}
	for(int i=1;i<=n;i++)
		srt(G[i]);
	if(k==1)
	{
		puts("0");
		puts("1");
		return ;
	}
	GetAllDepths(1);
	int mdd=min(k,md);
	vector<int> res;
	GetRouteToSingleVertex(res,ver[mdd],1);
	int num=sz(res);
	int Depth=0;
	for(int i=0;i<sz(res);i++)
		app[res[i]]++;
	while(num<k&&(clock()-st)/CLOCKS_PER_SEC<2.5)
	{
		Depth++;
		for(int i=0;i<sz(res)&&num<k;i++)
			if(depth[res[i]]==Depth&&!ok[res[i]])
				for(int j=0;j<sz(G[res[i]])&&num<k;j++)
				{
					int from=res[i];
					int to=G[from][j];
					if(app[to])
						continue;
					res.insert(res.begin()+i,to);
					res.insert(res.begin()+i,from);
					i+=2;
					app[from]++;
					app[to]++;
					num++;
					ok[res[i]]=1;
				}
	}
	
	while(!res.empty()&&app[res.back()]>1)
	{
		app[res.back()]--;
		res.pop_back();
	}
	printf("%d\n",sz(res)-1);
	for(int i=0;i<sz(res);i++)
		printf("%d ",res[i]);
	puts("");
	return ;
}
int main()
{
	st=clock();
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
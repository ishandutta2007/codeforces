#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define per(i,x,y) for (int i=(x);i>=(y);i--)
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+5;
const ll inf=1e18;
int n,m,Q,cnt,head[N],q[N],top,f[N][25],dep[N],vis[N];ll dis[45][N],d[N];vector<pii> G[N];
void dfs(int u,int pr){
	vis[u]=1;
	rep (i,1,18) f[u][i]=f[f[u][i-1]][i-1];
	for (auto v:G[u]) if (v.fi!=pr)
		if (!vis[v.fi]){
			f[v.fi][0]=u,d[v.fi]=d[u]+v.se,dep[v.fi]=dep[u]+1;
			dfs(v.fi,u);
		} else q[++top]=u,q[++top]=v.fi;
}
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	per (i,20,0) if (tmp>>i&1) x=f[x][i];
	if (x==y) return x;
	per (i,20,0) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
ll get_dis(int x,int y){ return d[x]+d[y]-2*d[lca(x,y)]; }
void dij(int t,int s){
	priority_queue<pli,vector<pli>,greater<pli> > q;q.push(pli(0ll,s));
	rep (i,1,n) dis[t][i]=inf,vis[i]=0;dis[t][s]=0;
	while (!q.empty()){
		int u=q.top().se;q.pop();
		if (vis[u]) continue;vis[u]=1;
		for (auto i:G[u]){
			int v=i.fi,w=i.se;
			if (dis[t][v]>dis[t][u]+w)
				dis[t][v]=dis[t][u]+w,q.push(pli(dis[t][v],v));
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep (i,1,m){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		G[x].push_back(pii(y,z));
		G[y].push_back(pii(x,z));
	}
	dfs(1,0);
	sort(q+1,q+1+top);top=unique(q+1,q+1+top)-q-1;
	rep (i,1,top) dij(i,q[i]);
	scanf("%d",&Q);
	while (Q--){
		int x,y;scanf("%d%d",&x,&y);
		ll ans=get_dis(x,y);
		rep (i,1,top) ans=min(ans,dis[i][x]+dis[i][y]);
		printf("%I64d\n",ans);
	}
	return 0;
}
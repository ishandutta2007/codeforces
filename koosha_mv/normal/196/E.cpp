#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=2e5+99,inf=1e16;

int n,m,k,ans,a[N],p[N],dist[N],comp[N],par[N];
vector<pair<int,int> > g[N];
set<pair<int,int> > s;
vector<pair<int,pair<int,int> > > edge;

int Get_par(int u){
	if(par[u]<0) return u;
	return par[u] = Get_par(par[u]);
}
void merge(int u,int v,int w){
	if((u=Get_par(u))==(v=Get_par(v))) return ;
	ans += w;
	if(par[u] > par[v]) swap(u,v);
	par[u] += par[v];
	par[v] = u;
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	fill(dist,dist+N,inf);
	fill(par,par+N,-1);
	cin>>n>>m;
	f(i,0,m){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].pb({v, w});
		g[v].pb({u, w});
	}
	cin>>k;
	f(i,0,k){
		cin >> p[i];
		comp[p[i]] = p[i];
		dist[p[i]] = 0;
	}
	f(i,1,n+1){
		s.insert(mp(dist[i], i));
	}
	while(s.size()){
		int d = (*s.begin()).F, u = (*s.begin()).S;
		//cout << u << " " << d << endl;
		s.erase(s.begin());
		for(auto p : g[u]){
			if(d+p.S < dist[p.F]){
				s.erase({dist[p.F], p.F});
				comp[p.F] = comp[u];
				dist[p.F] = d+p.S;
				s.insert({dist[p.F], p.F});
			}
		}		
	}
	f(u,1,n+1){
		f(j,0,g[u].size()){
			int v = g[u][j].F, w = g[u][j].S;
			edge.pb(mp(dist[u]+w+dist[v], mp(comp[u], comp[v])));
		}
	}
	sort(edge.begin(), edge.end());
	f(i,0,edge.size()){
		int u = edge[i].S.F, v = edge[i].S.S, w = edge[i].F;
		merge(u,v,w);
	}
	cout << ans + dist[1];
}
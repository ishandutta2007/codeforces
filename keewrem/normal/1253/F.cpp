#include <bits/stdc++.h>
#pragma gcc optimize("O3")
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MAXN = 100010;
int N,M,K,Q;
vector<pii> g[MAXN],adj[MAXN];
pii dist[MAXN];
bool vis[MAXN], s[MAXN];
int uf[MAXN], sz[MAXN], dep[MAXN];
pii st[MAXN][20];
int find(int a){
	if(uf[a] != a)uf[a] = find(uf[a]);
	return uf[a];
}
bool uni(int a, int b){
	a = find(a); b = find(b);
	if(a == b)return 0;
	if(sz[a] > sz[b])swap(a,b);
	sz[b]+=sz[a];
	uf[a] = b;
	return 1;
}
void dfs(int n){
	vis[n] = 1;
	for(int i = 1; i < 20; i++){
		st[n][i] = st[st[n][i-1].fi][i-1];
		st[n][i].se = max(st[n][i-1].se,st[n][i].se);
	}
	for(auto x: adj[n]){
		if(vis[x.fi])continue;
		dep[x.fi] = dep[n]+1;
		st[x.fi][0] = {n,x.se};
		dfs(x.fi);
	}
}
signed main(){
	cin.tie(0);
	ios_base::sync_with_stdio(NULL);
	cin >> N >> M >> K >> Q;
	int a,b,c;
	for(int i = 0; i < M; i++){
		cin >> a >> b >> c;
		a--; b--;
		g[a].pb({b,c});
		g[b].pb({a,c});
	}
	priority_queue<pii> pq;
	for(int i = 0; i < N; i++)dist[i] = {111111111111111111,i};
	for(int i = 0; i < K; i++){pq.push({0,i}); dist[i] = {0,i};}
	int n, d;
	while(!pq.empty()){
		n = pq.top().se;
		d = -pq.top().fi;
		pq.pop();

		if(d > dist[n].fi)continue;
		for(auto x: g[n]){
			if(x.se + d < dist[x.fi].fi){
				dist[x.fi] = {x.se +d,dist[n].se};
				pq.push({-dist[x.fi].fi, x.fi});
			}
		}
	}
	//for(int i = 0; i < N; i++)cout << "dist " << dist[i].fi<< " " <<dist[i].se << endl;
	vector<pair<int,pii>> v;
	for(int i = 0; i < N; i++){
		sz[i] = 1; uf[i] = i;
		for(auto x: g[i]){
			if(dist[i].se < dist[x.fi].se)v.pb({dist[i].fi + dist[x.fi].fi + x.se,{dist[i].se,dist[x.fi].se}});
		}
	}
	sort(v.begin(),v.end());
	for(auto x: v){
		if(uni(x.se.se,x.se.fi)){
			adj[x.se.se].pb({x.se.fi,x.fi});
			adj[x.se.fi].pb({x.se.se,x.fi});
		//	cout <<"edge "<< x.se.se << " "<<x.se.fi << endl;
		}
	}
	dfs(0);
	while(Q--){
		cin >> a >> b;
		a--; b--;
		if(dep[a] < dep[b])swap(a,b);
		int ans = 0;
		for(int i = 19; i >= 0; i--){
			if(dep[a]-dep[b] >= (1<<i)){
				ans = max(st[a][i].se,ans);
				a = st[a][i].fi;
			}
		}
		if(a == b){
			cout << ans << endl;
			continue;
		}
		for(int i = 19; i >= 0; i--){
			if(st[a][i].fi != st[b][i].fi){
				ans = max({ans,st[a][i].se,st[b][i].se});
				a = st[a][i].fi;
				b = st[b][i].fi;
			}
		}
		ans = max({ans,st[a][0].se,st[b][0].se});
		cout << ans << "\n";
	}
	return 0;
}
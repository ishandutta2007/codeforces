//Krzysztof Boryczka
#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

const int N=3e5+5;

int p[N], diam[N], n, m, q;
vi G[N];
ii gosc;

int Find(int v){
	return p[v]==v ? v : p[v]=Find(p[v]);
}

void Union(int v, int u){
	v=Find(v); u=Find(u);
	if(v==u) return;
	p[u]=v;
	diam[v]=max({diam[v], diam[u], (diam[v]+1)/2+(diam[u]+1)/2+1});
}

void dfs(int v, int par, int dist){
	gosc=max(gosc, {dist, v});
	for(auto &x: G[v]) if(x!=par) dfs(x, v, dist+1);
}

void rob(int v){
	gosc={0, 0};
	dfs(v, v, 0);
	dfs(gosc.nd, gosc.nd, 0);
	diam[v]=gosc.st;
}

void solve(){
	int a, b;
	cin>>n>>m>>q;
	FOR(i, 1, n) p[i]=i;
	FOR(i, 1, m){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
		Union(a, b);
	}
	FOR(i, 1, n) diam[i]=0;
	FOR(i, 1, n) if(!diam[Find(i)]) rob(Find(i));
	FOR(i, 1, q){
		cin>>b>>a;
		if(b==1) cout<<diam[Find(a)]<<ent;
		else{
			cin>>b;
			Union(a, b);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}
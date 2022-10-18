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

const int N=5e5+5;
const int M=1<<19;

int n, tim;
vi G[N];
int sz[N], par[N], in[N], out[N], nxt[N];
int tree[M*2+5][2];

void dfs_sz(int v=1, int p=1){
	sz[v]=1;
	par[v]=p;
	for(auto &u: G[v]){
		if(u==p) continue;
		dfs_sz(u, v);
		sz[v]+=sz[u];
		if(G[v][0]==par[v] || sz[u]>sz[G[v][0]]) swap(u, G[v][0]);
	}
}

void dfs_hld(int v=1){
	in[v]=++tim;
	for(auto &u: G[v]){
		if(u==par[v]) continue;
		nxt[u]=(u==G[v][0] ? nxt[v] : u);
		dfs_hld(u);
	}
	out[v]=tim;
}

void add(int l, int r, int val, int op){
	l+=M-1; r+=M-1;
	while(l<=r){
		if(l&1) tree[l++][op]=val;
		if(!(r&1)) tree[r--][op]=val;
		l>>=1; r>>=1;
	}
}

int query(int l, int op){
	l+=M-1;
	int ret=0;
	while(l){
		ret=max(ret, tree[l][op]);
		l>>=1;
	}
	return ret;
}

void path(int v, int u, int val, int op){
	while(nxt[v]!=nxt[u]){
		if(in[v]>in[u]) swap(v, u);
		add(in[nxt[u]], in[u], val, op);
		u=par[nxt[u]];
	}
	if(in[v]>in[u]) swap(v, u);
	add(in[v], in[u], val, op);
}

void solve(){
	int a, b, q;
	cin>>n;
	FOR(i, 2, n){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs_sz();
	dfs_hld();
	cin>>q;
	FOR(i, 1, q){
		cin>>a>>b;
		if(a==1) add(in[b], out[b], i, 1);
		if(a==2) path(1, b, i, 0);
		if(a==3) cout<<(query(in[b], 0)<query(in[b], 1))<<ent;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
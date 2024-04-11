// Krzysztof Boryczka
#pragma GCC optimize("O3")
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

const int N=1e5+5;
const int LOG=17;

int n;
int par[N], dpth[N], cnt[N], ans[N];
int anc[N][LOG+1];
vii G[N];

void prep_dfs(int v, int p){
	par[v]=p;
	dpth[v]=dpth[p]+1;
	for(auto &x: G[v]) if(!par[x.st]) prep_dfs(x.st, v);
}

void prep(){
	prep_dfs(1, 1);
	FOR(i, 1, n) anc[i][0]=par[i];
	FOR(j, 1, LOG) FOR(i, 1, n) anc[i][j]=anc[anc[i][j-1]][j-1];
}

int lca(int a, int b){
	if(dpth[a]<dpth[b]) swap(a, b);
	FORD(i, LOG, 0) if(dpth[anc[a][i]]>=dpth[b]) a=anc[a][i];
	FORD(i, LOG, 0) if(anc[a][i]!=anc[b][i]) a=anc[a][i], b=anc[b][i];
	return a == b ? a : par[a];
}

void dfs(int v, int p){
	for(auto &x: G[v]){
		if(x.st==p) continue;
		dfs(x.st, v);
		ans[x.nd]=cnt[x.st];
		cnt[v]+=cnt[x.st];
	}
}

void solve(){
	int a, b, q;
	cin>>n;
	FOR(i, 2, n){
		cin>>a>>b;
		G[a].pb({b, i});
		G[b].pb({a, i});
	}
	prep();
	cin>>q;
	FOR(i, 1, q){
		cin>>a>>b;
		cnt[a]++;
		cnt[b]++;
		cnt[lca(a, b)]-=2;
	}
	dfs(1, 1);
	FOR(i, 2, n) cout<<ans[i]<<sp;
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
    // FOR(te, 1, tt){
	// 	cout<<"Case #"<<te<<": ";
	// 	solve();
	// }
	solve();
	return 0;
}
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

const int N=1e5+10;

int n;
vi ans;
int layer[N], val[N], klik[N];
vi G[N];

void dfs(int v, int p, int dpt){
	layer[dpt+2]^=layer[dpt];
	if(layer[dpt]^val[v]){
		klik[v]=1;
		ans.pb(v);
		layer[dpt+2]^=1;
	}
	for(auto &x: G[v]){
		if(x==p) continue;
		dfs(x, v, dpt+1);
	}
	if(klik[v]) layer[dpt+2]^=1;
	layer[dpt+2]^=layer[dpt];
}


void solve(){
	int a, b;
	cin>>n;
	FOR(i, 2, n){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	FOR(i, 1, n) cin>>val[i];
	FOR(i, 1, n){
		cin>>a;
		val[i]^=a;
	}
	dfs(1, 1, 1);
	cout<<SIZE(ans)<<ent;
	for(auto &x: ans) cout<<x<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}
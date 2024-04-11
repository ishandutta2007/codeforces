#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define X first
#define Y second

const int N = 3e5+5;

vi G[N];
int vis[N];
int col[N];
int tim;

void dfs(int v, int p){
	vis[v] = ++tim;
	col[v] = col[p]^1;
	TRAV(x, G[v]){
		if(x == p) continue;
		if(vis[x] && col[v] && col[x]) col[v] = 0;
	}
	TRAV(x, G[v]){
		if(x == p) continue;
		if(!vis[x]) dfs(x, v);
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	tim = 0;
	FOR(i, 1, n+1) G[i].clear();
	FOR(i, 1, n+1) vis[i] = col[i] = 0;
	FOR(i, 0, m){
		int a, b;
		cin >> a >> b;
		G[a].PB(b);
		G[b].PB(a);
	}
	dfs(1, 1);
	FOR(i, 1, n+1){
		if(!vis[i]){
			cout << "NO\n";
			return;
		}
	}
	vi ans;
	FOR(i, 1, n+1) if(col[i]) ans.PB(i);
	cout << "YES\n";
	cout << SZ(ans) << '\n';
	TRAV(x, ans) cout << x << ' ';
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	FOR(te, 0, tt){
		// cout << "Case #" << te+1 << ": ";
		solve();
	}
	// solve();
	return 0;
}
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

const int N = 2e5+5;

bool cyc[N];
int vis[N], nr[N], sz[N];
int n, nrx;
vi G[N], stos;

void cyc_find(int v, int p){
	vis[v] = ++nrx;
	stos.PB(v);
	TRAV(x, G[v]){
		if(x == p) continue;
		if(!vis[x]) cyc_find(x, v);
		if(vis[x] < vis[v]){
			for(int i = SZ(stos)-1; i >= 0; i--){
				cyc[stos[i]] = 1;
				if(stos[i] == x) break;
			}
		}
	}
	stos.pop_back();
}

void dfs(int v, int p){
	nr[v] = nr[p];
	sz[nr[v]]++;
	TRAV(x, G[v]){
		if(x == p || cyc[x]) continue;
		dfs(x, v);
	}
}

void solve(){
	cin >> n;
	FOR(i, 0, n){
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].PB(b);
		G[b].PB(a);
	}
	cyc_find(0, 0);
	FOR(i, 0, n) if(cyc[i]) nr[i] = i, dfs(i, i);
	ll ans = 0;
	FOR(i, 0, n) ans += 2*n - sz[nr[i]]-1;
	cout << ans/2 << '\n';
	FOR(i, 0, n) cyc[i] = vis[i] = sz[i] = 0;
	FOR(i, 0, n) G[i].clear();
	nrx = 0;
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
//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

struct fenwick{
	vector<int> fen;
	fenwick(int n = 0){
		fen.resize(n + 20, 0);
		return;
	}
	void upd(int x, int y){
		assert(x + 5 < Sz(fen));
		for(x += 5; x < Sz(fen); x += x & -x){
			fen[x] += y;
		}
		return;
	}
	int get(int x){
		x = min(x, Sz(fen) - 6);
		int y = 0;
		for(x += 5; x > 0; x -= x & -x){
			assert(x < Sz(fen));
			y += fen[x];
		}
		return y;
	}
};

int n, par[maxn], sz[maxn], ans[maxn];
vector<int> g[maxn];
fenwick fen[maxn], fn, kol;
vector<int> vec[maxn];

void dfs(int v){
	sz[v] = 1;
	for(int u : g[v]){
		dfs(u);
		sz[v] += sz[u];
	}
	kol.upd(sz[v], 1);
	return;
}
void solve(int v, int ssz){
	int mx = n - sz[v], mn = n - sz[v], bc = v, bbc = -1, mxx = -1, mx2 = -n - 5;
	if(par[v] == 0) mx = -n - 10, mn = n + 10;
	fn.upd(sz[v], 1);
	for(int u : g[v]){
		if(sz[u] < mn) mn = sz[u];
		if(sz[u] > mx2){
			mx2 = sz[u];
		}
		if(mx2 > mx){
			swap(mx, mx2);
			bc = u;
		}
		if(mxx < sz[u]){
			mxx = sz[u];
			bbc = u;
		}
	}
	for(int u : g[v]){
		if(u == bbc) solve(u, ssz);
		else solve(u, sz[u]);
	}
	if(bc != v){
		int l = -1, r = n - 1;
		while(r - l > 1){
			int mid = (l + r) >> 1;
			if(fen[bc].get(mid - mn) - fen[bc].get(mx - mid - 1) > 0) r = mid;
			else l = mid;
		}
		ans[v] = max(r, mx2);
	}
	for(int u : g[v]){
		if(u == bbc) continue;
		for(int x : vec[u]){
			vec[bbc].pb(x);
			fen[bbc].upd(x, 1);
		}
	}
	if(~bbc){
		vec[v].swap(vec[bbc]);
		fen[v].fen.swap(fen[bbc].fen);
	}
	else fen[v] = fenwick(ssz);
	vec[v].pb(sz[v]);
	fen[v].upd(sz[v], 1);
	fn.upd(sz[v], -1);
	if(bc == v){
		int l = -1, r = n - 1;
		while(r - l > 1){
			int mid = (l + r) >> 1;
			if((kol.get(mid - mn) - kol.get(mx - mid - 1)) - (fen[v].get(mid - mn) - fen[v].get(mx - mid - 1)) -
			(fn.get(mid - mn) - fn.get(mx - mid - 1)) + (fn.get(mid - mn + sz[v]) - fn.get(mx - mid - 1 + sz[v])) > 0){
				r = mid;
			}
			else l = mid;
		}
		ans[v] = max(r, mx2);
	}
	if(mx > 0) ans[v] = min(ans[v], mx);
}

int main(){
	fast_io;
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		int v, u;
		cin >> v >> u;
		par[u] = v;
		g[v].pb(u);
	}
	kol = fenwick(n);
	fn = fenwick(n);
	dfs(g[0][0]);
	solve(g[0][0], n);
	for(int i = 1; i <= n; i++){
		cout << ans[i] << "\n";
	}
	
	return 0;
}
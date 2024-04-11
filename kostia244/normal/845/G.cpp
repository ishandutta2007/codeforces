#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:26777216")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
//const ll mod = 1e9 + 7;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
vector<vector<pair<int, int>>> g;
vi pxor;
bitset<100100> vis;
vector<pair<pair<int, int>, int>> back;

void dfs(int v) {
	vis.set(v);
	for(auto i : g[v]) {
		int to = i.first;
		if(vis.test(to)) {
			back.pb({{v, to}, i.second});
		} else {
			pxor[to] = pxor[v]^i.second;
			dfs(to);
		}
	}
}

vi basis;
void add(ll x) {
	for(auto i : basis)
		x = min(x, x^i);
	if(x)
		basis.pb(x);
}

void get(int &x, int b) {
	if(x&(1<<b)) return;
	for(auto i : basis)
		if(x > (x^i) && !((x^i)&(1<<b))) {
			x=x^i;
			return;
		}
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	g.resize(n+1);
	pxor.resize(n+1);
	for(int f, t, c, i = 0; i < m; i++) {
		cin >> f >> t >> c;
		g[f].pb({t, c});
		g[t].pb({f, c});
	}
	dfs(1);
	for(auto i : back)
		add(pxor[i.first.second]^pxor[i.first.first]^i.second);
	int ans = pxor[n];
	for(int i = 30;i>=0;i--)
		get(ans, i);
	cout << ans;
}
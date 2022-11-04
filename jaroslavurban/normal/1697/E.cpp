#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

const int mod = 998244353;

const int N = 1010;

struct mint {
	ll x;
	mint(ll x = 0) : x(x) {} 
	static ll inv(ll a, ll m) { return a %= m == 1 ? 1 : m - (m / a) * inv(m, a); }
	mint operator+(mint b) { return (x + b.x) % mod; }
	mint operator-(mint b) { return (x - b.x + mod) % mod; }
	mint operator*(mint b) { return (x * b.x) % mod; }
	mint operator/(mint b) { return (x * inv(b.x, mod)) % mod; }
	explicit operator int() const { return x; }
};

mint F[N], IF[N];

mint choose(int n, int k) { return k > n || k < 0 ? 0 : F[n] * IF[k] * IF[n - k]; }

int dist(pair<int, int> a, pair<int, int> b) { return abs(a.first - b.first) + abs(a.second - b.second); }

void ProGamerMove() {
	int n; cin >> n;
	vector<pair<int, int>> p(n);
	for (auto& [x, y] : p) cin >> x >> y;
	vector<vector<int>> g(n);
	for (int i = 0; i < n; ++i) {
		int mn = INT_MAX;
		for (int j = 0; j < n; ++j) if (j != i) mn = min(mn, dist(p[i], p[j]));
		for (int j = 0; j < n; ++j) if (dist(p[i], p[j]) == mn) g[i].push_back(j);
	}
	vector<int> cnts(5);
	for (int i = 0; i < n; ++i) {
		vector<int> verts;
		queue<int> q; q.push(i);
		vector<int> vis(n);
		int eds = 0;
		while (q.size()) {
			int u = q.front(); q.pop();
			if (vis[u]) continue;
			eds += g[u].size();
			verts.push_back(u);
			vis[u] = true;
			for (int v : g[u]) q.push(v);
		}
		if (eds == verts.size() * (verts.size() - 1)) ++cnts[verts.size()];
		else ++cnts[1];
	}
	vector<mint> colors(n + 1);
	colors[cnts[1]] = choose(n, cnts[1]) * F[cnts[1]];
	for (int c = 2; c <= 4; ++c) if (cnts[c]) {
		vector<mint> ncolors(n + 1);
		for (int comb = 0; comb <= cnts[c] / c; ++comb) {
			int add = cnts[c] - comb * (c - 1);
			if (!add) continue;
			for (int i = n; i >= add; --i) {
				ncolors[i] = ncolors[i] + colors[i - add] * choose(cnts[c] / c, comb) * choose(n - (i - add), add) * F[add];
			}
		}
		swap(colors, ncolors);
	}
	cout << (int)accumulate(colors.begin(), colors.end(), mint(0)) << '\n';
}

signed main(){
	F[0] = IF[0] = IF[1] = 1;
	for (int i = 2; i < N; ++i) IF[i] = mint(mod) - mint(mod / i) * IF[mod % i];
	for (int i = 1; i < N; ++i) F[i] = mint(i) * F[i - 1], IF[i] = IF[i] * IF[i - 1];
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	//cin >> tc;
	while (tc--) ProGamerMove();
}
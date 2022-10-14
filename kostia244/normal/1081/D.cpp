#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 998244353;
int wefucked = 0, k;
struct dsu {
	vector<int> r, p, sp;
	dsu(int n) : r(n, 1), sp(n, 0), p(n) {iota(all(p), 0);}
	int par(int v) {
		return v == p[v] ? v : p[v] = par(p[v]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if(i == j) return;
		if(r[i] < r[j]) swap(i, j);
		p[j] = i;
		r[i] += r[j];
		sp[i] += sp[j];
		wefucked |= sp[i] == k;
	}
};
int n, m;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k;
	dsu d(n+1);
	for(int t, i = k; i--;) cin >> t, d.sp[t]++;
	vector<array<int, 3>> e(m);
	for(auto &i : e) cin >> i[2] >> i[1] >> i[0];
	sort(all(e));
	for(auto [c, f, t] : e) {
		d.unite(f, t);
		if(wefucked) {
			for(int i = 1; i <= k; i++) cout << c << " "; cout << '\n';exit(0);
		}
	}
}
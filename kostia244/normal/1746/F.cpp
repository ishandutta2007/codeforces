#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
struct Fenwick {
	vector<int> f;
	Fenwick(int n) : f(n+1) {}
	void add(int pos, int val) {
		for(; pos < f.size(); pos += pos&-pos)
			f[pos] += val;
	}
	int get(int r) {
		int res = 0;
		for(; r; r -= r&-r)
			res += f[r];
		return res;
	}
	int get(int l, int r) {
		return get(r) - get(l-1);
	}
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, q;
	cin >> n >> q;
	vector<int> _a(n), vals;
	for(auto &i : _a) cin >> i, vals.push_back(i);
	vector<array<int, 4>> queries(q);
	for(auto &[t, a, b, c] : queries) {
		cin >> t >> a >> b;
		if(t == 2) cin >> c;
		else vals.push_back(b);
	}
	sort(all(vals));
	for(auto &i : _a) i = lower_bound(all(vals), i) - vals.begin();
	for(auto &[t, a, b, c] : queries) {
		if(t == 1)
			b = lower_bound(all(vals), b) - vals.begin();
	}
	bitset<1<<20> ans = 0; ans = ~ans;
	vector<int> col(1<<20);
	int pos;
	for(int iter = 0; iter < 64; iter++) {
		auto a = _a;
		bitset<1<<20> cur = 0;
		Fenwick f(n);
		pos = 0;
		for(auto &i : col) i = rng() & 1;
		for(int i = 0; i < n; i++)
			f.add(i+1, col[a[i]]);
		for(auto [t, x, y, z] : queries) {
			if(t == 1) {
				f.add(x, col[y] - col[a[x-1]]);
				a[x-1] = y;
			} else {
				cur[pos++] = f.get(x, y) % z == 0;
			}
		}
		ans &= cur;
	}
	for(int i = 0; i < pos; i++)
		report(ans[i]);
}
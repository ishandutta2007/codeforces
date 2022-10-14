// Problem: D. Cute number
// Contest: Codeforces - Codeforces Round #796 (Div. 1)
// URL: https://codeforces.com/contest/1687/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int A = 2e6 + 1024;
struct dsu {
	vector<int> e;
	vector<array<int, 2>> D;
	dsu(int n) : e(n, -1), D(n) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		D[a][0] = min(D[a][0], D[b][0]);
		D[a][1] = max(D[a][1], D[b][1]);
		return true;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i : a)
		cin >> i;
	
	vector<vector<int>> merge(A);
	for(int i = 1; i < n; i++) {
		merge[a[i] - a[i-1] + 1].push_back(i);
	}
	dsu d(n);
	for(int i = 0; i < n; i++)
		d.D[i] = {i, i};
	vector<ll> values;
	ll lst = 0;
	for(int lvl = 0; lvl < A; lvl++) {
		int iters = 0;
		for(int i = 0; i < n; i = d.D[i][1] + 1) {
			i = d.find(i);
			int l = d.D[i][0], r = d.D[i][1];
			ll minShift = max(0ll, lvl*1ll*lvl - a[l]);
			ll maxShift = lvl*1ll*(lvl+1) - a[r] + 1;
			if(minShift < maxShift) {
				values.push_back(((minShift*2 + 1)<<20) + r-l+1);
				values.push_back(((maxShift*2)<<20) + r-l+1);
			}
		}
		for(auto i : merge[lvl])
			d.join(i - 1, i);
	}
	sort(all(values));
	int cur = 0;
	for(auto i : values) {
		cur += (i & (1ll << 20)) ? (i & ((1<<20)-1)) : -(i & ((1<<20)-1));
		// cout << cur << endl;
		if(cur == n) {
			cout << (i>>21) << '\n';
			return 0;
		}
	}
}
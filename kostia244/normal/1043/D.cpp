// Problem: D. Mysterious Crime
// Contest: Codeforces - Codeforces Round #519 by Botan Investments
// URL: https://codeforces.com/contest/1043/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
struct dsu {
	vector<int> e;
	dsu(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, m;
	cin >> n >> m;
	vector<int> nxt(n+1, -1);
	for(int t, i = 0; i < m; i++) {
		for(int nt, j = 0; j < n; j++) {
			cin >> nt;
			if(j) {
				if(nxt[t] != -2) {
					if(nxt[t] == -1) nxt[t] = nt;
					if(nxt[t] != nt) nxt[t] = -2;
				}
			}
			t = nt;
		}
		nxt[t] = -2;
	}
	dsu d(n+1);
	for(int i = 1; i <= n; i++) if(nxt[i] >= 0)
		d.join(i, nxt[i]);
	ll ans = 0;
	for(int i = 1; i <= n; i++) if(d.find(i) == i) {
		ans += d.e[i]*1ll*(d.e[i]-1)/2;
	}
	cout << ans << '\n';
}
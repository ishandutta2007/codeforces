// Problem: D. Social Network
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/D
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
	int n, d;
	cin >> n >> d;
	dsu D(n+1);
	for(int extr = 0, a, b, t, i = 0; i < d; i++) {
		cin >> a >> b;
		extr += !D.join(a, b);
		vector<int> rt;
		for(int i = 1; i <= n; i++) if(D.find(i) == i)
			rt.push_back(D.size(i));
		sort(all(rt), greater<>());
		int ans = 0;
		for(int i = 0; i <= min(extr, int(rt.size())-1); i++)
			ans += rt[i];
		cout << ans-1 << '\n';
	}
}
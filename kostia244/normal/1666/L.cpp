// Problem: L. Labyrinth
// Contest: Codeforces - 2021-2022 ICPC, NERC, Northern Eurasia Onsite (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1666/problem/L
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
const int N = 2e5 + 16;
int n, m, s, p[N], c[N];
vector<int> g[N];
void report(int t, int x) {
	vector<int> A{t}, B{t, x};
	do {
		t = p[t];
		A.push_back(t);
	} while(t != s);
	if(x != s) do {
		x = p[x];
		B.push_back(x);
	} while(x != s);
	reverse(all(A));
	reverse(all(B));
	cout << "Possible\n";
	cout << A.size() << '\n';
	for(auto i : A) cout << i << ' '; cout << '\n';
	cout << B.size() << '\n';
	for(auto i : B) cout << i << ' '; cout << '\n';
	exit(0);
}
int cur = 1;
void dfs(int v) {
	c[v] = cur;
	for(auto &i : g[v]) {
		if(c[i] && c[i] != cur) {
			report(i, v);
		}
		if(c[i] == 0) {
			p[i] = v;
			dfs(i);
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> s;
	for(int u,v, i = 0; i < m; i++) {
		cin >> u >> v;
		if(v == s) continue;
		g[u].push_back(v);
	}
	for(auto i : g[s]) {
		if(c[i]) {
			report(i, s);
		}
		p[i] = s;
		++cur;
		dfs(i);
	}
	cout << "Impossible\n";
}
// Problem: E. Fib-tree
// Contest: Codeforces - Codeforces Global Round 13
// URL: https://codeforces.com/contest/1491/problem/E
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
const int maxn = 1<<18;
int n;
#define prev gay
vector<int> g[maxn];
int fib[maxn], prev[maxn];
int sz[maxn], par[maxn];
vector<int> comp;
void sizes(int v) {
	sz[v] = 1;
	comp.push_back(v);
	for(auto i : g[v]) if(i != par[v]) {
		par[i] = v;
		sizes(i);
		//cout << v << " + " << i << " " << sz[i] << endl;
		sz[v] += sz[i];
	}
	//cout << v+1 << " -> " << sz[v] << endl;
}
int solve(int v) {
	par[v] = -1;
	comp.clear();
	//cout << " st " << v << endl;
	sizes(v);
	if(sz[v] == 1) return 1;
	if(!fib[sz[v]]) return 0;
	int x = -1, y = -1;
	for(auto i : comp)
		if(sz[i] == prev[sz[v]] || sz[i] == sz[v]-prev[sz[v]]) {
			x = par[i], y = i;
			break;
		}
	//cout << sz[v] << " : " << x << " " << y << " " << sz[9] << " " << prev[8] << endl;
	if(x == -1) return 0;
	g[x].erase(find(all(g[x]), y));
	swap(x, y);
	g[x].erase(find(all(g[x]), y));
	return solve(x) && solve(y);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	fib[1] = 1;
	int u = 0, v = 1;
	while(v+u < maxn) {
		tie(u, v) = pair<int, int>{v, u+v};
		fib[v] = 1;
		prev[v] = u;
	}
	cin >> n;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		f--,t--;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	report(solve(0));
}
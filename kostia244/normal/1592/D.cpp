// Problem: D. Hemose in ICPC ?
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.com/contest/1592/problem/D
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
const int N = 1e3 + 33;
int n, chs = 0, P[N];
vector<int> g[N], alive, col, tk;
void dfs(int v, int p) {
	if(!chs) return;
	chs -= alive[v];
	tk.push_back(v);
	col[v] = 1;
	for(auto &i : g[v]) if(i != p) {
		P[i] = v;
		dfs(i, v);
	}
}
int ask(vector<int> &a) {
	cout << "? " << a.size() << " ";
	for(auto &i : a) cout << 1+i << " "; cout << endl;
	cin >> a[0];
	return a[0];
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;f--,t--;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	int cnt = 1;
	alive.assign(n, 1);
	alive[0] = 0;
	tk.resize(n);iota(all(tk), 0);
	int mx = ask(tk);
	cnt = n-1;
	while(cnt > 1) {
		chs = cnt/2;
		tk.clear();
		col.assign(n, 0);
		dfs(0, n);
		int t = ask(tk) != mx;
		cnt = 0;
		for(int i = 0; i < n; i++) {
			alive[i] &= col[i]^t;
			cnt += alive[i];
		}
	}
	int v = 0;
	while(!alive[v]) v++;
	cout << "! " << v+1 << " " << 1+P[v] << endl;
}
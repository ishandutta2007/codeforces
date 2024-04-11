// Problem: F. New Year Shopping
// Contest: Codeforces - Good Bye 2014
// URL: https://codeforces.com/contest/500/problem/F
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
const int maxn = 20200;
int n, p, q, ans[maxn];
vector<array<int, 2>> tree[4*maxn];
vector<array<int, 2>> queries[maxn];
void update(int v, int l, int r, int ql, int qr, array<int, 2> item) {
	if(qr < l || r < ql) return;
	if(ql <= l && r <= qr) {
		tree[v].push_back(item);
		return;
	}
	int mid = (l+r)/2;
	update(2*v, l, mid, ql, qr, item);
	update(2*v+1, mid+1, r, ql, qr, item);
}
const int A = 4040;
array<int, A> def, cur;
void dfs(int v, int l, int r) {
	for(auto [c, h] : tree[v]) {
		for(int i = A-1-c; i >= 0; i--)
			cur[i+c] = max(cur[i+c], cur[i]+h);
	}
	if(l == r) {
		for(auto [w, id] : queries[l]) {
			ans[id] = cur[w];
		}
		return;
	}
	int mid = (l+r)/2;
	auto backup = cur;
	dfs(2*v, l, mid);
	cur = backup;
	dfs(2*v+1, mid+1, r);
	cur = backup;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	def.fill(0);
	cur = def;
	cin >> n >> p;
	for(int c, h, t, i = 0; i < n; i++) {
		cin >> c >> h >> t;
		update(1, 1, maxn-1, t, t+p-1, {c, h});
	}
	cin >> q;
	for(int a, b, i = 0; i < q; i++) {
		cin >> a >> b;
		queries[a].push_back({b, i});
	}
	dfs(1, 1, maxn-1);
	for(int i = 0; i < q; i++) cout << ans[i] << '\n';
}
// Problem: H.  II
// Contest: Codeforces - Manthan, Codefest 16
// URL: https://codeforces.com/contest/633/problem/H
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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
const int N = 30300;
int res[N], t1[N], t2[N], fib[N], rsz = 0, tsz = 0;
void add_b() {
	int i = 0, j = 0, pos = 0;
	while(i < rsz && j < tsz) {
		t2[pos++] = min(res[i], t1[j]);
		(res[i] <= t1[j] ? i : j)++;
	}
	while(i < rsz) t2[pos++] = res[i++];
	while(j < tsz) t2[pos++] = t1[j++];
	rsz += tsz;
	for(int i = 0; i < rsz; i++)
		res[i] = t2[i];
}
void clean() {
	int pos = 1;
	t2[0] = res[0];
	for(int i = 1; i < rsz; i++)
		if(res[i] != t2[pos-1])
			t2[pos++] = res[i];
	rsz = pos;
	for(int i = 0; i < rsz; i++)
		res[i] = t2[i];
}
struct SortTree {
	int n;
	vector<vector<array<int, 2>>> tree;
	SortTree(vector<int> a = {}) {
		n = a.size();
		tree.resize(4*n);
		vector<array<int, 2>> b;
		for(int i = 0; i < n; i++)
			b.push_back({a[i], i});
		sort(all(b));
		for(auto [val, idx] : b)
			push(1, 0, n-1, idx, val);
	}
	void push(int v, int l, int r, int i, int x) {
		if(i < l || r < i) return;
		tree[v].push_back({i, x});
		if(l != r) {
			int m = (l+r)/2;
			push(2*v, l, m, i, x);
			push(2*v+1, m+1, r, i, x);
		}
	}
	void get(int v, int l, int r, int ql, int qr) {
		if(r < ql || qr < l) return;
		if(2*(qr-ql+1) >= (r-l+1)) {
			tsz = 0;
			for(auto [idx, val] : tree[v]) if(ql <= idx && idx <= qr)
				t1[tsz++] = val;
			add_b();
			return;
		}
		int m = (l+r)/2;
		get(2*v, l, m, ql, qr);
		get(2*v+1, m+1, r, ql, qr);
	}
	void get(int l, int r) {
		rsz = tsz = 0;
		get(1, 0, n-1, l, r);
		clean();
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, m, q,l,r;
	cin >> n >> m;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	SortTree st(a);
	cin >> q;
	fib[0] = fib[1] = 1;
	for(int i = 2; i <= n; i++)
		fib[i] = (fib[i-1]+fib[i-2])%m;
	while(q--) {
		cin >> l >> r;
		st.get(l-1, r-1);
		__int128 ans = 0;
		for(int i = 0; i < rsz; i++)
			ans += res[i]*1ll*fib[i];
		cout << int(ans%m) << '\n';
	}
}
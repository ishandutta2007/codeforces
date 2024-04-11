// Problem: E. Equilibrium
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/E
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
#define int long long
const int N = 1<<17, inf = 1e9 + 12369;
struct node {
	int min_bal, bal, pref, suf, sub, sum;
	bool empt;
	node(int x = -inf) {
		min_bal = bal = x;
		sum = -x;
		pref = suf = sub = max(0ll, -x);
		empt = x==-inf;
	}
	friend node operator+(const node &a, const node &b) {
		if(a.empt) return b;
		if(b.empt) return a;
		node res;
		res.min_bal = min(a.min_bal, a.bal+b.min_bal);
		res.bal = a.bal + b.bal;
		res.sum = a.sum+b.sum;
		res.pref = max(a.sum+b.pref, a.pref);
		res.suf = max(a.suf+b.sum, b.suf);
		res.sub = max({a.sub, b.sub, a.suf+b.pref});
		res.empt = 0;
		return res;
	}
};
int n, q, a[N];
node tree[2*N];
node qry(int l, int r) {
	node L, R;
	for(l += N, r += N; l < r; l>>=1,r>>=1) {
		if(l&1) L = L + tree[l++];
		if(r&1) R = tree[--r] + R;
	}
	return L+R;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int t, i = 1; i <= n; i++) {
		cin >> t;
		a[i] = t-a[i];
		tree[N+i] = node(a[i]);
	}
	for(int i = N; i--;) {
		tree[i] = tree[2*i] + tree[2*i+1];
	
	}
	// for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
	for(int l, r; q--;) {
		cin >> l >> r;
		auto info = qry(l, r+1);
		if(info.min_bal < 0 || info.sum != 0) cout << "-1\n";
		else {
			cout << info.sub << '\n';
		}
	}
}
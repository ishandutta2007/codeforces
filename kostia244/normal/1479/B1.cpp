// Problem: B1. Painting the Array I
// Contest: Codeforces - Codeforces Round #700 (Div. 1)
// URL: https://codeforces.com/contest/1479/problem/B1
// Memory Limit: 512 MB
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

struct segment_tree
{
	int n;
	vector<ll> a;

	segment_tree(int n) : n(n), a(2 * n) {}

	void update(int p, ll v)
	{
		for (a[p += n] = v-lazy; p /= 2;)
			a[p] = max(a[2 * p], a[2 * p + 1]);
	}

	ll query(int l, int r)
	{
		ll g = -(1<<30);

		for (l += n, r += n; l < r; l /= 2, r /= 2)
		{
			if (l & 1) g = max(g, a[l++]);
			if (r & 1) g = max(g, a[--r]);
		}

		return g + lazy;
	}
	ll lazy = 0;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	cin >> n;
	segment_tree st(n+4);
	for(int i = 0; i < n+4; i++) st.update(i, -(1<<30));
	int lst = 0;
	st.update(0, 0);
	for(int t, i = n; i--;) {
		cin >> t;
		ll f = st.query(t, t+1);
		f = max(f, st.query(0, t)+1);
		f = max(f, st.query(t+1, n+4)+1);
		if(lst != t) {
			st.lazy++;
		}
		f = max(f, st.query(lst, lst+1));
		st.update(lst, f);
		lst = t;
		//for(int i = 0; i <= n; i++) cout << st.query(i, i+1) << " "; cout << endl;
	}
	cout << st.query(0, n+4) << endl;
}
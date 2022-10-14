// Problem: G.  
// Contest: Codeforces - Codeforces Round #760 (Div. 3)
// URL: https://codeforces.com/contest/1618/problem/G
// Memory Limit: 512 MB
// Time Limit: 4500 ms
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
	vector<int> e, l, r;
	vector<array<ll, 2>> s;
	vector<ll> pref;
	ll ans = 0;
	dsu(int n, vector<array<ll, 2>> S) : e(n, -1) {
		l = vector<int>(n);
		iota(all(l), 0);
		r = l;
		s = S;
		pref.resize(n);
		for(int i = 0; i < n; i++)
			pref[i] = s[i][0];
		for(int i = 1; i < n; i++)
			pref[i] += pref[i-1];
		for(auto [x, y] : S) if(y)
			ans += x;
		for(auto &[x, y] : s)
			x *= y;
	}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	ll get(int r, int l) {
		if(l<0) return pref[r];
		return pref[r]-pref[l];
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		l[a] = min(l[a], l[b]);
		r[a] = max(r[a], r[b]);
		ans -= s[a][0], ans -= s[b][0];
		s[a][1] += s[b][1];
		s[a][0] = get(r[a], r[a]-s[a][1]);
		ans += s[a][0];
		return true;
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, m, q;
	cin >> n >> m >> q;
	vector<ll> a(n), b(m);
	vector<array<ll, 2>> dif, al;
	for(auto &i : a) {
		cin >> i;
		al.push_back({i, 1});
	}
	for(auto &i : b) {
		cin >> i;
		al.push_back({i, 0});
	}
	sort(all(a)), sort(all(b)), sort(all(al));
	for(int i = 1; i < n+m; i++)
		dif.push_back({al[i][0]-al[i-1][0], i});
	sort(all(dif));
	n += m;
	map<ll, ll> ans;
	dsu d(n, al);
	ans[0] = d.ans;
	for(auto [D, p] : dif) {
		d.join(p-1, p);
		ans[D] = d.ans;
	}
	vector<array<ll,2>> uh;
	for(auto [x, y] : ans)
		uh.push_back({x, y});
	for(int k; q--;) {
		cin >> k;
		cout << (upper_bound(all(uh), array<ll,2>{k, 1ll<<60})-1)->at(1) << '\n';
	}
}
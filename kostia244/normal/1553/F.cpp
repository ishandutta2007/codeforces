// Problem: F.  
// Contest: Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1553/problem/F
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
struct fen {
	int n;
	vector<ll> f;
	fen(int N = 0) : n(N), f(n+3) {}
	void add(int p, ll d) {
		for(; p <= n; p += p&-p)
			f[p] += d;
	}
	ll get(int p) {
		ll res = 0;
		for(; p; p -= p&-p)
			res += f[p];
		return res;
	}
};
const int C = 3e5 + 15;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	fen f1(C), f0(C), sub(C);
	int n, t;
	ll ans = 0;
	cin >> n;
	for(int I = 0; I < n; I++) {
		cin >> t;
		ll lst0 = 0, lst1 = 0;
		for(int j = 0; j < C; j+=t) {
			ll cur0 = f0.get(min(C-1, j+t-1)), cur1 = f1.get(min(C-1, j+t-1));
			ans += (cur1-lst1) - j*(cur0-lst0);
			lst0 = cur0, lst1 = cur1;
		}
		ans += I*1ll*t - sub.get(t);
		f0.add(t, 1);
		f1.add(t, t);
		lst0 = 0;
		for(int j = t; j < C; j+=t) {
			sub.add(j, t);
		}
		cout << ans << " ";
	}
}
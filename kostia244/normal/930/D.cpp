#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, dl[maxn], dr[maxn], adl[maxn], adr[maxn];
multiset<int> f_l[2], f_r[2];
vector<int> S[maxn];
int mx(multiset<int> &a) {
	return a.empty() ? -(1<<24) : *a.rbegin();
}
int mn(multiset<int> &a) {
	return a.empty() ? (1<<24) : *a.begin();
}
int ceven(int l, int r) {
	if(l > r) return 0;
	return (r/2) - ((l-1)/2);
}
int codd(int l, int r) {
	if(l > r) return 0;
	return (r-l+1) - ceven(l, r);
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int x, y, i = 0; i < n; i++) {
		cin >> x >> y;
		x += 110000;
		y += 110000;
		int D = x+y;
		int A = (maxn/2) + x - y;
		f_r[D&1].insert(A);
		S[D].push_back(A);
	}
	ll ans = 0;
	for(int i = 0; i < maxn; i++) {
		for(auto &j : S[i]) {
			f_r[i&1].erase(f_r[i&1].find(j));
			f_l[i&1].insert(j);
		}
		int L = max(mn(f_r[(i&1)^1]), mn(f_l[(i&1)^1]));
		int R = min(mx(f_r[(i&1)^1]), mx(f_l[(i&1)^1]));
		if(i&1) ans += codd(L+1, R-1);
		else ans += ceven(L+1, R-1);
	}
	cout << ans << endl;
}
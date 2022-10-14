#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
void solve() {
	cin >> n;
	vector<int> a(2*n);
	for(auto &i : a) cin >> i;
	a.push_back(2*n + 1);
	int mx = -1, st = 0;
	vector<int> b;
	for(auto &i : a) {
		if(i > mx) {
			b.push_back(st);
			st = 1; mx = i;
		} else st++;
	}
	bitset<4040> f;
	f[0] = 1;
	for(auto &i : b) f = f|(f<<i);
	cout << (f[n]?"YES\n":"NO\n");
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}
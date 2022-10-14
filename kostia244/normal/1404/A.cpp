#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 3e5 + 33, maxk = 1<<11, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n, k;string s;
	cin >> n >> k >> s;
	for(int i = 0; i < k; i++) {
		int c0 = 0, c1 = 0;
		for(int j = i; j < n; j += k) {
			c0 += s[j] == '0';
			c1 += s[j] == '1';
		}
		if(c0&&c1) {cout << "NO\n"; return;}
		if(c0) s[i] = '0';
		if(c1) s[i] = '1';
	}
	int c0 = 0, c1 = 0;
	for(int i = 0; i < k; i++) {
		c0 += s[i] == '0';
		c1 += s[i] == '1';
	}
	if(max(c0, c1)>(k/2)) cout << "NO\n";
	else cout << "YES\n";
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
	
}
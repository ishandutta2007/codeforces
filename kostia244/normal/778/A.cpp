#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
string s, t;
int p[maxn], n, m;
bool can(int x) {
	string f;
	for(int i = 0; i < n; i++) {
		if(p[i] > x) f += s[i];
	}
	int i = 0, j = 0;
	while(i < f.size() && j < m) j += f[i++] == t[j];
	return j == m;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s >> t; n = s.size(); m = t.size();
	for(int t, i = 1; i <= n; i++) {
		cin >> t; --t;
		p[t] = i;
	}
	int ans = 0;
	for(int i = 1<<20; i>>=1;)
		if(can(ans+i)) ans += i;
	cout << ans << endl;
}
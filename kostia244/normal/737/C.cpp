#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, s, nod[maxn], v[maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> s;
	ll ans = 1ll<<60, f = 0, z = 0;
	for(int t, i = 1; i <= n; i++) {
		cin >> t;
		if(i == s && t) t = 0, f = 1;
		if(i != s && t == 0) z++;
		else nod[t]++;
	}
	for(int i = 0; i < n; i++) v[i] = nod[i]==0;
	for(int i = 1; i <= n; i++) nod[i] += nod[i-1];
	for(int i = 1; i <= n; i++) v[i] += v[i-1];
	for(int i = n>1; i < n; i++) {
		ll bad_dep = v[i];
		ll cur = n-nod[i];
		cur = max(cur, bad_dep);
		ans = min(ans, cur);
		//cout << i << " " << cur << " " << v[i] << " " << nod[i] << endl;
	}
	if(ans == 1ll<<60) ans = -1;
	else ans += f;
	cout << ans << endl;
}
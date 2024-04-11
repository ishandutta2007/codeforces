#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse4,popcnt,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<17, mod = 1e9 + 7;
void solve() {
	ll m, d, w;
	cin >> m >> d >> w;
	m = min(m, d);
	--d;
	ll b = w/__gcd(w, d);
	ll pl = (m/b)*1ll*(m/b - 1)/2;
	ll ph = ((m+b-1)/b)*1ll*((m+b-1)/b - 1)/2;
	pl *= b - (m%b);
	ph *= m%b;
	cout << pl+ph << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}
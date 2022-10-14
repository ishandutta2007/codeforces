#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<17, mod = 998244353 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n;
	cin >> n;
	vi a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	ll base = 0;
	for(int i = 0; i < n; i++) {
		base += max(0ll, a[i] - b[(n+i-1)%n]);
	}
	ll ans = 1ll<<60;
	for(int i = 0; i < n; i++) ans = min(ans, base - max(0ll, a[i] - b[(n+i-1)%n]) + a[i]);
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
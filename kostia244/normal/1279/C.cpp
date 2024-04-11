//#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,avx,sse,sse2,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using ld = long double;
const int maxn = 2e6 + 55, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n, m;
	vi a, b;
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for(int t, i = 0; i < n; i++) {
		cin >> t, t--;
		a[t] = i;
	}
	for(auto &i : b) cin >> i, i--;
	ll ans = 0, mx = -1, cur = 0;
	for(auto i : b) {
		if(a[i]<mx) {
			ans++;
		} else {
			mx = a[i];
			ans += (a[i]-cur)*2ll+1;//, cout << ans << "\n";
		}
		cur ++;
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while(t--) solve();
}
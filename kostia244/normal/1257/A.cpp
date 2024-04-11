#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
void solve() {
	ll n, x, a, b;
	cin >> n >> x >> a >> b;
	ll ans = min(n-1, abs(a-b)+x);
	cout << ans << "\n";
}
int main() {
	 ios::sync_with_stdio(0);
	 cin.tie(0);
	 cout.tie(0);
	 ll t;
	 cin >> t;
	 while(t--) solve();
	 return 0;
}
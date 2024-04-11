//#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using ld = long double;
const int maxn = 505, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n, p, k;
	vi a;
	cin >> n >> p >> k;
	a.resize(n);
	for(auto &i : a) cin >> i;
	sort(all(a));
	vi sm(k, 0), pr(n, 0);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		pr[i] = a[i] + (i?pr[i-1]:0);
		sm[i%k] += a[i];
		ll t = sm[i%k];
//		cout << i << " " << t << " " << a[i] << "\n";
		if((i+1)%k) {
			t -= a[i%k];
			t += pr[i%k];
		}
//		cout << i << " " << t << "\n";
		if(t<=p) ans = i+1;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}
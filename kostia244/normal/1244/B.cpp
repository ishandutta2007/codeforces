#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:26777216")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9 + 7;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	ll n;
	string s;
	cin >> n >> s;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll t = max((ll)i + 1, n - i);
		if (s[i] == '1') {
			t += max((ll) i + 1, n - i);
		}
		ans = max(ans, t);
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}
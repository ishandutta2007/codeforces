#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

ll f(ll n) {
	ll ans = 0;
	for (int k = 2;; ++k) {
		ll add = n / k / k / k;
		if (add == 0) return ans;
		ans += add;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll m;
	cin >> m;
	ll l = 1, r = 1e18;
	while (l < r - 1) {
		ll mid = (l + r) / 2;
		if (f(mid) >= m) r = mid;
		else l = mid;
	}
	if (f(r) == m) cout << r << '\n';
	else cout << "-1\n";
	return 0;
}
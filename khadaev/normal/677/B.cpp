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

#define int ll

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, h, k;
	cin >> n >> h >> k;
	vector<int> a(n);
	forn(i, 0, n) cin >> a[i];
	int i = 0, s = 0, ans = 0;
	while (i < n) {
		while (i < n && s + a[i] <= h) {
			s += a[i];
			++i;
		}
		++ans;
		if (s < k) s = 0;
		else s -= k;
		if (i < n) {
			int r = s + a[i] - h;
			if (r <= 0) continue;
			int t = (r + k - 1) / k;
			ans += t;
			s -= t * k;
			if (s < 0) s = 0;
		} else {
			ans += (s + k - 1) / k;
		}
	}
	cout << ans << '\n';
	return 0;
}
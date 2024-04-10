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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a;
	cin >> n >> a;
	--a;
	vector<int> t(n);
	forn(i, 0, n) cin >> t[i];
	int ans = 0;
	forn(i, 0, n) {
		int cnt1 = 0, cnt2 = 0;
		if (a - i >= 0) {
			++cnt1;
			if (t[a - i]) ++cnt2;
		}
		if (a + i < n && i) {
			++cnt1;
			if (t[a + i]) ++cnt2;
		}
		if (cnt1 == cnt2) ans += cnt1;
	}
	cout << ans << '\n';
	return 0;
}
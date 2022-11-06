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
	ll n, m;
	cin >> n >> m;
	ll n1 = 1, m1 = 1, ln = 0, lm = 0;
	while (n1 < n) {
		n1 *= 7;
		++ln;
	}
	if (ln == 0) ++ln;
	while (m1 < m) {
		m1 *= 7;
		++lm;
	}
	if (lm == 0) ++lm;
	if (lm + ln > 7) {
		cout << "0\n";
		return 0;
	}
	vector<int> digits(7);
	int ans = 0;
	forn(i, 0, 7) digits[i] = i;
	do {
		int n2 = 0;
		forn(i, 0, ln) {
			n2 *= 7;
			n2 += digits[i];
		}
		int m2 = 0;
		forn(i, ln, lm + ln) {
			m2 *= 7;
			m2 += digits[i];
		}
		if (n2 < n && m2 < m) ++ans;
	} while (next_permutation(all(digits)));
	fore(i, 1, 7 - ln - lm) ans /= i;
	cout << ans << '\n';
	return 0;
}
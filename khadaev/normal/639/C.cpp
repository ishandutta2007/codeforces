#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n, k;
	cin >> n >> k;
	int sz = n + 100;
	vector<ll> a(sz, 0);
	fore(i, 0, n) cin >> a[i];
	vector<ll> b = a;
	forn(i, 0, sz - 1) {
		b[i + 1] += (b[i] - abs(b[i] % 2)) / 2;
		b[i] = abs(b[i] % 2);
	}
	//forn(i, 0, n+10) cout << b[i] << ' ';
	//cout << '\n';
	if (b[sz - 1]) {
		forn(i, 0, sz) a[i] *= -1;
		b = a;
		forn(i, 0, sz - 1) {
			b[i + 1] += (b[i] - abs(b[i] % 2)) / 2;
			b[i] = abs(b[i] % 2);
		}
		//forn(i, 0, n+10) cout << b[i] << ' ';
		//cout << '\n';
		if (b[sz - 1]) {
			return 1;
		}
	}
	int mindeg = INF, maxdeg = -1;
	forn(i, 0, sz) if (b[i]) {
		mindeg = min(mindeg, i);
		maxdeg = max(maxdeg, i);
	}

	if (maxdeg - mindeg > 40) {
		cout << "0\n";
		return 0;
	}
	ll num = 0;
	for(int i = maxdeg; i >= mindeg; --i) {
		num *= 2;
		num += b[i];
	}
	//forn(i, 0, n + 10) cout << b[i] << ' ';
	//cout << '\n';
	int ans = 0;
	forn(i, 0, 32) {
		if (num > 2 * k) break;
		int dg = mindeg - i;
		if (dg < 0) break;
		ll val = a[dg] - num;
		num *= 2;
		if (dg > n) continue;
		if (dg == n && val == 0) continue;
		if (abs(val) <= k) {
			++ans;
			//cout << dg << ' ' << val << '\n';
		}
		//cout << dg << ' ' << num << ' ' << val << '\n';

	}
	cout << ans << '\n';
	return 0;
}
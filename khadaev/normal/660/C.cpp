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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	forn(i, 0, n) cin >> a[i];
	int l = 0, r = n + 1;
	while (l < r - 1) {
		int m = (l + r) / 2;
		//cout << m << '\n';
		int s = 0;
		forn(i, 0, m) s += a[i];
		bool ok = false;
		forn(i, m, n) {
			if (m - s <= k) ok = true;
			s -= a[i - m];
			s += a[i];
		}
		if (m - s <= k) ok = true;
		if (ok) l = m;
		else r = m;
	}
	r = l;
	cout << r << '\n';
	int s = 0;
	forn(i, 0, r) s += a[i];
	forn(i, r, n) {	
		if (r - s <= k) {
			forn(j, 0, n) {
				if (j < i && j >= i - r) cout << "1 ";
				else cout << a[j] << ' ';
			}
			return 0;
		}
		s -= a[i - r];
		s += a[i];
	}
	if (r - s <= k) {
		forn(j, 0, n) {
			if (j < n && j >= n - r) cout << "1 ";
			else cout << a[j] << ' ';
		}
		return 0;
	}

	return 1;
}
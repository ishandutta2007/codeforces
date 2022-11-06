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
	vector<int> x = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2}, y = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};
	set<pair<int, int>> s;
	forn(i, 0, 10) s.emplace(x[i], y[i]);
	int n;
	cin >> n;
	vector<int> a(n);
	forn(i, 0, n) {
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	int ok = 0;
	forn(i, 0, 10) {
		bool good = 1;
		int xx = x[i], yy = y[i];
		forn(j, 1, n) {
			xx += x[a[j]] - x[a[j - 1]];
			yy += y[a[j]] - y[a[j - 1]];
			if (s.count({xx, yy}) == 0) {
				good = 0;
				break;
			}
		}
		if (good) ++ok;
	}
	if (ok == 1) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
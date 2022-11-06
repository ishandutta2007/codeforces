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
	int n, d, h;
	cin >> n >> d >> h;
	if (h * 2 < d) {
		cout << "-1\n";
		return 0;
	}
	if (d == 1) {
		if (n == 2) {
			cout << "1 2\n";
			return 0;
		} else {
			cout << "-1\n";
			return 0;
		}
	}
	if (h == d) {
		for (int i = 1; i <= h; ++i) cout << i << ' ' << i + 1 << '\n';
		for (int i = h + 2; i <= n; ++i) cout << h << ' ' << i << '\n';
		return 0;
	}
	for(int i = 1; i <= h; ++i) cout << i << ' ' << i + 1 << '\n';
	if (d > h) cout << "1 " << h + 2 << "\n";
	for (int i = h + 2; i <= d; ++i) cout << i << ' ' << i + 1 << '\n';
	for (int i = d + 2; i <= n; ++i) cout << "1 " << i << '\n';
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

char c[100][100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, 0, n)
		forn(j, 0, n)
			cin >> c[i][j];
	ll ans = 0;
	forn(i, 0, n) {
		int cnt = 0;
		forn(j, 0, n) if(c[i][j] == 'C') ++cnt;
		ans += cnt * (cnt - 1) / 2;
	}
	forn(i, 0, n) {
		int cnt = 0;
		forn(j, 0, n) if(c[j][i] == 'C') ++cnt;
		ans += cnt * (cnt - 1) / 2;
	}
	cout << ans << '\n';

	return 0;
}
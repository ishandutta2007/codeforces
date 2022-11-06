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

int m[367], f[367];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, 0, n) {
		char c;
		int b, e;
		cin >> c >> b >> e;
		if (c == 'M') fore(i, b, e) ++m[i];
		else fore(i, b, e) ++f[i];
	}
	int ans = 0;
	fore(i, 1, 366)
		ans = max(ans, min(m[i], f[i]));
	cout << 2 * ans << '\n';
	return 0;
}
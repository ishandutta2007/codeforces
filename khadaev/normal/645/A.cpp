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

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	char a[4], b[4];
	cin >> a[0] >> a[1] >> a[3] >> a[2];
	cin >> b[0] >> b[1] >> b[3] >> b[2];
	vector<char> ax, bx;
	forn(i, 0, 4) if (a[i] != 'X') ax.push_back(a[i]);
	forn(i, 0, 4) if (b[i] != 'X') bx.push_back(b[i]);
	int ai, bi;
	forn(i, 0, 3) if (ax[i] == 'A') ai = i;
	forn(i, 0, 3) if (bx[i] == 'A') bi = i;
	forn(i, 0, 3)
		if (ax[(i + ai) % 3] != bx[(i + bi) % 3]) {
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	return 0;
}
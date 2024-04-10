#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#undef M_PI
const ld M_PI = 3.1415926535897932384626433;
const ld eps = 1e-8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1\n";
		return 0;
	}
	vector<int> m(n, 0);
	forn(i, 0, n)
		forn(j, 0, n) {
			int a;
			cin >> a;
			m[i] = max(a, m[i]);
		}
	forn(i, 0, n)
		if (m[i] == n - 1) {
			m[i] = n;
			break;
		}
	for (int i : m) cout << i << ' ';
	return 0;
}
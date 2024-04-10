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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> cr(n, 0), cc(m, 0), tr(n, k + 1), tc(m, k + 1);
	while(k--) {
		int t, p, a;
		cin >> t >> p >> a;
		--p;
		if (t == 1) {
			cr[p] = a;
			tr[p] = k;
		} else {
			cc[p] = a;
			tc[p] = k;
		}
	}
	forn(i, 0, n) {
		forn(j, 0, m) {
			cout << (tr[i] < tc[j] ? cr[i] : cc[j]) << ' ';
		}
		cout << '\n';
	}
	return 0;
}
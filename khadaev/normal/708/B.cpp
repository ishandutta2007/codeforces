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

ll a[2][2];
ll c[2];

bool test() {
	return (c[0] * c[1] == a[0][1] + a[1][0]);
}

void solve() {
	int n = c[0] + c[1];
	while (n--) {
		if (a[0][1] >= c[1]) {
			printf("0");
			a[0][1] -= c[1];
			--c[0];
		} else {
			printf("1");
			a[1][0] -= c[0];
			--c[1];
		}
	}
}

int main() {
	forn(i, 0, 2) forn(j, 0, 2) scanf("%lld", &a[i][j]);
	bool zero = true;
	forn(i, 0, 2) forn(j, 0, 2) if (a[i][j]) zero = false;
	if (zero) {
		printf("0");
		return 0;
	}
	vector<int> x[2];
	forn(i, 0, 2) {
		if (a[i][i] == 0) {
			x[i].eb(0);
			x[i].eb(1);
		} else {
			ll t;
			for (t = 0; t * (t - 1) / 2 < a[i][i]; ++t);
			if (t * (t - 1) / 2 == a[i][i]) x[i].eb(t);
		}
	}
	for (int c0 : x[0])
		for (int c1 : x[1]) {
			c[0] = c0, c[1] = c1;
			if (test()) {
				solve();
				return 0;
			}
		}
	printf("Impossible\n");
	return 0;
}
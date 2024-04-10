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
	ll p[2];
	p[0] = 0, p[1] = 1;
	int n, q;
	scanf("%d %d", &n, &q);
	forn(ii, 0, q) {
		int t;
		scanf("%d", &t);
		if (t == 2) {
			forn(i, 0, 2) {
				if (p[i] % 2 == 0) {
					++p[i];
				} else --p[i];
			}
		} else {
			int d;
			scanf("%d", &d);
			forn(i, 0, 2) p[i] += d;
		}
	}
	vector<int> pos(n), inv(n);
	forn(i, 0, n) pos[i] = ((i + p[i % 2] - i % 2) % n + n) % n;
	forn(i, 0, n) inv[pos[i]] = i;
	forn(i, 0, n) printf("%d ", inv[i] + 1);
	return 0;
}
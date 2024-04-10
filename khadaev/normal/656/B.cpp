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
	int d = 720720;
	int n;
	cin >> n;
	vector<int> m(n), r(n);
	forn(i, 0, n) cin >> m[i];
	forn(i, 0, n) cin >> r[i];
	int ans = 0;
	forn(i, 0, d) {
		bool ok = false;
		forn(j, 0, n)
			if (i % m[j] == r[j])
				ok = true;
		if (ok) ++ans;
	}
	cout << fixed << setprecision(10) << (ld)ans / d;
	return 0;
}
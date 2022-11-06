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
	int n, m;
	cin >> n >> m;
	vector<int> ans(4 * n, -1);
	forn(i, 0, n) {
		ans[4 * i + 1] = 2 * i + 1;
		ans[4 * i] = 2 * i + 1 + 2 * n;
		ans[4 * i + 2] = 2 * i + 1 + 2 * n + 1;
		ans[4 * i + 3] = 2 * i + 2;
	}
	forn(i, 0, 4 * n)
		if (ans[i] <= m)
			cout << ans[i] << ' ';
	return 0;
}
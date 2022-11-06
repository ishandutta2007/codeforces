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
	int n;
	cin >> n;
	vector<int> a(n);
	forn(i, 0, n) cin >> a[i];
	vector<int> ans = {a[0]};
	int p1 = 999999937, p2 = 999999929, p3 = 999999893;
	forn(i, 0, n - 1) {
		if (__gcd(a[i], a[i + 1]) > 1) {
			if (a[i] != p1 && a[i + 1] != p1) ans.eb(p1);
			else if (a[i] != p2 && a[i + 1] != p2) ans.eb(p2);
			else ans.eb(p3);
		}
		ans.eb(a[i + 1]);
	}
	cout << ans.size() - n << '\n';
	for(int i : ans) cout << i << ' ';
	return 0;
}
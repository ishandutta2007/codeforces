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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll> a(5), b(5);
	forn(i, 0, 5) a[i] += n / 5;
	fore(i, 1, n % 5) a[i]++;
	forn(i, 0, 5) b[i] += m / 5;
	fore(i, 1, m % 5) b[i]++;
	ll ans = a[0] * b[0];
	forn(i, 1, 5) ans += a[i] * b[5 - i];
	cout << ans << '\n';
	return 0;
}
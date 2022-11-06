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

void fail() {
	cout << "-1\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (n == 4) fail();
	if (k < n + 1) fail();
	vector<int> rest;
	fore(i, 1, n) if (i != a && i != b && i != c && i != d) rest.eb(i);
	cout << a << ' ' << c << ' ';
	for (int i : rest) cout << i << ' ';
	cout << d << ' ' << b << '\n';
	cout << c << ' ' << a << ' ';
	for (int i : rest) cout << i << ' ';
	cout << b << ' ' << d << '\n';
	return 0;
}
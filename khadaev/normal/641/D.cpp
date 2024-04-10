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
	vector<ld> a(n), b(n), s(n), t(n);
	forn(i, 0, n) cin >> a[i];
	forn(i, 0, n) cin >> b[i];
	ld sum = 0;
	forn(i, 0, n) {
		sum += a[i];
		s[i] = sum;
	}
	sum = 0;
	for(int i = n - 1; i >= 0; --i) {
		sum += b[i];
		t[i] = sum;
	}
	/*forn(i, 0, n) cout << s[i] << ' ';
	cout << '\n';
	forn(i, 0, n) cout << t[i] << ' ';*/
	vector<ld> anss1(n), anss2(n);
	forn(i, 0, n - 1) {
		ld pr = s[i], copr = t[i + 1];
		ld s = pr - copr + 1;
		ld d = s * s - 4 * pr;
		anss1[i] = (s + sqrt(d)) / 2;
		anss2[i] = (s - sqrt(d)) / 2;
	}
	anss1[n - 1] = 1;
	anss2[n - 1] = 1;
	cout << anss1[0] << ' ';
	forn(i, 1, n) cout << anss1[i] - anss1[i - 1] << ' ';
	cout << '\n' << anss2[0] << ' ';
	forn(i, 1, n) cout << anss2[i] - anss2[i - 1] << ' ';
	cout << '\n';
	return 0;
}
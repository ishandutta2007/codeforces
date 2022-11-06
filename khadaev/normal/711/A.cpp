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
	int n;
	cin >> n;
	vector<string> a(n);
	forn(i, 0, n) cin >> a[i];
	bool ok = false;
	for(string &s : a) {
		if (s[0] == 'O' && s[1] == 'O') {
			s[0] = '+';
			s[1] = '+';
			ok = true;
			break;
		}
		if (s[3] == 'O' && s[4] == 'O') {
			s[3] = '+';
			s[4] = '+';
			ok = true;
			break;
		}
	}
	if (ok) {
		cout << "YES\n";
		forn(i, 0, n) cout << a[i] << '\n';
	} else cout << "NO\n";
	return 0;
}
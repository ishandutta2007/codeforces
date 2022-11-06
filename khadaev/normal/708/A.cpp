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
	string s;
	cin >> s;
	int n = s.length();
	int i = 0;
	while (i < n && s[i] == 'a') ++i;
	if (i == n) {
		forn(j, 0, n - 1) cout << 'a';
		cout << "z\n";
		return 0;
	}
	int j = i;
	while (j < n && s[j] != 'a') ++j;
	forn(k, 0, i) cout << s[k];
	forn(k, i, j) cout << (char)(s[k] - 1);
	forn(k, j, n) cout << s[k];
	cout << '\n';
	return 0;
}
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
	map<char, char> sym;
	sym['A'] = 'A';
	sym['b'] = 'd';
	sym['d'] = 'b';
	sym['H'] = 'H';
	sym['I'] = 'I';
	sym['M'] = 'M';
	sym['O'] = 'O';
	sym['o'] = 'o';
	sym['p'] = 'q';
	sym['q'] = 'p';
	sym['T'] = 'T';
	sym['U'] = 'U';
	sym['V'] = 'V';
	sym['v'] = 'v';
	sym['W'] = 'W';
	sym['w'] = 'w';
	sym['X'] = 'X';
	sym['x'] = 'x';
	sym['Y'] = 'Y';
	string s;
	cin >> s;
	int n = s.length();
	forn(i, 0, n) {
		if (sym.count(s[i]) == 0 || sym[s[i]] != s[n - 1 - i]) {
			cout << "NIE\n";
			return 0;
		}
	}
	cout << "TAK\n";
	return 0;
}
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

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int next[26];
	forn(i, 0, 26) next[i] = -1;
	cin >> n;
	bool start[26];
	forn(i, 0, 26) start[i] = false;
	forn(i, 0, n) {
		string s;
		cin >> s;
		int l = s.length();
		start[s[0] - 'a'] = true;
		forn(i, 0, l - 1) next[s[i] - 'a'] = s[i + 1] - 'a';
	}
	forn(i, 0, 26) if (next[i] >= 0) start[next[i]] = false;
	forn(i, 0, 26) if (start[i]) for (int j = i; j >= 0; j = next[j]) cout << char('a' + j);
	return 0;
}
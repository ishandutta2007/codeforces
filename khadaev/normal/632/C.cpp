#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

bool cmp(string s, string t) {
	return s + t < t + s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> s(n);
	forn(i, 0, n) cin >> s[i];
	sort(s.begin(), s.end(), cmp);
	forn(i, 0, n) {
		cout << s[i];		
	}
	return 0;
}
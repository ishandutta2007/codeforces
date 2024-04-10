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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, p;
	cin >> n >> p;
	vector<string> s(n);
	forn(i, 0, n) cin >> s[i];
	reverse(s.begin(),  s.end());
	ll cnt = 0, ans = 0;
	forn(i, 0, n) {
		ans += cnt * p;
		cnt *= 2;
		if (s[i] != "half") {
			++cnt;
			ans += p / 2;
		}
	}
	cout << ans << '\n';
	return 0;
}
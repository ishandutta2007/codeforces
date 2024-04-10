#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, m; cin >> n >> m;
	string s; cin >> s;
	int l = 0, r = 0, u = 0, d = 0;
	int x = 0, y = 0;
	int rx = 0, ry = 0;
	for (char c : s) {
		if (c == 'U') --y;
		if (c == 'D') ++y;
		if (c == 'L') --x;
		if (c == 'R') ++x;
		l = min(l, x);
		r = max(r, x);
		u = min(u, y);
		d = max(d, y);
		if (r - l + 1 > m || d - u + 1 > n) break;
		rx = -l;
		ry = -u;
	}
	cout << ry + 1 << ' ' << rx + 1 << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}
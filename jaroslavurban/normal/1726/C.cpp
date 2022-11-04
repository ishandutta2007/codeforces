#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int last = -1;
	int n; cin >> n;
	string s; cin >> s;
	s += '(';
	int res = 0;
	for (int i = 0; i < 2 * n + 1; ++i)
		if (s[i] == '(') {
			res += max(0, i - last - 2);
			last = i;
		}
	cout << res + 1 << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}
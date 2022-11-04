#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	string s;
	cin >> s;
	int n = s.size();
	for (int sm, i = n - 2; i >= 0; --i) {
		sm = s[i] + s[i + 1] - 2 * int('0');
		if (sm >= 10) {
			cout << s.substr(0, i) << sm << s.substr(i + 2, n - i - 2) << "\n";
			return;
		}
	}
	cout << s[0] + s[1] - 2 * int('0') << s.substr(2, n - 2) << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}
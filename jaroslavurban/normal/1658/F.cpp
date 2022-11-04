#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, m; cin >> n >> m;
	string s; cin >> s;
	int ones = count(s.begin(), s.end(), '1');
	if ((ll)ones * m % n) { cout << "-1\n"; return; }
	int need = (ll)ones * m / n, have = count(s.begin(), s.begin() + m, '1');
	for (int i = 0; i < n; ++i) {
		if (have == need) {
			if (i + m <= n) {
				cout << "1\n";
				cout << i + 1 << " " << i + m << "\n";
			} else {
				cout << "2\n";
				cout << 1 << " " << (i + m) % n << "\n";
				cout << i + 1 << " " << n << "\n";
			}
			return;
		}
		have += s[(i + m) % n] == '1';
		have -= s[i] == '1';
	}
	assert(0);
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}
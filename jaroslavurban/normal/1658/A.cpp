#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	string s; cin >> s;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			for (int j = i + 1; j < n; ++j) {
				if (s[j] == '0') {
					res += 3 - min(3, (j - i));
					break;
				}
			}
		}
	}
	cout << res  << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}
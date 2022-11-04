#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// https://github.com/kth-competitive-programming/kactl/blob/main/content/various/ConstantIntervals.h

void ProGamerMove() {
	int n, c;
	cin >> n >> c;
	vector<int> pref(c + 2);
	for (int v, i = 0; i < n; ++i) cin >> v, pref[v] = true;
	for (int i = 1; i < c + 2; ++i) pref[i] += pref[i - 1];
	for (int i = 1; i < c + 2; ++i) {
		if (pref[i] - pref[i - 1]) {
			for (int j = 1; j * i < c + 2; ++j) {
				if (!(pref[j] - pref[j - 1]) && (pref[min(c + 1, (j + 1) * i - 1)] - pref[j * i - 1])) {
					cout << "No\n";
					return;
				}
			}
		}
	}
	cout << "Yes\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}
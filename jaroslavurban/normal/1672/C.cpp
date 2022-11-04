#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	int mn = INT_MAX, mx = INT_MIN;
	for (int i = 0; i < n - 1; ++i) if (a[i] == a[i + 1]) {
		mn = min(mn, i);
		mx = max(mx, i);
	}
	cout << (mn == INT_MAX ? 0 : mx - mn  - (mx - mn >= 2)) << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}
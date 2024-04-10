#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<pair<int, int>> a(n);
	ll res = 0;
	for (auto& [x, y] : a) {
		cin >> x >> y;
		if (x < y) swap(x, y);
		res += 2 * ll(x + y);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 1; ++i) res -= 2 * a[i].first;
	cout << res << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}
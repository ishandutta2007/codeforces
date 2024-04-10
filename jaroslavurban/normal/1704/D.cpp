#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, m; cin >> n >> m;
	vector<ll> sums(n);
	for (int a, i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> a;
			sums[i] += a * ll(j + 1);
		}
	ll mx = *max_element(sums.begin(), sums.end());
	cout << find(sums.begin(), sums.end(), mx) - sums.begin() + 1 << ' ' << mx - *min_element(sums.begin(), sums.end()) << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}
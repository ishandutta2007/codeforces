#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	auto go = [&] (int i) {
		int mn = a[i], mx = a[i];
		for (; i < n && mx - mn <= 2 * x; ++i) mn = min(mn, a[i]), mx = max(mx, a[i]);
		return i - (mx - mn > 2 * x);
	};
	int res = 0;
	for (int i = 0; i < n; ++res) i = go(i);
	cout << res - 1 << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}
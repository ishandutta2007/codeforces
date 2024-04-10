#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	if (n == 1) { cout << "0\n"; return; }
	int res = INT_MIN;
	for (int i = 0; i < n; ++i) res = max(res, a[i] - a[(i + 1) % n]);
	res = max(res, *max_element(a.begin() + 1, a.end()) - a[0]);
	res = max(res, a[n - 1] - *min_element(a.begin(), a.end() - 1));
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
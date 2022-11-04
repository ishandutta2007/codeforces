#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	sort(a.begin(), a.end());
	if (a[0] == a[n - 1]) { cout << "0\n"; return; }
	int res = 0;
	for (int i = 0; i < n - 1; ++i) res = max(res, 2 * a[i + 1] - a[0] - a[i]);
	for (int i = 0; i < n - 1; ++i) res = max(res, a[i + 1] + a[n - 1] - 2 * a[i]);
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
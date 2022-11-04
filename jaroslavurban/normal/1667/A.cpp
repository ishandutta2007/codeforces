#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll tr(vector<int> a, int x) {
	ll res = 0;
	for (ll cur = 0, i = x - 1; i >= 0; --i) {
		res += cur / a[i] + 1;
		cur = a[i] * (cur / a[i] + 1);
	}
	for (ll cur = 0, i = x + 1; i < a.size(); ++i) {
		res += cur / a[i] + 1;
		cur = a[i] * (cur / a[i] + 1);
	}
	return res;
}

void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	ll res = LLONG_MAX;
	for (int i = 0; i < n; ++i) res = min(res, tr(a, i));
	cout << res << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	//cin >> tc;
	while (tc--) ProGamerMove();
}
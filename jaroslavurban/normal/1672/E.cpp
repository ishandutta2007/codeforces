#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int ask(int w) {
	cout << "? " << w << endl;
	int res; cin >> res; return res;
}

void ProGamerMove() {
	int n; cin >> n;
	int l = 2 * n - 1, r = 1e7;
	while (l < r) {
		int m = (l + r) / 2;
		if (ask(m) == 1) r = m;
		else l = m + 1;
	}
	ll s = l - (n - 1), res = LLONG_MAX;
	for (int i = 0; i < n; ++i) {
		ll w = (s + i + n - i - 1) / (n - i);
		ll h = ask(w);
		if (h) res = min(res, w * h);
	}
	cout << "! " << res << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}
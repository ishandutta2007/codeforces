#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n;
	cin >> n;
	vector<int> k(n), h(n);
	for (int& v : k) cin >> v;
	for (int& v : h) cin >> v;
	ll until = k.back(), y = h.back() - k.back();
	ll res = 0;
	for (int i = n - 2; i >= 0; --i) {
		if (h[i] - k[i] <= y) continue;
		if (-y >= k[i]) {
			res += (until + y) * (until + y + 1) / 2;
			until = k[i];
			y = h[i] - k[i];
		} else {
			y = h[i] - k[i];
		}
	}
	res += (until + y) * (until + y + 1) / 2;
	cout << res << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}
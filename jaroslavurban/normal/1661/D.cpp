#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


void ProGamerMove() {
	int k, n; cin >> n >> k;
	vector<ll> b(n), diffc(n);
	for (ll& v : b) cin >> v;
	ll sum = 0, c = 0, res = 0;
	for (int i = n - 1; i >= k; --i) {
		b[i] -= sum;
		ll need = max(0ll, b[i] + k - 1) / k;
		c += need;
		sum += need * k;
		diffc[i - k] += need;
		c -= diffc[i];
		sum -= c;
		res += need;
	}
	ll mx = 0;
	for (int i = k - 1; i >= 0; --i) {
		b[i] -= sum;
		mx = max(mx, max(0ll, b[i] + i) / (i + 1));
		c -= diffc[i];
		sum -= c;
	}
	cout << res + mx << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}
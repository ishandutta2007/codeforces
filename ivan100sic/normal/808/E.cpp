#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, resto_target, sol, zbir;
size_t x1, x2;

vector<ll> c[4];

ll zbir_tacno[300005];
ll zbir_jbg[300005];
size_t dpx1[300005], dpx2[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (ll i=1; i<=n; i++) {
		ll x, y;
		cin >> x >> y;
		c[x].push_back(y);
	}

	for (int i=1; i<=3; i++) {
		sort(c[i].begin(), c[i].end(), greater<ll>());
	}

	// dpx
	for (int i=1; i<=m; i++) {
		ll& zt = zbir_tacno[i];
		size_t& dpx1 = ::dpx1[i];
		size_t& dpx2 = ::dpx2[i];

		if (i >= 2 && ::dpx2[i-2] + 1 <= c[2].size()) {
			zt = zbir_tacno[i-2];
			dpx1 = ::dpx1[i-2];
			dpx2 = ::dpx2[i-2];

			zt += c[2][dpx2++];
		} else if (i >= 2 && ::dpx1[i-2] + 2 <= c[1].size()) {
			zt = zbir_tacno[i-2];
			dpx1 = ::dpx1[i-2];
			dpx2 = ::dpx2[i-2];

			zt += c[1][dpx1++];
			zt += c[1][dpx1++];
		} else if (::dpx1[i-1] + 1 <= c[1].size()) {
			zt = zbir_tacno[i-1];
			dpx1 = ::dpx1[i-1];
			dpx2 = ::dpx2[i-1];

			zt += c[1][dpx1++];
		} else {
			zt = 0;
			continue;
		}

		// cerr << i << ' ' << dpx1 << ' ' << dpx2 << ' ' << zt << '\n';

		// sada smes samo po dva da prebacujes
		// izbacujem dvojku ubacujem dva keca
		while (dpx2 >= 1 && dpx1 + 2 <= c[1].size()) {
			if (c[1][dpx1] + c[1][dpx1+1] > c[2][dpx2-1]) {
				zt += c[1][dpx1] + c[1][dpx1+1];
				zt -= c[2][dpx2-1];
				dpx1 += 2;
				dpx2 -= 1;
			} else {
				break;
			}
		}

		while (dpx1 >= 2 && dpx2 + 1 <= c[2].size()) {
			if (c[1][dpx1-1] + c[1][dpx1-2] < c[2][dpx2]) {
				zt -= c[1][dpx1-1] + c[1][dpx1-2];
				zt += c[2][dpx2];
				dpx1 -= 2;
				dpx2 += 1;
			} else {
				break;
			}
		}

		// cerr << i << ' ' << dpx1 << ' ' << dpx2 << ' ' << zt << '\n';
	}

	for (int i=1; i<=m; i++) {
		zbir_jbg[i] = max(zbir_jbg[i-1] , zbir_tacno[i]);
		// cerr << i << ' ' << zbir_tacno[i] << '\n';
	}

	//

	// iteriram po broju uzetih 3
	ll uzeo_3_start = min(m/3, (ll)c[3].size());
	zbir = sol = 0;

	for (ll uzeo_3 = 0; uzeo_3 <= uzeo_3_start; uzeo_3++) {
		resto_target = m - 3*uzeo_3;

		sol = max(sol, zbir + zbir_jbg[resto_target]);

		if (uzeo_3 != uzeo_3_start) {
			zbir += c[3][uzeo_3];
		}
	}

	cout << sol;
}
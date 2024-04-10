#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, m, k;
	cin >> n >> m >> k;
	if (k < n) {
		cout << k + 1 << " 1\n";
	}
	else {
		ll r = n - (k - n) / (m - 1);
		ll c;
		if (r % 2 == 0) {
			c = (k - n) % (m - 1) + 2;
		}
		else {
			c = (k - n) % (m - 1) + 2;
			c = m + 2 - c;
		}
		cout << r << ' ' << c << '\n';
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}
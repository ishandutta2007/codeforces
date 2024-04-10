#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll sd(ll x) {
	ll z = 0;
	while (x) {
		z += x % 10;
		x /= 10;
	}
	return z;
}

ll pamet(ll n) {
	ll b = 0;
	ll a = n;

	ll p = 1;
	for (int i = 0; i < 14; i++) {
		a = n / p * p - 1;
		if (a >= 0) {
			b = max(b, sd(a) + sd(n - a));
		}
		p *= 10;
	}
	return b;
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n;
	cin >> n;
	cout << pamet(n) << '\n';
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int sd(int x) {
	int z = 0;
	while (x) {
		z += x % 10;
		x /= 10;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll a, b, c;
	basic_string<int> z;
	cin >> a >> b >> c;
	for (ll sx=1; sx<=81; sx++) {
		ll x = b*pow(sx, a) + c;
		if (x <= 0 || x >= 1e9)
			continue;
		if (sd(x) == sx) {
			z += x;
		}
	}
	cout << z.size() << '\n';
	for (ll x : z)
		cout << x << ' ';
	cout << '\n';
}
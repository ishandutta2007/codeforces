#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, m, q;
	cin >> n >> m >> q;
	ll g = gcd(n, m);
	while (q--) {
		ll sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		sy--, ey--;
		if (sx == 1)
			sy /= n/g;
		else
			sy /= m/g;

		if (ex == 1)
			ey /= n/g;
		else
			ey /= m/g;

		cout << (sy == ey ? "YES\n" : "NO\n");
	}
}
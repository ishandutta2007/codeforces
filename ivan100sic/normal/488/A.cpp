#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool lucky(ll x) {
	x = abs(x);
	while (x) {
		if (x % 10 == 8)
			return 1;
		x /= 10;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll a, b=1;
	cin >> a;
	a++;
	while (!lucky(a)) {
		a++, b++;
	}
	cout << b << '\n';
}
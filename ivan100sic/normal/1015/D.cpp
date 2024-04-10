#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, k, s, pos = 1;

void mv(ll z, ll c) {
	while (c--) {
		if (pos + z <= n)
			pos += z;
		else
			pos -= z;
		cout << pos << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> s;
	if (s < k || s > (n-1)*k)
		return cout << "NO\n", 0;

	cout << "YES\n";
	// napravicemo da svi potezi imaju "skoro" istu duzinu
	ll z1, z2, c1, c2;
	if (s % k == 0) {
		z1 = s / k;
		z2 = s / k;
		c1 = k;
		c2 = 0;
	} else {
		z2 = s / k;
		z1 = s / k + 1;
		c1 = s % k;
		c2 = k - c1;
	}

	mv(z1, c1);
	mv(z2, c2);
}
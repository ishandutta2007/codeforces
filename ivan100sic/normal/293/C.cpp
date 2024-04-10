#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll cnt;

void dod(ll x, ll y, ll z) {
	if (x == y && y == z)
		cnt += 1;
	else if (x == y || y == z || x == z)
		cnt += 3;
	else
		cnt += 6;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n;
	cin >> n;

	if (n % 3) {
		cout << "0\n";
		return 0;
	}

	n /= 3;

	basic_string<int> small_divs;
	for (int x=1; x<=40000; x++)
		if (4*n % x == 0)
			small_divs += x;

	for (ll a=1; a<=18000; a++) {
		// cerr << "a: " << a << '\n';
		for (ll x : small_divs) {
			ll b = x - a;
			if (b < a)
				continue;
			ll q = sqrt((ld)(a-b)*(a-b) + (ld)4.0*n / (a+b));
			/*
			if ((q-a-b) / 2 < 0.999 * b) {
				cerr << "a: " << a << ", b: " << b << '\n';
				// break;
			}
			*/

			ll c = round(q);
			if (4*n % (a+b) || c*c != (a-b)*(a-b) + 4*n / (a+b))
				continue;
			c -= a+b;
			if (c % 2 == 0 && (c >> 1) >= b)
				dod(a, b, c >> 1);
		}
	}

	cout << cnt << '\n';
}
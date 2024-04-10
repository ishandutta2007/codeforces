// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ll x;
	cin >> x;

	x %= 360;
	if (x < 0)
		x += 360;

	ll lo = 5555;
	int c = -1;
	for (int i=0; i<4; i++) {
		ll y = x - 90*i;
		y %= 360;
		ll t = min({abs(y), abs(y-360), abs(y+360)});
		if (t < lo) {
			lo = t;
			c = i;
		}
	}
	cout << c << '\n';
}
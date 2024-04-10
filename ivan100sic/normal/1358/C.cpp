// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;

		c -= a;
		d -= b;

		cout << min(c, d) * max(c, d) + 1 << '\n';
	}
}


/*
aaa 00012
  a
	a

b   01222
b
bbb

*/
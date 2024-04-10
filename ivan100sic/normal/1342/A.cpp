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
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		cout << min(2*a, b)*min(x, y) + a*abs(x-y) << '\n';
	}
}
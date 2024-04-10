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
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int x = (a+c-1) / c;
		int y = (b+d-1) / d;
		if (x + y <= k) {
			cout << x << ' ' << y << '\n';
		} else {
			cout << "-1\n";
		}
	}
}
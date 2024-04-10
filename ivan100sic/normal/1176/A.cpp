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

	int t;
	cin >> t;
	while (t--) {
		ll x, y=0;
		cin >> x;
		while (x > 1) {
			if (x % 2 == 0) {
				x /= 2;
				y++;
			} else if (x % 3 == 0) {
				x = 2*x / 3;
				y++;
			} else if (x % 5 == 0) {
				x = 4*x / 5;
				y++;
			} else {
				y = -1;
				break;
			}
		}
		cout << y << '\n';
	}
}
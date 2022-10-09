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

	string ans[2] = {"NO", "YES"};

	int t;
	cin >> t;
	while (t--) {
		ll x, y;
		cin >> x >> y;
		if (x == 1) {
			cout << ans[y == 1] << '\n';
		} else if (x == 2 || x == 3) {
			cout << ans[y <= 3] << '\n';
		} else {
			cout << ans[1] << '\n';
		}
	}
}
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
		int n, best;
		cin >> n >> best;
		ll z = 0;
		while (--n) {
			int x;
			cin >> x;
			if ((x < 0) == (best < 0)) {
				best = max(best, x);
			} else {
				z += best;
				best = x;
			}
		}
		cout << z + best << '\n';
	}
}
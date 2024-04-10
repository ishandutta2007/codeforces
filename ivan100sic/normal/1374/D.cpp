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
		int n, k;
		cin >> n >> k;
		multiset<int> a;
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			x = k - x % k;
			if (x < k) {
				a.insert(x);
			}
		}

		int x = 0;
		ll sol = 0;
		while (a.size()) {
			auto it = a.lower_bound(x);
			if (it == a.end()) {
				it = a.begin();
				x -= k;
			}

			sol += 1 + (*it - x);
			x = (*it + 1) % k;
			a.erase(it);
		}

		cout << sol << '\n';
	}
}
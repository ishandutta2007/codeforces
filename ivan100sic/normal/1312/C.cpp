// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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
		int n, k;
		cin >> n >> k;
		map<int, int> m;
		while (n--) {
			ll x, c=0;
			cin >> x;
			while (x > 0) {
				if (x % k > 1)
					m[0] = 2;
				if (x % k)
					m[c]++;
				c++;
				x /= k;
			}
		}
		int o = 1;
		for (auto [x, y] : m)
			if (y > 1)
				o = 0;
		cout << (o ? "YES\n" : "NO\n");
	}
}

// I will still practice daily...
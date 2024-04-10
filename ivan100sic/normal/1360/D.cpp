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

		set<int> divs;
		for (int x=1; x*x<=n; x++) {
			if (n % x == 0) {
				divs.insert(x);
				divs.insert(n / x);
			}
		}

		int s = n;
		for (int d : divs) {
			if (d <= k) {
				s = min(s, n / d);
			}
		}

		cout << s << '\n';
	}
}
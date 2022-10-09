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
		ll n, m, sol = 0;
		cin >> n >> m;
		for (ll d=1; d<=10; d++) {
			ll b = pow(10, d) - 1;
			if (b <= m)
				sol += n;
		}

		cout << sol << '\n';
	}
}
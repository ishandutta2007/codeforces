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

	int n, k, m, t;
	cin >> n >> k >> m >> t;
	while (t--) {
		int u, v;
		cin >> u >> v;
		if (u == 1) {
			n++;
			if (v <= k)
				k++;
		} else {
			if (v < k)
				k -= v, n -= v;
			else
				n = v;
		}
		cout << n << ' ' << k << '\n';
	}
}
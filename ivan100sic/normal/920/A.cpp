#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int x[205], n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i=1; i<=k; i++)
			cin >> x[i];

		int sol = 0;
		for (int i=1; i<=n; i++) {
			int z = 12313123;
			for (int j=1; j<=k; j++)
				z = min(z, abs(i - x[j]));
			sol = max(sol, z);
		}
		cout << sol+1 << '\n';
	}
}
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
		int n, d;
		cin >> n >> d;

		int l = sqrt(d) - 10000, r = sqrt(d) + 10000;
		int u = 1e9;
		for (int i=max(0, l); i<=r; i++) {
			u = min(u, i + (d+i)/(i+1));
		}
		cout << (u <= n ? "YES\n" : "NO\n");
	}
}
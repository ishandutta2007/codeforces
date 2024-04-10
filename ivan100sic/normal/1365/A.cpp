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
		int n, m;
		cin >> n >> m;
		vector<int> r(n), c(m);
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				int x;
				cin >> x;
				r[i] += x;
				c[j] += x;
			}
		}

		int u = count(begin(r), end(r), 0);
		int v = count(begin(c), end(c), 0);

		cout << (min(u, v) % 2 == 0 ? "Vivek\n" : "Ashish\n");
	}
}
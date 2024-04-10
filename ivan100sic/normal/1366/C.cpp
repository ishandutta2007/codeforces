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
		vector<array<int, 2>> d(n+m-1);
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				int x;
				cin >> x;
				d[min(n+m-2-i-j, i+j)][x]++;
			}
		}

		int sol = 0;

		for (int i=0; i<n+m-1; i++) {
			if (i < n+m-2-i) {
				sol += min(d[i][0], d[i][1]);
			}
		}

		cout << sol << '\n';
	}
}
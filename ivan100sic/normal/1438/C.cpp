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
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				int x;
				cin >> x;
				if (x % 2 != (i+j) % 2) {
					x++;
				}
				cout << x << " \n"[j == m-1];
			}
		}
	}
}
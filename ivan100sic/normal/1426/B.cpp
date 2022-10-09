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
		bool symm = false;

		for (int i=0; i<n; i++) {
			int a[4];
			for (int j=0; j<4; j++) cin >> a[j];
			if (a[1] == a[2]) {
				symm = true;
			}
		}

		if (symm && m % 2 == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
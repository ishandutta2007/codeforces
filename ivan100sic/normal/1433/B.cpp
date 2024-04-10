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
		int n, c=0, l=-1, r=-1;
		cin >> n;
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			if (x == 1) {
				if (l == -1) {
					l = i;
				}
				r = i;
				c++;
			}
		}

		cout << r-l-c+1 << '\n';
	}
}
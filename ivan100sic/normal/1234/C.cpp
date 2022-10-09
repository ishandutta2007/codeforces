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

	int q;
	cin >> q;
	while (q--) {
		int n;
		string a[2];

		cin >> n;
		cin >> a[0] >> a[1];

		int x = 0, y = 0;
		while (y < n) {
			if (a[x][y] <= '2') {
				y++;
			} else {
				if (a[x^1][y] <= '2') {
					y = -1;
					break;
				} else {
					x ^= 1;
					y++;
				}
			}
		}

		cout << (x == 1 && y == n ? "YES\n" : "NO\n");
	}
}
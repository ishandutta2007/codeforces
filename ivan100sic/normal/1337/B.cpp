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
		int x, n, m;
		cin >> x >> n >> m;
		while (n--) {
			if (m > 0 && x <= 10) {
				x -= 10;
				m--;
				break;
			}
			x = x/2 + 10;
		}
		while (m--)
			x -= 10;
		cout << (x <= 0 ? "YES\n" : "NO\n");
	}
}
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
		int n, x = 0, y = 0, ok = 1;
		cin >> n;
		while (n--) {
			int a, b;
			cin >> a >> b;
			if (a >= x && b >= y && b-y <= a-x)
				;
			else
				ok = 0;
			x = a, y = b;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}
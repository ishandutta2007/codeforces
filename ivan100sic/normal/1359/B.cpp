// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int cost(int x, int y, int z) {
	int t = 0;
	if (z % 2)
		t += x;
	t += z/2 * min(y, 2*x);
	return t;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		int sol = 0;
		for (int i=0; i<n; i++) {
			string s;
			cin >> s;
			s += '*';
			int l = 0;
			for (char c : s) {
				if (c == '*') {
					sol += cost(x, y, l);
					l = 0;
				} else {
					l++;
				}
			}
		}
		cout << sol << '\n';
	}
}
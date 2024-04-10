// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int dx[6] = {1, 0, -1, -1, 0, 1};
const int dy[6] = {1, 1, 0, -1, -1, 0};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		ll x, y, c[6];
		cin >> x >> y;
		for (int i=0; i<6; i++) {
			cin >> c[i];
		}

		ll sol = 9e18;

		for (int u=0; u<6; u++) {
			for (int v=0; v<6; v++) {
				if (v%3 == u%3) continue;

				ll f = dx[v]*dy[u] - dx[u]*dy[v];
				ll p = (dx[v]*y - dy[v]*x) * f;
				ll q = (dy[u]*x - dx[u]*y) * f;

				if (p >= 0 && q >= 0) {
					sol = min(sol, p*c[u] + q*c[v]);
				}
			}
		}

		cout << sol << '\n';
	}
}
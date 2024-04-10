// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

// gde se nalazim, koliko je proslo od paljenja zelenog svetla
int d[10005][1005];
// rezultat = broj ciklusa crvenog svetla
int n, m, g, r;
int _a[10010], *a = _a+5;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	memset(d, 255, sizeof d);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> a[i];
	}


	cin >> g >> r;

	sort(a, a+m);

	deque<pair<int, int>> q;
	d[0][0] = 0;
	q.emplace_back(0, 0);

	ll sol = 1e18;

	while (q.size()) {
		auto [i, t] = q.front();
		q.pop_front();

		// cerr << "stanje " << i << ' ' << t << ' ' << d[i][t] << '\n';

		if (i == m-1) {
			// dosli smo do kraja
			// cerr << "kraj " << d[i][t] << ' ' << t << '\n';
			sol = min(sol, (r+g+0ll)*d[i][t] + t);
			// ne moramo dalje
			continue;
		}

		// ako je t == g, idemo pravo na 0 uz dodavanje red lighta
		if (t == g) {
			if (d[i][0] == -1) {
				d[i][0] = d[i][t] + 1;
				q.emplace_back(i, 0);
				continue;
			}
		}

		// mozemo napred?
		int i2 = i+1, t2 = t + a[i+1] - a[i];
		if (i2 < m && t2 <= g) {
			if (d[i2][t2] == -1) {
				d[i2][t2] = d[i][t];
				q.emplace_front(i2, t2);
			}
		}

		// mozemo nazad?
		i2 = i-1, t2 = t + a[i] - a[i-1];
		if (i2 >= 0 && t2 <= g) {
			if (d[i2][t2] == -1) {
				d[i2][t2] = d[i][t];
				q.emplace_front(i2, t2);
			}
		}
	}

	if (sol > 1e17)
		sol = -1;
	cout << sol << '\n';
}
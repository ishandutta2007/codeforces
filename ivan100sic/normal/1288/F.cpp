#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n1, n2, m, r, b, n, cost;
string s1, s2;

int lb[405], ub[405], x[405];
int u[205], v[205], f[205];

int pe[405], pd[405], d[405];
bool ok;

void improve_plus_minus() {
	while (1) {
		bool ch = false;
		for (int i=0; i<m; i++) {
			// push forward?
			if (f[i] < 1) {
				int ecost = f[i] == -1 ? -r : b;
				if (d[u[i]] + ecost < d[v[i]]) {
					d[v[i]] = d[u[i]] + ecost;
					pe[v[i]] = i;
					pd[v[i]] = 0;
					ch = true;
				}
			}

			// push backward?
			if (f[i] > -1) {
				int ecost = f[i] == 1 ? -b : r;
				if (d[v[i]] + ecost < d[u[i]]) {
					d[u[i]] = d[v[i]] + ecost;
					pe[u[i]] = i;
					pd[u[i]] = 1;
					ch = true;
				}
			}
		}
		if (!ch) {
			break;
		}
	}

	int i = -1;
	for (int ii=0; ii<n; ii++) {
		if (x[ii] - 1 >= lb[ii] && (i == -1 || d[ii] < d[i])) {
			i = ii;
		}
	}

	if (i != -1 && d[i] < 1e8) {
		cost += d[i];
		ok = true;
		// super, go back
		int j = i;
		while (1) {
			int e = pe[j];
			if (e == -1)
				break;

			if (pd[j] == 0) {
				x[u[e]]++;
				x[v[e]]--;
				f[e]++;
				j = u[e];
			} else {
				x[u[e]]--;
				x[v[e]]++;
				f[e]--;
				j = v[e];
			}
		}
	}
}

void improve_minus_plus() {
	while (1) {
		bool ch = false;
		for (int i=0; i<m; i++) {
			// push forward?
			if (f[i] > -1) {
				int ecost = f[i] == 1 ? -b : r;
				if (d[u[i]] + ecost < d[v[i]]) {
					d[v[i]] = d[u[i]] + ecost;
					pe[v[i]] = i;
					pd[v[i]] = 0;
					ch = true;
				}
			}

			// push backward?
			if (f[i] < 1) {
				int ecost = f[i] == -1 ? -r : b;
				if (d[v[i]] + ecost < d[u[i]]) {
					d[u[i]] = d[v[i]] + ecost;
					pe[u[i]] = i;
					pd[u[i]] = 1;
					ch = true;
				}
			}
		}
		if (!ch) {
			break;
		}
	}

	int i = -1;
	for (int ii=0; ii<n; ii++) {
		if (x[ii] + 1 <= ub[ii] && (i == -1 || d[ii] < d[i])) {
			i = ii;
		}
	}

	if (i != -1 && d[i] < 1e8) {
		cost += d[i];
		ok = true;
		// super, go back
		int j = i;
		while (1) {
			int e = pe[j];
			if (e == -1)
				break;

			if (pd[j] == 0) {
				x[u[e]]--;
				x[v[e]]++;
				f[e]--;
				j = u[e];
			} else {
				x[u[e]]++;
				x[v[e]]--;
				f[e]++;
				j = v[e];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n1 >> n2 >> m >> r >> b >> s1 >> s2;

	for (int i=0; i<n1; i++) {
		lb[i] = -123123;
		ub[i] = 123123;
		if (s1[i] == 'B') {
			lb[i] = 1;
		} else if (s1[i] == 'R') {
			ub[i] = -1;
		}
	}

	for (int i=0; i<n2; i++) {
		lb[i+n1] = -123123;
		ub[i+n1] = 123123;
		if (s2[i] == 'R') {
			lb[i+n1] = 1;
		} else if (s2[i] == 'B') {
			ub[i+n1] = -1;
		}
	}

	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i];
		u[i]--, v[i]--;
		v[i] += n1;
	}

	n = n1 + n2;

	while (1) {
		ok = true;
		for (int i=0; i<n; i++)
			if (x[i] < lb[i] || x[i] > ub[i])
				ok = false;
		if (ok) {
			cout << cost << '\n';
			for (int i=0; i<m; i++)
				cout << "RUB"[f[i]+1];
			cout << '\n';
			return 0;
		}

		ok = false;

		// povecavamo start, smanjujemo end
		memset(d, 63, sizeof d);
		for (int i=0; i<n; i++)
			if (x[i] < lb[i])
				d[i] = 0, pe[i] = -1;
		improve_plus_minus();

		memset(d, 63, sizeof d);
		for (int i=0; i<n; i++)
			if (x[i] > ub[i])
				d[i] = 0, pe[i] = -1;
		improve_minus_plus();

		// for (int i=0; i<n; i++)
		// 	cerr << x[i] << ' ';
		// cerr << '\n';

		if (!ok) {
			cout << "-1\n";
			return 0;
		}
	}
}
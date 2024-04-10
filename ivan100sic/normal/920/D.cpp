// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, k, v;
int a[5005];
int d[5005][5005];

void no() {
	cout << "NO\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> k >> v;
	for (int i=0; i<n; i++)
		cin >> a[i];

	d[0][0] = 1;

	for (int i=0; i<n; i++) {
		int x = a[i] % k;
		for (int j=0; j<k; j++) {
			if (!d[i][j])
				continue;
			d[i+1][j] |= 1;
			d[i+1][(j+x) % k] |= 2;
		}
	}

	string used(n, 0);

	int r = v % k;
	if (d[n][r] == 0) {
		no();
	}

	for (int i=n; i; i--) {
		if (d[i][r] & 2) {
			used[i-1] = 1;
			r = (r + k - a[i-1] % k) % k;
			cerr << "using " << i-1 << '\n';
		}
	}

	int ur = -1, nur = -1;

	for (int i=0; i<n; i++) {
		if (used[i]) {
			ur = i;
		} else {
			nur = i;
		}
	}

	vector<tuple<int, int, int>> sol;

	if (nur == -1) {
		// skupi sve pa baci sto ti se ne svidja
		for (int i=1; i<n; i++) {
			sol.emplace_back(1'000'000'000, i, 0);
			a[0] += a[i];
			a[i] = 0;
		}

		if (a[0] < v) {
			no();
		}

		sol.emplace_back((a[0] - v) / k, 0, 1);
	} else if (ur == -1) {
		// skupi sve
		for (int i=1; i<n; i++) {
			sol.emplace_back(1'000'000'000, i, 0);
			a[0] += a[i];
			a[i] = 0;
		}

		if (a[0] < v) {
			no();
		}

		// prebaci u 1 koliko ti treba
		sol.emplace_back(v / k, 0, 1);
	} else {
		// skupi uzete u ur, ostale u nur
		for (int i=0; i<n; i++) {
			if (used[i] && i != ur) {
				sol.emplace_back(1'000'000'000, i, ur);
				a[ur] += a[i];
				a[i] = 0;
			} else if (!used[i] && i != nur) {
				sol.emplace_back(1'000'000'000, i, nur);
				a[nur] += a[i];
				a[i] = 0;
			}
		}

		int mp = a[nur] / k * k;
		if (a[ur] + mp < v) {
			no();
		}

		if (v > a[ur]) {
			sol.emplace_back((v - a[ur]) / k, nur, ur);
		} else {
			sol.emplace_back((a[ur] - v) / k, ur, nur);
		}
	}

	sol.erase(remove_if(begin(sol), end(sol), [](auto x) { return get<0>(x) == 0; }), sol.end());

	cout << "YES\n";
	for (auto [x, y, z] : sol)
		cout << x << ' ' << y+1 << ' ' << z+1 << '\n';
}
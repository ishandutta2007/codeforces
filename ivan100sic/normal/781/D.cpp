#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
#include <array>
#include <bitset>
using namespace std;

typedef unsigned long long ull;

typedef array<bitset<512>, 512> matrica;

matrica transpose(const matrica& other) {
	matrica tmp;
	for (ull i=0; i<512; i++) {
		for (ull j=0; j<512; j++) {
			tmp[j][i] = other[i][j];
		}
	}
	return tmp;
}

matrica mul(const matrica& a, const matrica& b) {
	matrica c = transpose(b);
	matrica d;

	for (ull i=0; i<512; i++) {
		for (ull j=0; j<512; j++) {
			auto bs = a[i] & c[j];
			if (bs.any()) {
				d[i][j] = 1;
			} else {
				d[i][j] = 0;
			}
		}
	}

	return d;
}

int n, m;

bool check(const matrica& a) {
	for (int i=1; i<=n; i++) {
		if (a[i].any()) {
			return true;
		}
	}
	return false;
}

matrica p[65], q[65], ident;

ull solve(matrica a, ull base, ull order, int t) {

	if (order == 0) {
		return base;
	}

	// cerr << base << ' ' << order << ' ' << t << '\n';

	// probaj levu polovinu

	matrica t2 = mul(a, (t?q:p)[order-1]);

	if (!check(t2)) {
		return solve(a, base, order-1, t);
	} else {
		return solve(t2, base + (1ull << (order-1)), order-1, t^1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v, t;
		cin >> u >> v >> t;

		if (t == 0) {
			p[0][u][v] = 1;
		} else {
			q[0][u][v] = 1;
		}
	}

	for (int i=1; i<65; i++) {
		p[i] = mul(p[i-1], q[i-1]);
		q[i] = mul(q[i-1], p[i-1]);
	}

	for (int i=0; i<512; i++) {
		ident[i][i] = 1;
	}

	ull sol = solve(ident, 0, 61, 0);

	if (sol > 1'000'000'000'000'000'000ull) {
		cout << -1;
	} else {
		cout << sol << '\n';
	}

}
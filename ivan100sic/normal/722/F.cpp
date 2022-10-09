#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> a[100005];
vector<pair<int, int>> b[100005];

// 7, 25, 27, 32

struct restriction {
	int lista[12] = { 7, 25, 27, 32, 11, 13, 17, 19, 23, 29, 31, 37};
	int z[12][50];

	restriction() {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < lista[i]; j++) {
				z[i][j] = 0;
			}
		}
	}

	void change(int mod, int rem, int delta) {
		for (int i = 0; i<12; i++) {
			int start = rem % lista[i];
			int curr = start;

			do {
				z[i][curr] -= delta;
				curr = (curr + mod) % lista[i];
			} while (curr != start);

			for (int j = 0; j<lista[i]; j++) z[i][j] += delta;
		}
	}

	bool moze() {
		// ako postoji za svaki moduo po jedna moguca onda ok
		for (int i = 0; i<12; i++) {
			bool ima = false;
			for (int j = 0; j<lista[i]; j++) {
				if (z[i][j] == 0) {
					ima = true;
					break;
				}
			}
			if (!ima) return false;
		}
		return true;
	}

};

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		a[i].resize(k);
		for (int& x : a[i]) cin >> x;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j<a[i].size(); j++) {
			b[a[i][j]].push_back({ i, j });
		}
	}

	for (int i = 1; i <= m; i++) {
		if (b[i].size() == 0) {
			cout << 0 << endl;
			continue;
		}
		restriction rest;
		int sol = 0;
		int r = 0;
		rest.change(a[b[i][0].first].size(), b[i][0].second, +1);
		for (int l = 0; l<b[i].size(); l++) {

			if (r < l) {
				// force
				rest.change(a[b[i][l].first].size(), b[i][l].second, +1);
				r = l;
			}

			while (1) {
				if (r < b[i].size() - 1 && b[i][r + 1].first == b[i][r].first + 1) {
					r++;
					rest.change(a[b[i][r].first].size(), b[i][r].second, +1);

					if (!rest.moze()) {
						rest.change(a[b[i][r].first].size(), b[i][r].second, -1);
						r--;
						break;
					}
				} else break;
			}

			sol = max(sol, r - l + 1);

			// remove l
			rest.change(a[b[i][l].first].size(), b[i][l].second, -1);
		}

		cout << sol << endl;
	}

	cin >> n;





	return 0;
}
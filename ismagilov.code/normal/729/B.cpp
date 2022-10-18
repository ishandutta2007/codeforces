#include <iostream>

#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"

using namespace std;

main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	bool a[n][m];
	bool summ[4][n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int tek;
	tek = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == 0) {
				summ[tek][i][j] = a[i][j];
			}
			else {
				summ[tek][i][j] = (a[i][j] || summ[tek][i][j - 1]);
			}
		}
	}
	tek = 2;
	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			if (j == m - 1) {
				summ[tek][i][j] = a[i][j];
			}
			else {
				summ[tek][i][j] = (a[i][j] || summ[tek][i][j + 1]);
			}
		}
	}
	tek = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0) {
				summ[tek][i][j] = a[i][j];
			}
			else {
				summ[tek][i][j] = (a[i][j] || summ[tek][i - 1][j]);
			}
		}
	}
	tek = 3;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (i == n - 1) {
				summ[tek][i][j] = a[i][j];
			}
			else {
				summ[tek][i][j] = (a[i][j] || summ[tek][i + 1][j]);
			}
		}
	}
	int kol = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				kol += summ[0][i][j] + summ[1][i][j] + summ[2][i][j] + summ[3][i][j];
			}
		}
	}
	cout << kol;
}
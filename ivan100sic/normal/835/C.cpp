#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int a[105][105][15], c, n, q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> q >> c;
	c++;

	for (int i=0; i<n; i++) {
		int x, y, s;
		cin >> x >> y >> s;
		a[x][y][s]++;
	}

	for (int i=1; i<=102; i++) {
		for (int j=1; j<=102; j++) {
			for (int k=0; k<c; k++) {
				a[i][j][k] += a[i-1][j][k] + a[i][j-1][k] - a[i-1][j-1][k];
			}
		}
	}

	while (q--) {
		int t, xl, yl, xr, yr;
		cin >> t >> xl >> yl >> xr >> yr;

		xl--;
		yl--;

		// s+t == k

		int sol = 0;

		for (int s=0; s<c; s++) {
			int k = (s+t) % c;
			sol += (a[xr][yr][s] - a[xr][yl][s] - a[xl][yr][s] + a[xl][yl][s]) * k;
		}

		cout << sol << '\n';


	}
	
}
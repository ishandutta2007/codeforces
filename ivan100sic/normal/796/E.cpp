#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int dp[2][1101][101];
int z[4][1101];
int n, p, k;

int sol;

inline void sugg(int& a, int b) {
	a = max(a, b);
	sol = max(sol, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> p >> k;
	for (int i=0; i<2; i++) {
		int a;
		cin >> a;
		while (a--) {
			int x;
			cin >> x;
			z[i][x] = 1;
		}
	}

	{
		for (int i=1; i<=n+k+k; i++) {
			if (z[0][i] - z[1][i] == 1) {
				z[2][i] = 1;
			}

			if (z[0][i] - z[1][i] == -1) {
				z[3][i] = 1;
			}
		}

		for (int i=1; i<=n+k+k; i++) {
			for (int j=0; j<4; j++) {
				z[j][i] += z[j][i-1];
			}
		}
	}

	for (int q=0; q<p; q++) {

		auto tgt = dp[1 - q % 2];
		auto moj = dp[q % 2];

		for (int x=0; x<=n+k; x++) {

			int ly = max(x-k, 0);
			int uy = min(x+k, n+k);

			for (int y=ly; y<=uy; y++) {

				int offerer = moj[x][y-x+k];

				sugg(tgt[x][y-x+k], offerer);

				if (y-x+k-1 >= 0) {
					sugg(moj[x+1][y-x+k-1], offerer);
				}

				if (y-x+k+1 <= k+k) {
					sugg(moj[x][y-x+k+1], offerer);
				}

				if (x <= y) {
					int dod = z[0][x+k] - z[0][y];
					dod += z[2][y] - z[2][x];
					sugg(tgt[x+k][y-x], offerer + dod);

					//
					dod = z[1][y+k] - z[1][y];
					sugg(tgt[y][2*k], offerer + dod);
				}

				if (y <= x) {
					int dod = z[1][y+k] - z[1][x];
					dod += z[3][x] - z[3][y];
					sugg(tgt[x][y-x+k+k], offerer + dod);

					//
					dod = z[0][x+k] - z[0][x];
					sugg(tgt[x+k][0], offerer + dod);
				}
			}
		}
	}

	cout << sol;

}
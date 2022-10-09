// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[88];
int p0[88];

const int inf = 1e9;

// koliko smo stavili nula
//   koliko smo stavili nula pre zadnjeg keca
//     ukupno buld rastojanje
int dp[2][81][81][3333], sol[6666];

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	int c0 = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			p0[c0] = i;
			c0++;
		}
	}

	memset(dp, 192, sizeof dp);
	dp[0][0][0][0] = 0;

	for (int i=0; i<n; i++) {
		auto ol = dp[i&1];
		auto nu = dp[(i&1)^1];

		for (int j=0; j<=i+1; j++) {
			for (int k=0; k<=i+1; k++) {
				for (int l=0; l<3330; l++) {
					nu[j][k][l] = -inf;
				}
			}
		}

		for (int j=0; j<=i+1 && j<=c0; j++) {
			for (int k=0; k<=i+1; k++) {
				for (int l=0; l<3330; l++) {
					// stavimo nulu?
					if (j < c0) {
						int j_ = j+1;
						int k_ = k;
						int l_ = l + abs(i - p0[j]);

						int v = ol[j][k][l] + k;
						mx(nu[j_][k_][l_], v);
					}

					// stavimo keca?
					{
						int j_ = j;
						int k_ = j;
						int l_ = l;

						int v = ol[j][k][l];
						mx(nu[j_][k_][l_], v);
					}
				}
			}
		}
	}

	for (int j=0; j<=n; j++) {
		for (int k=0; k<=n*(n-1)/2; k++) {
			mx(sol[k], dp[n&1][c0][j][k]);
		}
	}

	for (int k=0; k<=n*(n-1)/2; k++) {
		if (k) sol[k] = max(sol[k], sol[k-1]);
		cout << sol[k] << ' ';
	}
	cout << '\n';

}
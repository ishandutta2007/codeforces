#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const string wn[2] = {"BitLGM\n", "BitAryo\n"};

namespace ns2 {
	int w[305][305];
	bool wx[305], wy[305], wxy[666];
	int x, y;

	void solve() {
		cin >> x >> y;
		for (int i=0; i<=x; i++) {
			for (int j=0; j<=y; j++) {
				int& a = w[i][j];
				a = 2;

				if (wx[i])
					a = 1;
				if (wy[j])
					a = 1;
				if (wxy[i-j+333])
					a = 1;

				if (a == 2) {
					wx[i] = wy[j] = wxy[i-j+333] = 1;
				}
			}
		}

		cout << wn[w[x][y]-1];
	}
}

namespace ns3 {

	int w[305][305][305];
	bool wx[305][305][305], wy[305][305][305], wz[305][305][305], wd[305][305][305];
	int x, y, z;

	void solve() {
		cin >> x >> y >> z;
		for (int i=0; i<=x; i++) {
			for (int j=0; j<=y; j++) {
				for (int k=0; k<=z; k++) {
					int& a = w[i][j][k];
					a = 2;

					if (i > 0) {
						if (wx[i-1][j][k]) {
							a = 1;
							wx[i][j][k] = 1;
						}
					}

					if (j > 0) {
						if (wy[i][j-1][k]) {
							a = 1;
							wy[i][j][k] = 1;
						}
					}

					if (k > 0) {
						if (wz[i][j][k-1]) {
							a = 1;
							wz[i][j][k] = 1;
						}
					}

					if (i && j && k) {
						if (wd[i-1][j-1][k-1]) {
							a = 1;
							wd[i][j][k] = 1;
						}
					}

					if (a == 2) {
						wx[i][j][k] = 1;
						wy[i][j][k] = 1;
						wz[i][j][k] = 1;
						wd[i][j][k] = 1;
					}
				}
			}
		}

		cout << wn[w[x][y][z]-1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	if (n == 1) {
		int x;
		cin >> x;
		cout << wn[x == 0];
	} else if (n == 2) {
		ns2::solve();
	} else {
		ns3::solve();
	}
}
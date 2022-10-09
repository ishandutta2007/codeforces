#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ld d[105][105][105][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int r, s, p;
	cin >> r >> s >> p;

	for (int i=0; i<=r; i++) {
		for (int j=0; j<=s; j++) {
			for (int k=0; k<=p; k++) {
				auto q = d[i][j][k];
				if (i+j+k == 0)
					continue;
				if (i+j == 0)
					q[2] = 1;
				else if (i+k == 0)
					q[1] = 1;
				else if (j+k == 0)
					q[0] = 1;
				else {
					ld p = i*j + j*k + k*i;
					if (i && j) {
						q[0] += i*j / p * d[i][j-1][k][0];
						q[1] += i*j / p * d[i][j-1][k][1];
						q[2] += i*j / p * d[i][j-1][k][2];
					}
					if (j && k) {
						q[0] += j*k / p * d[i][j][k-1][0];
						q[1] += j*k / p * d[i][j][k-1][1];
						q[2] += j*k / p * d[i][j][k-1][2];
					}
					if (i && k) {
						q[0] += i*k / p * d[i-1][j][k][0];
						q[1] += i*k / p * d[i-1][j][k][1];
						q[2] += i*k / p * d[i-1][j][k][2];
					}
				}
			}
		}
	}

	{
		cout << setprecision(20) << fixed;
		auto q = d[r][s][p];
		cout << q[0] << ' ' << q[1] << ' ' << q[2] << '\n';
	}
}
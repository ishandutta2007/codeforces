#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

double d[2005][2005];
int n, t;
double p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	d[0][0] = 1;
	cin >> n >> p >> t;

	double sol = 0;

	for (int i=0; i<t; i++) {
		for (int j=0; j<=n; j++) {
			if (j == n) {
				d[i+1][n] += d[i][n];
			} else {
				d[i+1][j] += d[i][j] * (1-p);
				d[i+1][j+1] += d[i][j] * (p);
			}
		}
	}

	for (int j=0; j<=n; j++)
		sol += d[t][j] * j;

	cout.precision(20); cout << fixed;
	cout << sol << '\n';
}
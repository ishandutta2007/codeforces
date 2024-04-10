#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string a[33];
int z[33][33];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) {
			z[i+1][j+1] = z[i+1][j] + z[i][j+1] - z[i][j] + (a[i][j] == '1');
		}
	int sol = 0;
	for (int p=0; p<n; p++)
		for (int q=0; q<m; q++)
			for (int r=p+1; r<=n; r++)
				for (int s=q+1; s<=m; s++) {
					int c = 0;
					c += z[p][q];
					c += z[r][s];
					c -= z[p][s];
					c -= z[r][q];
					if (c == 0) {
						sol = max(sol, r-p+s-q);
					}
				}
	cout << 2 * sol << '\n';
}
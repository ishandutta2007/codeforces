#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ull dp[55][55];
int n, h;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> h;
	dp[0][0] = 1;
	for (int i=1; i<=n; i++) {
		for (int l=0; l<i; l++) {
			int r = i-l-1;
			for (int x=0; x<=n; x++) {
				for (int y=0; y<=n; y++) {
					dp[i][max(x, y)+1] += dp[l][x] * dp[r][y];					
				}
			}
		}
	}

	ull z = 0;
	for (int j=h; j<=n; j++)
		z += dp[n][j];
	cout << z << '\n';
}
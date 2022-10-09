#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int mod = 1'000'000'007;

int dp[2005][2005][2][2];
string a, b;
int m, d;

void ad(int& x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> m >> d >> a >> b;
	int n = a.size();

	dp[0][0][0][0] = 1;
	for (int i=0; i<n; i++)
	for (int j=0; j<m; j++)
	for (int k=0; k<2; k++)
	for (int l=0; l<2; l++)
	for (int x=0; x<10; x++) {
		if ((x == d) != (i % 2 == 1))
			continue;
		if (k == 0 && x < a[i]-'0')
			continue;
		if (l == 0 && x > b[i]-'0')
			continue;

		int k2 = k || x > a[i]-'0';
		int l2 = l || x < b[i]-'0';
		ad(dp[i+1][(10*j+x)%m][k2][l2], dp[i][j][k][l]);
	}

	int sol = 0;
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			ad(sol, dp[n][0][i][j]);
	cout << sol << '\n';
}
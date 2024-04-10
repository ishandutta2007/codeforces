#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int mod = 1000000007;

int n, m;
string a[2005];
int rt[2005][2005], ct[2005][2005];
int dp[2][2005][2005], sm[2][2005][2005];

int add(int x, int y) {
	x += y;
	return x - (x >= mod) * mod;
}

int sub(int x, int y) {
	x -= y;
	return x + (x < 0) * mod;
}

void wrt(int i, int j, int k, int v) {
	dp[i][j][k] = v;
	sm[i][j][k] = add(sm[i][j+i][k+(1^i)], v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=n-1; i>=0; i--) {
		for (int j=m-1; j>=0; j--) {
			rt[i][j] = rt[i+1][j];
			ct[i][j] = ct[i][j+1];
			if (a[i][j] == 'R')
				rt[i][j]++, ct[i][j]++;
		}
	}

	if (a[n-1][m-1] == 'R') {
		cout << "0\n";
		return 0;
	}

	if (n == 1 && m == 1) {
		cout << "1\n";
		return 0;
	}

	wrt(0, n-1, m-1, 1);
	wrt(1, n-1, m-1, 1);
	for (int i=n-1; i>=0; i--) {
		for (int j=m-1; j>=0; j--) {
			if (i == n-1 && j == m-1)
				continue;
			wrt(0, i, j, sub(sm[1][i+1][j], sm[1][n-rt[i+1][j]][j]));
			wrt(1, i, j, sub(sm[0][i][j+1], sm[0][i][m-ct[i][j+1]]));
		}
	}

	cout << add(dp[0][0][0], dp[1][0][0]) << '\n';
}
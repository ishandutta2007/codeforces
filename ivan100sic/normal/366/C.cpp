#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int HI = 110055;
int dp[105][HI];
int n, k;
int a[105], b[105];

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];

	memset(dp, 128, sizeof(dp));
	const int NO = dp[0][0];
	const int OFFS = 100033;

	dp[0][0 + OFFS] = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<HI; j++) {
			if (dp[i][j] == NO)
				continue;
			mx(dp[i+1][j], dp[i][j]);
			mx(dp[i+1][j+a[i]-k*b[i]], dp[i][j]+a[i]);
		}
	}
	int z = dp[n][OFFS];
	if (z <= 0)
		z = -1;
	cout << z << '\n';
}
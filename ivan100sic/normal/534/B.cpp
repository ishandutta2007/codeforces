#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int v1, v2, t, d;
int dp[1005][1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	memset(dp, 255, sizeof(dp));
	cin >> v1 >> v2 >> t >> d;
	dp[1][v1] = v1;

	for (int i=1; i<t; i++) {
		for (int j=1; j<=900; j++) {
			if (dp[i][j] == -1)
				continue;
			for (int k=max(1, j-d); k<=j+d; k++) {
				dp[i+1][k] = max(dp[i+1][k], dp[i][j] + k);
			}
		}
	}
	cout << dp[t][v2] << '\n';
}
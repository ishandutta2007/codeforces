#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
char c[7][7];

int dp[7][7]; // duzina, prvo slovo

int solve(int k, int z) {
	if (dp[k][z] != -1)
		return dp[k][z];
	if (k == 1)
		return dp[k][z] = z == 1;
	dp[k][z] = 0;
	for (int i=1; i<=6; i++) {
		if (c[z][i]) {
			dp[k][z] += solve(k-1, c[z][i]);
		}
	}
	return dp[k][z];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// the Ctrl+D approach
	cin >> n >> q;
	while (q--) {
		string s, p;
		cin >> s >> p;
		c[s[0] - 'a' + 1][s[1] - 'a' + 1] = p[0] - 'a' + 1;
	}

	memset(dp, 255, sizeof(dp));

	int z = 0;
	for (int i=1; i<=6; i++)
		z += solve(n, i);
	cout << z << '\n';

}
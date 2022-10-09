#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s;
int n, q;
int a[3];
string p[3];
int nx[100005][26];
int dp[254][254][254];

void mn(int& x, int y) {
	if (x == -1)
		x = y;
	else
		x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q >> s;
	for (char x='a'; x<='z'; x++) {
		nx[n][x-'a'] = n+1;
		nx[n+1][x-'a'] = n+1;
	}

	for (int i=n-1; i>=0; i--) {
		copy(nx[i+1], nx[i+1]+26, nx[i]);
		nx[i][s[i] - 'a'] = i+1;
	}

	memset(dp, 255, sizeof(dp));
	dp[0][0][0] = 0;

	while (q--) {
		char t;
		int idx;
		char x;
		cin >> t >> idx;
		idx--;
		if (t == '-') {
			for (int i=(idx == 0 ? a[0] : 0); i<=a[0]; i++)
			for (int j=(idx == 1 ? a[1] : 0); j<=a[1]; j++)
			for (int k=(idx == 2 ? a[2] : 0); k<=a[2]; k++)
			{
				dp[i][j][k] = -1;
			}
			p[idx].pop_back();
			a[idx]--;
		} else {
			cin >> x;
			p[idx] += x;
			a[idx]++;
			for (int i=(idx == 0 ? a[0] : 0); i<=a[0]; i++)
			for (int j=(idx == 1 ? a[1] : 0); j<=a[1]; j++)
			for (int k=(idx == 2 ? a[2] : 0); k<=a[2]; k++)
			{
				// cerr << "inner " << i << ' ' << j << ' ' << k << '\n';
				if (i) mn(dp[i][j][k], nx[dp[i-1][j][k]][p[0][i-1] - 'a']);
				if (j) mn(dp[i][j][k], nx[dp[i][j-1][k]][p[1][j-1] - 'a']);
				if (k) mn(dp[i][j][k], nx[dp[i][j][k-1]][p[2][k-1] - 'a']);
			}
		}
		// cerr << dp[a[0]][a[1]][a[2]] << '\n';
		cout << (dp[a[0]][a[1]][a[2]] <= n ? "YES\n" : "NO\n");
	}
}
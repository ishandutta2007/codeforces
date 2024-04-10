#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a, b, v,ans;
int dp[101][101][101],lps[101];
vector<int> back[101][101][101];
int main() {
	int i, j,k,n,m,o,l;
	cin >> a >> b >> v;
	n = a.size(), m = b.size(), o = v.size();
	a = ' ' + a;
	b = ' ' + b;
	memset(dp,-0x3f, sizeof(dp));
	l = 0;
	for (i = 1; i < o; ) {
		if (v[i] == v[l])lps[i] = ++l,i++;
		else {
			if (l != 0)l = lps[l - 1];
			else lps[i++] = 0;
		}
	}
	dp[0][0][0] = 0;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= m;j++) {
			if (i)for (k = 0; k < o; k++)if (dp[i - 1][j][k] >= dp[i][j][k])dp[i][j][k] = dp[i - 1][j][k], back[i][j][k] = { i - 1,j,k };
			if (j)for (k = 0; k < o; k++)if (dp[i ][j-1][k] >= dp[i][j][k])dp[i][j][k] = dp[i ][j-1][k], back[i][j][k] = { i ,j-1,k };
			if (i&&j&&a[i] == b[j]) {
				for (k = 0; k < o; k++) {
					int t=k;
					while (t != 0 && a[i] != v[t])t = lps[t - 1];
					if (a[i] == v[t])t++;
					if (dp[i - 1][j - 1][k] + 1 >= dp[i][j][t])dp[i][j][t] = dp[i - 1][j - 1][k] + 1, back[i][j][t] = { i - 1,j - 1,k };
				}
			}
		}
	}
	int st = 0; l = 0;
	for (i = 0; i < o; i++)if (dp[n][m][i] >= l)l = dp[n][m][i], st = i;
	vector<int> cur = { n,m,st };
	while (cur[0] | cur[1]) {
		vector<int> nex = back[cur[0]][cur[1]][cur[2]];
		if (nex[0] == cur[0] - 1 && nex[1] == cur[1] - 1)ans.push_back(a[cur[0]]);
		cur = nex;
	}
	for (i = ans.size() - 1; i >= 0; i--)printf("%c", ans[i]);
	if (ans.size() == 0)printf("0");
	getchar(); getchar();
}
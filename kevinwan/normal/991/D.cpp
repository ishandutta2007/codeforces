#include <bits/stdc++.h>
#define mmax(a,b) a=max(a,b)
using namespace std;
typedef long long ll;
string s[2];
int dp[100][3],a[100],pp[100];
int main() {
	cin >> s[0] >> s[1];
	int n = s[0].size(),i,j;
	memset(dp, 0x80, sizeof(dp));
	for (i = 0; i < n; i++)a[i] = (s[0][i] == '0') + (s[1][i] == '0');
	dp[0][a[0]] = 0;
	pp[0] = 0;
	for (i = 1; i < n; i++) {
		for(j=0;j<=a[i];j++)dp[i][j] = pp[i - 1];
		if (a[i] >= 1) {
			mmax(dp[i][a[i] - 1], dp[i - 1][2] + 1);
		}
		if (a[i] == 2) {
			mmax(dp[i][a[i] - 2], dp[i - 1][1]+1);
		}
		pp[i] = max(dp[i][0], dp[i][1]);
		mmax(pp[i], dp[i][2]);
	}
	printf("%d", pp[n - 1]);
	getchar(); getchar();
}
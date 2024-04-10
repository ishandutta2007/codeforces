#include<iostream>

using namespace std;

const int MAXN = 105;

int n, d;
int dp[MAXN];
string s;

int main () {
	cin >> n >> d >> s;
	dp[n-1]=0;
	for (int i=n-2; i>=0; i--) {
		dp[i]=MAXN;
		if (s[i]=='0') continue;
		for (int j=1; j<=d; j++) {
			if (i+j<n) dp[i]=min(dp[i], 1+dp[i+j]);
		}
	}
	if (dp[0]>=MAXN) cout << -1; else cout << dp[0];
	return 0;
}
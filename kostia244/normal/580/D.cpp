#include <bits/stdc++.h>
using namespace std;
#define MOD(ARG) while(ARG >= mod) ARG -= mod

long long dp[262144][19], rules[19][19], pl[19], n, m, k, f, t, c;

long long d(int mask, int prev) {
	if(dp[mask][prev] != -1)
		return dp[mask][prev];
	int k = 0;
	for(int i = 0; i < 18; i++)
		k += (mask>>i)&1;
	if(k == m)
		return 0;
	dp[mask][prev] = -1000000000000ll;
	for(int i = 0; i < 18; i++) {
		if(((mask>>i)&1) == 0) {
			dp[mask][prev] = max(dp[mask][prev], pl[i + 1] + rules[prev][i + 1] + d(mask|(1<<i),i + 1));
		}
	}

	return dp[mask][prev];
}

int main() {
	memset(rules, 0, sizeof(rules));
	memset(dp, -1, sizeof(dp));
	memset(pl, 0, sizeof(pl));
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		cin >>pl[i];
	while(k--)
		cin >> f >> t >> c, rules[f][t] = c;
	cout << d(0, 0);
	return 0;
}
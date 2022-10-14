#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

pair<ll, ll> a[200010];
ll dp[200010][6];
ll ans[200010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	for(ll i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = make_pair(x, i);
	}
	sort(a, a + n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 6; j++) dp[i][j] = 1000000000;
	dp[1][1] = 0;
	for(ll i = 2; i <= n; i++)
		for(ll j = 1; j <= min(i, 5ll); j++)
			if(j == 1){
				for(ll k = 3; k < 6; k++)
					dp[i][j] = min(dp[i][j], dp[i - j][k]);
			} else dp[i][j] = a[i - 1].first - a[i - 2].first + dp[i - 1][j - 1];
	int idx = n, team = 1;
	while(idx > 0) {
		int mK  = 3;
		if(dp[idx][4] < dp[idx][mK]) mK = 4;
		if(dp[idx][5] < dp[idx][mK]) mK = 5;
		for(ll i = 0; i < mK; i++)
			ans[a[idx-- - 1].second] = team;
		team++;
	}
	cout << min(min(dp[n][3], dp[n][4]), dp[n][5]) << " " << team - 1 << endl;
	for(ll i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
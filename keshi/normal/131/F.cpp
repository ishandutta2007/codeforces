#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 600;

ll n, m, k, cnt[maxn][maxn], dp[maxn][maxn], ans, t;

string d[maxn];

bool val(ll i, ll j){
	if(!(1 < i && i < n && 1 < j && j < m))return 0;
	if(d[i][j] == '0' || d[i][j + 1] == '0' || d[i][j - 1] == '0' || d[i - 1][j] == '0' || d[i + 1][j] == '0')return 0;
	return 1;
}

ll cal(ll s, ll e, ll l, ll r){
	return dp[e - 1][r - 1] - dp[s][r - 1] - dp[e - 1][l] + dp[s][l];
}

int main(){
	cin >> n >> m >> k;
	for(ll i = 1; i <= n; i++){
		cin >> d[i];
		d[i] = '0' + d[i] + '0';
	}
	for(ll j = 1; j <= m; j++){
		for(ll i = 1; i <= n; i++){
			cnt[j][i] = cnt[j][i - 1] + val(i, j);
		}
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			dp[i][j] = dp[i][j - 1] + cnt[j][i];
		}
	}
	for(ll s = 1; s <= n; s++){
		for(ll e = s; e <= n; e++){
			ll r = 1;
			for(ll l = 1; l <= m; l++){
				if(cal(s, e, l, m) < k) break;
				while(cal(s, e, l, r) < k && r <= m){
					r++;
				}
				ans += m - r + 1;
			}
		}
	}
	cout << ans;
	return 0;
}
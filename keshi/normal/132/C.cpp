#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 110;
const ll maxm = 60;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, dp[2][maxm][maxm][2][2], ans;

bool val[2][maxm][maxm][2];

string s;

int main(){
	fast_io;
	
	cin >> s >> m;
	
	n = s.size();
	
	val[0][0][0][0] = 1;
	val[0][0][0][1] = 1;
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j <= m; j++){
			for(ll k = 0; k <= j; k++){
				val[i % 2][j][k][0] = 0;
				val[i % 2][j][k][1] = 0;
				for(ll x = 0; x <= j - k; x++){
					if(val[1 - i % 2][j - k][x][0]){
						if(s[i - 1] == 'F' && k % 2 == 0 || s[i - 1] == 'T' && k % 2 == 1){
							if(!val[i % 2][j][k][0]){
								dp[i % 2][j][k][0][0] = dp[1 - i % 2][j - k][x][0][0] + 1;
								dp[i % 2][j][k][0][1] = dp[1 - i % 2][j - k][x][0][1] + 1;
							}
							dp[i % 2][j][k][0][0] = min(dp[i % 2][j][k][0][0], dp[1 - i % 2][j - k][x][0][0] + 1);
							dp[i % 2][j][k][0][1] = max(dp[i % 2][j][k][0][1], dp[1 - i % 2][j - k][x][0][1] + 1);
							val[i % 2][j][k][0] = 1;
						}
						else{
							if(!val[i % 2][j][k][1]){
								dp[i % 2][j][k][1][0] = dp[1 - i % 2][j - k][x][0][0];
								dp[i % 2][j][k][1][1] = dp[1 - i % 2][j - k][x][0][1];
							}
							dp[i % 2][j][k][1][0] = min(dp[i % 2][j][k][1][0], dp[1 - i % 2][j - k][x][0][0]);
							dp[i % 2][j][k][1][1] = max(dp[i % 2][j][k][1][1], dp[1 - i % 2][j - k][x][0][1]);
							val[i % 2][j][k][1] = 1;
						}
					}
					if(val[1 - i % 2][j - k][x][1]){
						if(s[i - 1] == 'F' && k % 2 == 0 || s[i - 1] == 'T' && k % 2 == 1){
							if(!val[i % 2][j][k][1]){
								dp[i % 2][j][k][1][0] = dp[1 - i % 2][j - k][x][1][0] - 1;
								dp[i % 2][j][k][1][1] = dp[1 - i % 2][j - k][x][1][1] - 1;
							}
							dp[i % 2][j][k][1][0] = min(dp[i % 2][j][k][1][0], dp[1 - i % 2][j - k][x][1][0] - 1);
							dp[i % 2][j][k][1][1] = max(dp[i % 2][j][k][1][1], dp[1 - i % 2][j - k][x][1][1] - 1);
							val[i % 2][j][k][1] = 1;
						}
						else{
							if(!val[i % 2][j][k][0]){
								dp[i % 2][j][k][0][0] = dp[1 - i % 2][j - k][x][1][0];
								dp[i % 2][j][k][0][1] = dp[1 - i % 2][j - k][x][1][1];
							}
							dp[i % 2][j][k][0][0] = min(dp[i % 2][j][k][0][0], dp[1 - i % 2][j - k][x][1][0]);
							dp[i % 2][j][k][0][1] = max(dp[i % 2][j][k][0][1], dp[1 - i % 2][j - k][x][1][1]);
							val[i % 2][j][k][0] = 1;
						}
					}
				}
			}
		}
	}
	
	ans = 0;
	
	for(ll i = 0; i <= m; i++){
		for(ll j = 0; j < 2; j++){
			for(ll k = 0; k < 2; k++){
				if(val[n % 2][m][i][j]) ans = max(ans, abs(dp[n % 2][m][i][j][k]));
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
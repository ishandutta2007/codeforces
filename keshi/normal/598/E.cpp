#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 31;
const ll maxk = 51;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, m, c, dp[maxn][maxn][maxk];

int main(){
	fast_io;
	
	cin >> t;
	
	for(ll i = 1; i < maxn; i++){
		for(ll j = 1; j < maxn; j++){
			for(ll k = 0; k < maxk; k++){
				dp[i][j][k] = inf;
				if(k == i * j || k == 0){
					dp[i][j][k] = 0;
				}
				if(k == 0 || k >= i * j) continue;
				for(ll o = 1; o < i; o++){
					for(ll p = 0; p < k; p++){
						dp[i][j][k] = min(dp[i][j][k], j * j + dp[o][j][p] + dp[i - o][j][k - p]);
					}
				}
				for(ll o = 1; o < j; o++){
					for(ll p = 0; p < k; p++){
						dp[i][j][k] = min(dp[i][j][k], i * i + dp[i][o][p] + dp[i][j - o][k - p]);
					}
				}
			}
		}
	}
	
	while(t--){
		cin >> n >> m >> c;
		cout << dp[n][m][c] << endl;
	}
	
	return 0;
}
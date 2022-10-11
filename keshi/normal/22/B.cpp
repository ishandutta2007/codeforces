//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 30;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, ans, dp[maxn][maxn];

string s[maxn];

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i++){
		cin >> s[i];
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (s[i][j - 1] == '1');
		}
	}
	
	for(ll l = 1; l <= n; l++){
		for(ll r = l; r <= n; r++){
			for(ll u = 1; u <= m; u++){
				for(ll d = u; d <= m; d++){
					if(dp[r][d] + dp[l - 1][u - 1] - dp[r][u - 1] - dp[l - 1][d] == 0){
						ans = max(ans, 2 * (r - l + d - u + 2));
					}
				}
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
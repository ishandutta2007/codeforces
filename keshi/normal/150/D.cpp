//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 200;
const ll mod = 1e9 + 7;
const ll inf = 1e12;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, c[maxn], dp[maxn][maxn][maxn], dp2[maxn][maxn];
string s;

int main(){
    fast_io;
 
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> c[i];
		if(c[i] == -1) c[i] = -inf;
	}
	if(n == 1){
		cout << max(0ll, c[1]);
		return 0;
	}
	cin >> s;
	for(ll k = 0; k <= n; k++){
		for(ll l = 0; l < n; l++){
			dp[k][l][l] = c[k + k];
			dp[k][l][l + 1] = max(c[k + k + 1], c[1] + c[k + k]);
		}
	}
	for(ll t = 2; t <= n; t++){
		for(ll l = 0; l + t <= n; l++){
			ll r = l + t;
			for(ll k = 0; k <= min(l, n - r); k++){
				dp[k][l][r] = -inf;
				for(ll i = l + 1; i < r; i++){
					dp[k][l][r] = max(dp[k][l][r], dp[0][l][i] + dp[k][i][r]);
					dp[k][l][r] = max(dp[k][l][r], dp[k][l][i] + dp[0][i][r]);
				}
				if(k) dp[k][l][r] = max(dp[k][l][r], dp[0][l][r] + c[k + k]);
				if(s[l] == s[r - 1]){
					dp[k][l][r] = max(dp[k][l][r], dp[k + 1][l + 1][r - 1]);
				}
			}
			for(ll i = l + 1; i < r; i++){
				dp2[l][r] = max(dp2[l][r], dp2[l][i] + dp2[i][r]);
			}
			dp2[l][r] = max(dp2[l][r], dp[0][l][r]);
		}
	}
	cout << dp2[0][n];
 
    return 0;
}
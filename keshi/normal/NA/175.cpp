#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

const ll maxn = 600;
const ll mod = 1e9;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], dp[maxn][maxn];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		dp[i][i] = 1;
		if(i > 0 && a[i] == a[i - 1]){
			dp[i - 1][i] = 1;
		}
		else if(i > 0){
			dp[i - 1][i] = 2;
		}
	}
	
	for(ll i = 2; i < n; i++){
		for(ll l = 0, r = i; r < n; l++, r++){
			dp[l][r] = inf;
			if(a[l] == a[r]){
				dp[l][r] = dp[l + 1][r - 1];
			}
			for(ll k = l; k < r; k++){
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
			}
		}
	}
	
	cout << dp[0][n - 1];
	
	return 0;
}
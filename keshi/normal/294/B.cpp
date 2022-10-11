#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 110;
const ll maxm = 300;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], b[maxn], dp[maxn][maxm];

bool val[maxn][maxm];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
	}
	
	val[0][0] = 1;
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < maxm; j++){
			dp[i][j] = inf;
			if(j >= a[i] && val[i - 1][j - a[i]]){
				val[i][j] = 1;
				dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i]]);
			}
			if(val[i - 1][j]){
				val[i][j] = 1;
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + b[i]);
			}
		}
	}
	
	for(ll j = 0; j < maxm; j++){
		if(val[n][j] && dp[n][j] <= j){
			cout << j;
			return 0;
		}
	}
	
	return 0;
}
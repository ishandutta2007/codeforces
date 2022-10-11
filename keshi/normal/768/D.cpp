#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e4 + 100;
const ll maxm = 1e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const long double eps = 1e-7;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, p;

long double a, dp[maxn][maxm];

int main(){
	fast_io;
	
	cin >> k >> n;
	
	dp[1][1] = 1;
	
	for(ll i = 2; i < maxn; i++){
		for(ll j = 1; j <= k; j++){
			dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1] * (k - j + 1)) / k;
		}
	}
	
	while(n--){
		cin >> p;
		a = (p - eps) / 2000;
		for(ll i = 1; i < maxn; i++){
			if(dp[i][k] >= a){
				cout << i << endl;
				break;
			}
		}
	}
	
	return 0;
}
//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e3 + 100;
const ll maxm = 1e4 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, dp[maxn][maxn], b[maxn][maxn];

vector<ll> a;

bool p[maxm];

int main(){
	fast_io;
	
	a.pb(0);
	
	for(ll i = 2; i < maxm; i++){
		if(p[i] == 0){
			a.pb(i);
			for(ll j = i; i * j < maxm; j++){
				p[i * j] = 1;
			}
		}
	}
	
	for(ll i = 1; i < maxn; i++){
		b[i][0] = 1;
		for(ll j = 1; j < maxn; j++){
			b[i][j] = b[i][j - 1] * a[i];
			if((b[i][j] / a[i]) != b[i][j - 1]) b[i][j] = inf;
		}
	}
	
	fill(dp[0], dp[0] + maxn, inf);
	dp[0][1] = 1;
	
	for(ll i = 1; i < maxn; i++){
		for(ll j = 1; j < maxn; j++){
			dp[i][j] = inf;
			for(ll k = 1; k * k <= j; k++){
				if(j % k == 0){
					if((dp[i - 1][j / k] * b[i][k - 1]) / b[i][k - 1] == dp[i - 1][j / k]){
						dp[i][j] = min(dp[i][j], dp[i - 1][j / k] * b[i][k - 1]);
					}
					if((dp[i - 1][k] * b[i][j / k - 1]) / b[i][j / k - 1] == dp[i - 1][k]){
						dp[i][j] = min(dp[i][j], dp[i - 1][k] * b[i][j / k - 1]);
					}
				}
			}
		}
	}
	
	cin >> n;
	
	cout << dp[maxn - 1][n];
	
	return 0;
}
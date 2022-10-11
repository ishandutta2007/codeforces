//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 40;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, p[maxn], dp[maxn][maxn];

bool par[maxn][maxn];

string s, d;

int main(){
	fast_io;
	
	p[0] = 1;
	
	for(ll i = 1; i <= 18; i++){
		p[i] = p[i - 1] * 10;
	}
	
	cin >> n >> s;
	
	s = ' ' + s;
	
	for(ll i = 1; i <= 2 * n; i++){
		for(ll j = 0; j <= min(i, n); j++){
			dp[i][j] = -inf;
			if(i != j) dp[i][j] = dp[i - 1][j] + (s[i] - '0') * p[n - i + j];
			if(j){
				if(dp[i][j] < dp[i - 1][j - 1] + (s[i] - '0') * p[n - j]){
					dp[i][j] = dp[i - 1][j - 1] + (s[i] - '0') * p[n - j];
					par[i][j] = 1;
				}
			}
		}
	}
	
	ll x = n;
	
	for(ll i = 2 * n; i > 0; i--){
		if(par[i][x]){
			d = 'H' + d;
			x--;
		}
		else d = 'M' + d;
	}
	
	cout << d;
	
	return 0;
}
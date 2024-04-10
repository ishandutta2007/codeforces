//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 85;
const ll maxk = 11;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

mt19937 rng(time(0));

ll n, m, c[maxn][maxn], dp[maxk][maxn], ans;

vector<ll> a, b;

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			cin >> c[i][j];
		}
	}
	
	ans = inf;
	
	for(ll o = 0; o < 5000; o++){
		a.clear();
		b.clear();
		a.pb(0);
		for(ll i = 1; i < n; i++){
			if(rng() % 2) a.pb(i);
			else b.pb(i);
		}
		fill(dp[0] + 1, dp[0] + n, inf);
		for(ll i = 0; i < m / 2; i++){
			fill(dp[i + 1], dp[i + 1] + n, inf);
			for(ll j : a){
				for(ll k : b){
					dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + c[j][k]);
				}
			}
			for(ll j : b){
				for(ll k : a){
					dp[i + 1][k] = min(dp[i + 1][k], dp[i + 1][j] + c[j][k]);
				}
			}
		}
		ans = min(ans, dp[m / 2][0]);
	}
	
	cout << ans;
	
	return 0;
}
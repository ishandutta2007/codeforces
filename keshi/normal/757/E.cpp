//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll maxm = 20;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll q, r, n, dp[maxn][maxm], p[maxn], c, ans, x;

int main(){
	fast_io;
	
	for(ll i = 0; i < maxm; i++){
		dp[0][i] = 2;
	}
	
	for(ll i = 0; i < maxn; i++){
		dp[i][0] = 1;
	}
	
	for(ll i = 1; i < maxn; i++){
		for(ll j = 1; j < maxm; j++){
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}
	
	for(ll i = 2; i < maxn; i++){
		if(p[i] == 0){
			p[i] = i;
			for(ll j = i; i * j < maxn; j++){
				p[i * j] = i;
			}
		}
	}
	
	cin >> q;
	
	while(q--){
		cin >> r >> n;
		ans = 1;
		while(n != 1){
			x = p[n];
			c = 0;
			while(n % x == 0){
				n /= x;
				c++;
			}
			ans = (ans * dp[r][c]) % mod;
		}
		cout << ans << '\n';
	}
	
	return 0;
}
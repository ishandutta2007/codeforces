//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, h, l, r, a[maxn], dp[maxn][maxn];

int main(){
	fast_io;
	
	cin >> n >> h >> l >> r;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < h; j++){
			dp[i][j] = max(dp[i - 1][(j + a[n - i]) % h] + (l <= (j + a[n - i]) % h && (j + a[n - i]) % h <= r), dp[i - 1][(j + a[n - i] - 1) % h] + (l <= (j + a[n - i] - 1) % h && (j + a[n - i] - 1) % h <= r));
		}
	}
	
	cout << dp[n][0];
	
	return 0;
}
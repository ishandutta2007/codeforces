//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

ll t, n, m, k;
ll dp[maxn][maxn];

int main(){
	fast_io;

	ll p2 = pw(2, mod - 2);

	cin >> t;
	while(t--){
		cin >> n >> m >> k;
		for(ll i = 1; i <= n; i++){
			dp[i][0] = (i * k) % mod;
			for(ll j = 1; j <= i; j++){
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) * p2 % mod;
			}
		}
		cout << dp[n][n - m] << "\n";
	}
	
	return 0;
}
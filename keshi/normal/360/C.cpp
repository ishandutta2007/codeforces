//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2020;
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

ll n, k, dp[maxn][maxn], ps[maxn][maxn];
string s;

int main(){
	fast_io;
	
	cin >> n >> k >> s;
	s = ' ' + s;
	dp[0][0] = ps[0][0] = 1;
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j <= k; j++){
			dp[i][j] = ps[i - 1][j] * (s[i] - 'a') % mod;
			ll c = (25 - (s[i] - 'a'));
			for(ll x = i - 1; (i - x) * (n + 1 - i) <= j; x--){
				if(x < 0) break;
				dp[i][j] = (dp[i][j] + dp[x][j - (i - x) * (n + 1 - i)] * c) % mod;
			}
			ps[i][j] = (ps[i - 1][j] + dp[i][j]) % mod;
		}
	}
	cout << ps[n][k];
	
	return 0;
}
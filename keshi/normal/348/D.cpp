//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 3100;
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

ll n, m, dp1[maxn][maxn], dp2[maxn][maxn];
string s[maxn];

int main(){
    fast_io;
    
    cin >> n >> m;
    for(ll i = 0; i < n; i++){
    	cin >> s[i];
	}
	dp1[1][2] = 1;
	dp2[2][1] = 1;
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			dp1[i][j] += dp1[i - 1][j] + dp1[i][j - 1];
			dp1[i][j] %= mod;
			dp2[i][j] += dp2[i - 1][j] + dp2[i][j - 1];
			dp2[i][j] %= mod;
			if(s[i - 1][j - 1] == '#') dp1[i][j] = dp2[i][j] = 0;
		}
	}
	cout << ((dp1[n - 1][m] *  dp2[n][m - 1] - dp1[n][m - 1] * dp2[n - 1][m]) % mod + mod) % mod;
 
    return 0;
}
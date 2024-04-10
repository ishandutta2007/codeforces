//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 55;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn], c[maxn][maxn];

ld dp[maxn][maxn], t[maxn], p[maxn][maxn][maxn], ans;

int main(){
	fast_io;
	
	cout << setprecision(20) << fixed;
	
	c[0][0] = 1;
	
	for(ll i = 1; i < maxn; i++){
		c[i][0] = 1;
		for(ll j = 1; j < maxn; j++){
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	
	for(n = 0; n < maxn; n++){
		for(m = 1; m < maxn; m++){
			for(ll i = 0; i <= n; i++){
				p[n][m][i] = c[n][i];
				for(ll j = 0; j < n - i; j++){
					p[n][m][i] = (p[n][m][i] * (m - 1)) / m;
				}
				for(ll j = 0; j < i; j++){
					p[n][m][i] /= m;
				}
			}
		}
	}
	
	cin >> n >> m;
	
	for(ll i = 1; i <= m; i++){
		cin >> a[i];
	}
	
	for(ll o = 1; o < maxn; o++){
		dp[0][0] = 1;
		for(ll i = 1; i <= m; i++){
			for(ll j = 0; j <= n; j++){
				dp[i][j] = 0;
				for(ll k = 0; k <= o * a[i]; k++){
					if(k <= j) dp[i][j] += p[n - j + k][m - i + 1][k] * dp[i - 1][j - k];
				}
			}
		}
		t[o] = dp[m][n];
		ans += o * (t[o] - t[o - 1]);
	}
	
	cout << ans;
	
	return 0;
}
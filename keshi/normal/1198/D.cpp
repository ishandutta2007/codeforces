//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 55;
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

ll n, ps[maxn][maxn], dp[maxn][maxn][maxn][maxn];
string s[maxn];

inline ll get(ll u, ll d, ll l, ll r){
	return ps[d][r] - ps[u][r] - ps[d][l] + ps[u][l];
}

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = ' ' + s[i];
		for(ll j = 1; j <= n; j++){
			ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + (s[i][j] == '#');
		}
	}
	for(ll d = 1; d <= n; d++){
		for(ll r = 1; r <= n; r++){
			for(ll u = d; u--;){
				for(ll l = r; l--;){
					ll& cur = dp[u][d][l][r];
					cur = max(d - u, r - l);
					for(ll m = l + 1; m <= r; m++){
						if(get(u, d, m - 1, m) == 0) cur = min(cur, dp[u][d][l][m - 1] + dp[u][d][m][r]);
					}
					for(ll m = u + 1; m <= d; m++){
						if(get(m - 1, m, l, r) == 0) cur = min(cur, dp[u][m - 1][l][r] + dp[m][d][l][r]);
					}
				}
			}
		}
	}
	cout << dp[0][n][0][n];
	
	return 0;
}
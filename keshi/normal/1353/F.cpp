//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 5e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, m, ans, a[maxn][maxn], dp[maxn][maxn];
vector<ll> b;

int main(){
	fast_io;
	for(ll i = 2; i < maxn; i++){
		dp[0][i] = inf;
		dp[i][0] = inf;
	}
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		b.clear();
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= m; j++){
				cin >> a[i][j];
				b.pb(a[i][j] - i - j + 2);
			}
		}
		ans = inf;
		for(ll k = 0; k < b.size(); k++){
			for(ll i = 1; i <= n; i++){
				for(ll j = 1; j <= m; j++){
					dp[i][j] = inf;
					if(a[i][j] >= b[k] + i + j - 2) dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j] - (b[k] + i + j - 2);
				}
			}
			ans = min(ans, dp[n][m]);
		}
		cout << ans << '\n';
	}
	
	return 0;
}
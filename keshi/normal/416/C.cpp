#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first.first
#define S first.second

ll n, k, dp[maxn][maxn];

pll r[maxn];
pair<pll, ll> a[maxn];

bool f[maxn][maxn][2];

vector<pll> ans;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i].F >> a[i].S;
		a[i].second = i;
	}
	
	sort(a + 1, a + n + 1);
	
	cin >> k;
	
	for(ll i = 1; i <= k; i++){
		cin >> r[i].first;
		r[i].second = i;
	}
	
	sort(r + 1, r + k + 1);
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= k; j++){
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			f[i][j][0] = (dp[i - 1][j] >= dp[i][j - 1]);
			if(a[i].F <= r[j].first){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i].S);
				f[i][j][1] = (dp[i - 1][j - 1] + a[i].S >= dp[i][j]);
			}
		}
	}
	ll x = n, y = k;
	while(x > 0 && y > 0){
		if(f[x][y][1]){
			ans.pb({a[x].second, r[y].second});
			x--;
			y--;
		}
		else if(f[x][y][0]){
			x--;
		}
		else{
			y--;
		}
	}
	
	cout << ans.size() << " " << dp[n][k] << endl;
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 110;
const ll maxm = 1e4 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m[maxn], k, a[maxn][maxn], cost[maxn][maxn], dp[maxn][maxm], ps[maxn], sp[maxn], pr[maxn];

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 1; i <= n; i++){
		cin >> m[i];
		fill(ps, ps + maxn, 0);
		fill(sp, sp + maxn, 0);
		for(ll j = 1; j <= m[i]; j++){
			cin >> a[i][j];
			ps[j] = ps[j - 1] + a[i][j];
		}
		for(ll j = m[i]; j > 0; j--){
			sp[j] = sp[j + 1] + a[i][j];
		}
		for(ll j = 0; j <= m[i]; j++){
			for(ll p = 0; p <= j; p++){
				cost[i][j] = max(cost[i][j], ps[p] + sp[m[i] - j + p + 1]);
			}
		}
		pr[i] = pr[i - 1] + m[i];
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j <= pr[i]; j++){
			for(ll p = 0; (p <= m[i]) && (p <= j); p++){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - p] + cost[i][p]);
			}
		}
	}
	
	cout << dp[n][k];
	
	return 0;
}
//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxm = 210;
const ll maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, a[maxn], c[maxm][maxn], ans, l, r;

vector<ll> g[maxm];

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		for(ll i = 0; i < maxm; i++){
			g[i].clear();
		}
		for(ll i = 1; i <= n; i++){
			cin >> a[i];
			for(ll j = 1; j < maxm; j++){
				c[j][i] = c[j][i - 1];
			}
			c[a[i]][i]++;
			g[a[i]].pb(i);
		}
		ans = 1;
		for(ll i = 1; i < maxm; i++){
			for(ll k = 0; (ll)g[i].size() - 1 - k > k; k++){
				l = g[i][k];
				r = g[i][g[i].size() - 1 - k] - 1;
				for(ll j = 0; j < maxm; j++){
					ans = max(ans, (k + 1) * 2 + c[j][r] - c[j][l]);
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
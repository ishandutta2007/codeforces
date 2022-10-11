//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 110;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], m, t, d, dp[maxn][maxn];

vector<ll> v[maxn][maxn];

bool f;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= i; j++){
			if(dp[i - 1][j] > dp[i - 1][j - 1] + a[i]){
				dp[i][j] = dp[i - 1][j];
				v[i][j] = v[i - 1][j];
			}
			else if(dp[i - 1][j] < dp[i - 1][j - 1] + a[i]){
				dp[i][j] = dp[i - 1][j - 1] + a[i];
				v[i][j] = v[i - 1][j - 1];
				v[i][j].pb(a[i]);
			}
			else{
				dp[i][j] = dp[i - 1][j];
				v[i][j] = v[i - 1][j - 1];
				v[i][j].pb(a[i]);
				f = 0;
				for(ll k = 0; k < j; k++){
					if(v[i][j][k] < v[i - 1][j][k]) break;
					if(v[i][j][k] > v[i - 1][j][k]){
						f = 1;
						break;
					}
				}
				if(f){
					v[i][j] = v[i - 1][j];
				}
			}
		}
	}
	
	cin >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> t >> d;
		cout << v[n][t][d - 1] << '\n';
	}
	
	return 0;
}
//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 19;
const ll maxm = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, t;

ld p[maxn][maxn], dp[maxn][maxm], c[maxn];

int main(){
	fast_io;
	cout << setprecision(10) << fixed;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			cin >> p[i][j];
		}
	}
	
	for(ll i = 1; i < (1ll << n); i++){
		if(__builtin_popcount(i) == 1){
			dp[__builtin_ctz(i)][i] = 1;
			continue;
		}
		t = __builtin_popcount(i);
		for(ll j = 0; j < n; j++){
			c[j] = 0;
			if(!((i >> j) & 1)) continue;
			for(ll k = 0; k < n; k++){
				if((i >> k) & 1) c[j] += p[k][j];
			}
			c[j] /= t * (t - 1) / 2;
		}
		for(ll j = 0; j < n; j++){
			if(!((i >> j) & 1)) continue;
			for(ll k = 0; k < n; k++){
				if((i >> k) & 1) dp[j][i] += dp[j][i - (1ll << k)] * c[k];
			}
		}
	}
	
	for(ll i = 0; i < n; i++){
		cout << dp[i][(1ll << n) - 1] << " ";
	}
	
	return 0;
}
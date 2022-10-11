//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1100;
const ll maxd = 12;
//const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, d, mod, dp[maxn][maxn][maxd], p[maxd], dp2[maxn];

ll pw(ll pa, ll pb){
	ll pc = 1;
	while(pb){
		if(pb & 1) pc = pc * pa % mod;
		pa = pa * pa % mod;
		pb >>= 1;
	}
	return pc;
}

int main(){
    fast_io;
	cin >> n >> d >> mod;
	if(n <= 2){
		cout << 1;
		return 0;
	}
	p[0] = 1;
	for(ll i = 1; i < maxd; i++){
		p[i] = pw(i, mod - 2);
	}
	dp2[1] = 1;
	for(ll j = 0; j < maxn; j++){
		dp[1][j][0] = 1;
	}
	for(ll i = 2; i <= n; i++){
		for(ll o = 1; o <= i; o++){
			ll x = 1;
			for(ll k = 0; k <= d && o * k <= i; k++){
				for(ll j = k; j <= d; j++){
					dp[i][o][j] = (dp[i][o][j] + dp[i - o * k][min(o - 1, i - o * k)][j - k] * x) % mod;
				}
				x = x * (dp2[o] + k) % mod * p[k + 1] % mod;
			}
		}
		dp2[i] = dp[i][i][d - 1];
	}
	cout << (dp[n][(n - 1) / 2][d] + (n & 1 ? 0 : dp2[n / 2] * (dp2[n / 2] + 1) % mod * p[2] % mod)) % mod;

    return 0;
}
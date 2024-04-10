//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 60;
const ll maxm = 5000;
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

ll n, dp[maxn][maxn], p[maxm], pp[maxm], dp2[maxn][maxn];

ll cal(ll x){
	string s;
	dp2[0][0] = 1;
	if(x == 0) return -1;
	while(x > 1){
		s += char('0' + (x & 1));
		x >>= 1;
	}
	reverse(all(s));
	for(ll i = 1; i <= Sz(s); i++){
		for(ll j = 0; j <= i; j++){
			dp2[i][j] = 0;
			if(s[i - 1] == '0'){
				dp2[i][j] += dp2[i - 1][j] * p[j];
			}
			else{
				dp2[i][j] += dp2[i - 1][j - 1] + dp2[i - 1][j] * p[j];
			}
			dp2[i][j] %= mod;
		}
	}
	return Sz(s);
}

int main(){
    fast_io;
	p[0] = 1;
	pp[0] = 1;
	for(ll i = 1; i < maxm; i++){
		p[i] = p[i - 1] * 2 % mod;
		pp[i] = pp[i - 1] * ((mod + 1) / 2) % mod;
	}
	dp[0][0] = 1;
	for(ll i = 1; i + 1 < maxn; i++){
		for(ll j = 0; j <= i; j++){
			dp[i][j] = dp[i - 1][j] * p[j];
			if(j) dp[i][j] += 2 * dp[i - 1][j - 1];
			dp[i][j] %= mod;
		}
	}
	cin >> n;
	n++;
	ll ans = 0;
	for(ll i = 0; i < maxn; i++){
		if(((n >> i) & 1) == 0) continue;
		ll m = cal((n >> i) - 1);
		if(m == -1){
			for(ll j = 0; j <= i; j++){
				ans = (ans + dp[i][j] * pp[j]) % mod;
			}
			continue;
		}
		for(ll j = 0; j <= i; j++){
			for(ll k = 0; k <= m; k++){
				ans = (ans + dp[i][j] * p[j * k] % mod * dp2[m][k]) % mod;
			}
		}
	}
	cout << ans;

    return 0;
}
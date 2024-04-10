//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 710;
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

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

ll n, dp[10][maxn][maxn], pd[10][maxn], cnt[12], pnt[12], p[maxn], ans;
string s;

int main(){
	fast_io;
	p[0] = 1;
	for(ll i = 1; i < maxn; i++){
		p[i] = p[i - 1] * 10 % mod;
	}
	
	cin >> s;
	n = Sz(s);
	ll pt = n - 1;
	while(pt >= 0 && s[pt] == '9'){
		s[pt] = '0';
		pt--;
	}
	if(pt == -1){
		s = "1" + s;
		n = Sz(s);
		cout << s << "\n";
	}
	else s[pt]++;
	for(ll t = 0; t < 10; t++){
		ll p1 = (10 - t - 1) * pw(10, mod - 2) % mod, p2 = (t + 1) * pw(10, mod - 2) % mod;
		dp[t][0][0] = 1;
		for(ll i = 1; i <= n; i++){
			dp[t][i][0] = dp[t][i - 1][0] * p2 % mod;
			for(ll j = 1; j <= i; j++){
				dp[t][i][j] = (dp[t][i - 1][j] * p2 + dp[t][i - 1][j - 1] * p1) % mod;
			}
		}
	}
	for(ll t = 0; t < 10; t++){
		ll p1 = pw(t + 1, mod - 2);
		ll p2 = t * p1 % mod;
		pd[t][0] = 0;
		for(ll i = 1; i <= n; i++){
			pd[t][i] = (p2 * pd[t][i - 1] + p1 * ((pd[t][i - 1] * 10 + t) % mod)) % mod;
		}
	}
	for(ll i = 0; i < n; i++){
		ll x = (s[i] - '0');
		for(ll y = 0; y < x; y++){
			cnt[y]++;
			pnt[y] = (pnt[y] * 10 + y) % mod;
			ll e = 0;
			ll c = 0;
			for(ll t = 9; t >= 0; t--){
				for(ll j = 0; j <= n - i - 1; j++){
					e += (pd[t][n - i - 1 - j] * p[cnt[t]] % mod + pnt[t]) % mod * dp[t][n - i - 1][j] % mod * p[j + c] % mod;
					e %= mod;
				}
				c += cnt[t];
			}
			ans = (ans + e * p[n - i - 1]) % mod;
			cnt[y]--;
			pnt[y] = (pnt[y] - y) * pw(10, mod - 2) % mod;
		}
		cnt[x]++;
		pnt[x] = (pnt[x] * 10 + x) % mod;
	}
	cout << (ans + mod) % mod;
	
	
	return 0;
}
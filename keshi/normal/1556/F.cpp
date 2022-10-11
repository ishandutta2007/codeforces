//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 20;
const ll maxm = 5e6;
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

ll n, a[maxn], b[maxn], dp[maxm], p[maxn][maxn], ans;
vector<ll> v1, v2;

int main(){
	fast_io;
	
	cin >> n;
	ll t = 1;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		t *= 3;
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			p[i][j] = a[i] * pw(a[i] + a[j], mod - 2) % mod;
		}
	}
	for(ll i = 1; i < t; i++){
		ll x = i;
		v1.clear();
		v2.clear();
		for(ll j = 0; j < n; j++){
			b[j] = x % 3;
			if(b[j] == 1) v1.pb(j + 1);
			if(b[j] == 2) v2.pb(j + 1);
			x /= 3;
		}
		ll y = 0;
		ll z = 0;
		for(ll j = n; j--;){
			y *= 3;
			z *= 3;
			if(b[j]) y += 2;
			if(b[j] == 2) z += 2;
		}
		if(v2.empty()) continue;
		if(v1.empty()){
			dp[y] = (dp[y] + 1) % mod;
			continue;
		}
		ll s = dp[z];
		for(ll j : v1){
			for(ll k : v2){
				s = s * p[k][j] % mod;
			}
		}
		dp[y] = (dp[y] - s) % mod;
		if(y == t - 1){
			ans = (ans + Sz(v2) * s) % mod;
		}
	}
	ans = (ans + n * dp[t - 1]) % mod;
	cout << (ans + mod) % mod;
	
	return 0;
}
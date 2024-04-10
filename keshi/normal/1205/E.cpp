//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
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

ll n, k, p[maxn], dp[maxn], ans;
vector<ll> g[maxn];

int main(){
    fast_io;
	for(ll i = 0; i < maxn; i++){
		g[i].reserve(10);
	}
	for(ll i = maxn - 1; i > 0; i--){
		for(ll j = i; j < maxn; j += i){
			g[j].pb(i);
		}
	}

	cin >> n >> k;
	p[0] = 1;
	for(ll i = 1; i < maxn; i++){
		p[i] = p[i - 1] * k % mod;
	}
	for(ll s = 2; s <= n + n - 2; s++){
		 ll l = max(0ll, s - n);
		 ll r = min(s - 1, n - 1);
		 for(ll i : g[s]){
			 dp[i] = 0;
		 }
		 for(ll i : g[s]){
			 dp[i] += r / i - l / i;
			 ans = (ans + dp[i] * p[max(i, s - n)]) % mod;
			 for(ll j : g[i]){
				 if(i != j) dp[j] -= dp[i];
			 }
		 }
	}
	cout << ans * pw(p[n], mod - 2) % mod;

    return 0;
}
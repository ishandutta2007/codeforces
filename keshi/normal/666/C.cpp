//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 100;
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

ll n, q, dp[maxn], p[maxn], ans[maxn];
string s;
vector<pll> vec[maxn];

int main(){
    fast_io;
    
    for(ll i = 1; i < maxn; i++){
    	p[i] = pw(i, mod - 2);
	}
    
    cin >> q >> s;
    while(q--){
    	ll t, x;
    	cin >> t;
    	if(t == 1){
    		cin >> s;		
		}
		else{
			cin >> x;
			vec[Sz(s)].pb(Mp(x, n++));
		}
	}
	for(ll t = 1; t < maxn; t++){
		if(vec[t].empty()) continue;
		fill(dp, dp + t, 0);
		ll c = 1;
		for(ll i = t; i < maxn; i++){
			dp[i] = (dp[i - 1] * 26 + c) % mod;
			c = c * i % mod * p[i + 1 - t] % mod;
			c = c * 25 % mod;
		}
		for(pll i : vec[t]){
			ans[i.S] = dp[i.F];
		}
	}
	for(ll i = 0; i < n; i++){
		cout << ans[i] << "\n";
	}
 
    return 0;
}
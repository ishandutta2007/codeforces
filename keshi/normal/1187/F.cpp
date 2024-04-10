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

ll n, l[maxn], r[maxn], ans, p[maxn], pp[maxn], ps;

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 0; i < n; i++){
    	cin >> l[i];
	}
	for(ll i = 0; i < n; i++){
		cin >> r[i];
		r[i]++;
		p[i] = pw(r[i] - l[i], mod - 2);
	}
	ans = n * n;
	for(ll i = 0; i + 1 < n; i++){
		pp[i] = (max(0ll, min(r[i], r[i + 1]) - max(l[i], l[i + 1]))) * p[i] % mod * p[i + 1] % mod;
		ans = (ans - (2 * n - 1) * pp[i]) % mod;
	}
	for(ll i = 0; i + 2 < n; i++){
		ans = (ans + 2 * max(0ll, min({r[i], r[i + 1], r[i + 2]}) - max({l[i], l[i + 1], l[i + 2]})) * p[i] % mod * p[i + 1] % mod * p[i + 2]) % mod;
	}
	for(ll i = n - 4; i >= 0; i--){
		ps = (ps + pp[i + 2]) % mod;
		ans = (ans + pp[i] * ps * 2) % mod;
	}
	cout << (ans + mod) % mod;
 
    return 0;
}
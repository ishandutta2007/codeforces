//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 998244353;
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

ll n, x, c, o1, o2;

ll C(ll a, ll b){
	if(b > a) return 0;
	if(b < 0) return 0;
	ll c = 1;
	for(ll i = 0; i < b; i++){
		c = c * (a - i) % mod;
		c = c * pw(i + 1, mod - 2) % mod;
	}
	return c;
}

int main(){
	fast_io;
	
	cin >> n;
	ll t = 1;
	for(ll i = 0; i < n; i++){
		string s;
		cin >> s;
		if(s[0] == 'W' || s[1] == 'B') o1 = 1;
		if(s[0] == 'B' || s[1] == 'W') o2 = 1;
		if(s == "BB" || s == "WW") t = 0;
		if(s == "WB" || s == "BW") continue;
		if(s == "??"){
			x += 2;
			c++;
			t = t * 2 % mod;
			continue;
		}
		ll j = 0;
		if(s[0] == '?') j = 1;
		if(s[1 - j] == 'B'){
			c--;
			continue;
		}
		if(s[1 - j] == 'W'){
			c++;
			continue;
		}
		if(s[j] == 'B'){
			x++;
		}
		else{
			x++;
			c++;
		}
	}
	t -= 1 - o1;
	t -= 1 - o2;
	cout << ((C(x, c) - t) % mod + mod) % mod << "\n";
	
	return 0;
}
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

ll q, n;
string s;

int main(){
	fast_io;
	
	cin >> q;
	while(q--){
		cin >> n >> s;
		ll x = n;
		for(ll i = 0; i + 1 < n; i++){
			if(s[i] < s[i + 1]){
				x = i + 1;
				break;
			}
		}
		if(n > 1 && s[0] == s[1]){
			x = 1;
		}
		for(ll i = 0; i < x; i++){
			cout << s[i];
		}
		for(ll i = x; i--;){
			cout << s[i];
		}
		cout << "\n";
	}
	
	return 0;
}
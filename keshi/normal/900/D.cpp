//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, dp[maxn];

vector<ll> a;

ll pw(ll x, ll y){
	if(y == 0) return 1;
	ll z = pw(x, y / 2);
	z = (z * z) % mod;
	if(y % 2) z = (x * z) % mod;
	return z;
}

int main(){
	ll x, y;
	fast_io;
	
	cin >> x >> y;
	
	if(y % x){
		cout << 0;
		return 0;
	}
	
	n = y / x;
	
	for(ll i = 1; i * i <= n; i++){
		if(n % i == 0){
			a.pb(i);
			if(i != n / i) a.pb(n / i);
		}
	}
	
	sort(a.begin(), a.end());
	
	for(ll i = 0; i < a.size(); i++){
		dp[i] = pw(2, a[i] - 1);
		for(ll j = 0; j < i; j++){
			if(a[i] % a[j] == 0) dp[i] = (dp[i] - dp[j]) % mod;
		}
	}
	
	cout << (dp[a.size() - 1] + mod) % mod;
	
	return 0;
}
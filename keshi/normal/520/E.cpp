//In the name of GOD
//Hello Yellow
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

ll n, ans, k, e, f[maxn], p[maxn];

string s;

ll powlog(ll a, ll b){
	if(b == 0) return 1;
	ll x = powlog(a, b / 2);
	if(b % 2) return (((x * x) % mod) * a) % mod;
	return (x * x) % mod;
}

ll inv(ll x){
	return powlog(x, mod - 2);
}

ll c(ll a, ll b){
	//cout << a << " " << b << " => ";
	if(b > a || b < 0){
		//cout << 0 << endl;
		return 0;
	}
	//cout << (((f[a] * inv(f[b])) % mod) * inv(f[a - b])) % mod << endl;
	return (((f[a] * inv(f[b])) % mod) * inv(f[a - b])) % mod;
}

int main(){
	fast_io;
	
	f[0] = 1;
	p[0] = 1;
	
	for(ll i = 1; i < maxn; i++){
		f[i] = (f[i - 1] * i) % mod;
		p[i] = (p[i - 1] * 10) % mod;
	}
	
	cin >> n >> k >> s;
	
	for(ll i = 0; i < n - 1; i++){
		e += (p[i] * c(n - i - 2, k - 1)) % mod;
		e %= mod;
	}
	e += (p[n - 1] * c(0, k)) % mod;
	e %= mod;
	
	ans = (e * (s[0] - '0')) % mod;
	
	for(ll i = 1; i < n; i++){
		e += p[n - i - 1] * (c(i, k) - c(i - 1, k - 1)) % mod - p[n - i] * c(i - 1, k) % mod;
		e %= mod;
		ans += (e * (s[i] - '0')) % mod;
		ans %= mod;
	}
	
	cout << (ans + mod) % mod;
	
	return 0;
}
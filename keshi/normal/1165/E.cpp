//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], b[maxn], c[maxn], ans;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		c[i] = (i + 1) * (n - i) * a[i];
	}
	
	for(ll i = 0; i < n; i++){
		cin >> b[i];
	}
	
	sort(c, c + n, greater<ll>());
	sort(b, b + n);
	
	for(ll i = 0; i < n; i++){
		c[i] %= mod;
		ans = (ans + b[i] * c[i]) % mod;
	}
	
	cout << ans;
	
	return 0;
}
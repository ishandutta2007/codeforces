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

ll n, x, ans;

int main(){
	fast_io;
	
	cin >> n;
	
	x = 1;
	
	for(ll i = 1; i < n; i++){
		x = (x * (n - i + 1)) % mod;
		ans = (ans - x + mod * 5) % mod;
	}
	
	cout << (ans + x * n) % mod;
	
	return 0;
}
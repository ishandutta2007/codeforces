//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, f[maxn];

int main(){
	ll v, u, w;
	fast_io;
	
	cin >> n >> m;
	
	f[0] = 1;
	f[1] = 1;
	
	for(ll i = 2; i < maxn; i++){
		f[i] = (f[i - 1] + f[i - 2]) % mod;
	}
	
	cout << (2 * (f[n] + f[m] - 1)) % mod;
	
	return 0;
}
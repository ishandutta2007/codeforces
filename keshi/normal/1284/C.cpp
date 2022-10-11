//In the name of GOD
//Hello 2020
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, f[maxn], ans;

int main(){
	fast_io;
	
	f[0] = 1;
	
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i++){
		f[i] = (i * f[i - 1]) % m;
	}
	
	for(ll i = 1; i <= n; i++){
		ans = (ans + (((((n - i + 1) * (n - i + 1) % m) * f[i]) % m) * f[n - i]) % m) % m;
	}
	
	cout << ans;
	
	return 0;
}
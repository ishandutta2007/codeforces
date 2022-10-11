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

ll n, k, ans, a[maxn];

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = k - a[i];
	}
	
	ans = 1;
	
	for(ll i = 0; i <= n; i++){
		if(a[i] == a[i + 1]) ans = (ans * (a[i] + 1)) % mod;
		else if(a[i] == a[i + 1] + 1) ans = (ans * a[i]) % mod;
		else if(a[i] != a[i + 1] - 1) ans = 0;
	}
	
	cout << ans;
	
	return 0;
}
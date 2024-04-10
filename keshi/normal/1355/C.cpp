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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll a, b, c, d, ans;

int main(){
	fast_io;
	
	cin >> a >> b >> c >> d;
	
	for(ll i = a; i <= b; i++){
		ll j = c - i + 1;
		j = max(j, b);
		if(j > c) continue;
		ll k = i + j - 1;
		k = min(k, d);
		if(c - j <= d - k){
			ans += (k - j + 2) * (k - j + 1) / 2  - (k - c + 1) * (k - c) / 2;
		}
		else{
			ans += (d - c + 2) * (d - c + 1) / 2 - (k - c) * (k - c + 1) / 2;
			ans += (d - c + 1) * (c + k - d - j);
		}
	}
	
	cout << ans;
	
	return 0;
}
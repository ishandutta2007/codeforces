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

ll t, n, a;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		a = (1ll << n);
		for(ll i = 1; i < n / 2; i++){
			a += (1ll << i);
		}
		for(ll i = n / 2; i < n; i++){
			a -= (1ll << i);
		}
		cout << a << '\n';
	}
	
	return 0;
}
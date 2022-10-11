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

ll t, l, r, m, x;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> l >> r >> m;
		for(ll i = l; i <= r; i++){
			x = m % i;
			if(l + x <= r && m != x){
				cout << i << " " << l + x << " " << l << '\n';
				break;
			}
			x = abs(x - i);
			if(l + x <= r){
				cout << i << " " << r - x << " " << r << '\n';
				break;
			}
		}
	}
	
	return 0;
}
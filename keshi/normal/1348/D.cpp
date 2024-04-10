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

ll t, n, x, s, l, r, mid;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		x = -1;
		for(ll i = 1; i < 32; i++){
			if(n >= i && (1ll << i) > n){
				x = i - 1;
				break;
			}
		}
		s = 1;
		n -= x + 1;
		cout << x << '\n';
		for(ll i = 0; i < x; i++){
			l = 0, r = s + 1;
			while(r - l > 1){
				mid = (l + r) / 2;
				if(n >= mid * (x - i)) l = mid;
				else r = mid;
			}
			n -= l * (x - i);
			s += l;
			cout << l << " ";
		}
		cout << '\n';
	}
	
	return 0;
}
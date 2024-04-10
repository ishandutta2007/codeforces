//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, n, a[maxn], c[maxn], mx;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			c[a[i]]++;
		}
		mx = -inf;
		for(ll i = 0; i <= 2 * n; i++){
			ll x = 0;
			for(ll j = 0; j < i - j; j++){
				x += min(c[j], c[i - j]);
			}
			if(i % 2 == 0) x += c[i / 2] / 2;
			mx = max(x, mx);
		}
		cout << mx << '\n';
		for(ll i = 0; i < n; i++){
			c[a[i]] = 0;
		}
	}
	
	return 0;
}
//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, a[maxn], b[maxn];

bool solve(){
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	for(ll i = 0; i < n; i++){
		cin >> b[i];
	}
	ll x = b[n - 1];
	ll y = 0, t = 0;
	for(ll i = 0; i < n - 1; i++){
		if(a[i] - y > b[i]){
			if(x < a[i] - y - b[i]) return 0;
			x -= a[i] - y - b[i];
			t += a[i] - y - b[i];
			y = a[i] - b[i];
		}
		x = min(x, a[i] - y);
		y = b[i] - max(0, a[i] - y);
	}
	return (y + b[n - 1] - t >= a[n - 1]);
}

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cout << (solve() ? "YES\n" : "NO\n");
	}
	
	return 0;
}
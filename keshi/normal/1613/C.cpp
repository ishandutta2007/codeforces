//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll t, n, h, a[maxn];

ll cal(ll k){
	ll x = 0;
	for(ll i = 0; i + 1 < n; i++){
		x += min(k, a[i + 1] - a[i]);
		if(x > inf) return x;
	}
	x += k;
	return x;
}

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> h;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		ll l = 0, r = h;
		while(r - l > 1){
			ll mid = (l + r) >> 1;
			if(cal(mid) >= h) r = mid;
			else l = mid;
		}
		cout << r << "\n";
	}
	
	return 0;
}
//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 120;
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

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

ll q, n, a[maxn], c[maxn];

int main(){
	fast_io;
	
	cin >> q;
	while(q--){
		fill(c, c + maxn, 0);
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			c[abs(a[i])]++;
		}
		ll ans = 0;
		for(ll i = 1; i < maxn; i++){
			ans += min(2ll, c[i]);
		}
		if(c[0]) ans++;
		cout << ans << "\n";
	}	
	
	return 0;
}
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

ll t, n, a[maxn], b[maxn];

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			ll x = a[i];
			b[i] = 0;
			while(x % 2 == 0){
				b[i]++;
				x >>= 1;
			}
		}
		ll ans = 0;
		for(ll i = 0; i < n; i++){
			ll c = 0;
			ll s = 0;
			for(ll j = 0; j < n; j++){
				if(i == j) continue;
				c += b[j];
				s += (a[j] >> b[j]);
			}
			ans = max(ans, s + (a[i] << c));
		}
		cout << ans << "\n";
	}
	
	return 0;
}
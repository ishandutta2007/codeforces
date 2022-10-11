//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;
const ll lg = 60;
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

ll t, n, a[maxn], c[maxn], p[maxn];

int main(){
    fast_io;

	for(ll i = 0; i < lg; i++){
		p[i] = (1ll << i) % mod;
	}

	cin >> t;
	while(t--){
		cin >> n;
		fill(c, c + lg, 0);
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			for(ll j = 0; j < lg; j++){
				if((a[i] >> j) & 1) c[j]++;
			}
		}
		ll ans = 0;
		for(ll i = 0; i < n; i++){
			ll d1 = 0, d2 = 0;
			for(ll j = 0; j < lg; j++){
				if((a[i] >> j) & 1){
					d1 = (d1 + p[j] * c[j]) % mod;
					d2 = (d2 + p[j] * n) % mod;
				}
				else{
					d2 = (d2 + p[j] * c[j]) % mod;
				}
			}
			ans = (ans + d1 * d2) % mod;
		}
		cout << ans << "\n";
	}

    return 0;
}
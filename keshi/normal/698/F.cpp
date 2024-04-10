//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
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

ll n, a[maxn], p[maxn], b[maxn], c[maxn], c2[maxn], f[maxn], par[maxn];

int main(){
	fast_io;
	
	f[0] = 1;
	for(ll i = 1; i < maxn; i++){
		f[i] = f[i - 1] * i % mod;
	}
	
	fill(b, b + maxn, 1);
	
    cin >> n;
    for(ll i = 2; i <= n; i++){
    	if(p[i]) continue;
    	c2[n / i]++;
    	for(ll j = i; j <= n; j += i){
    		p[j] = i;
    		b[j] *= i;
		}
		if(2 * i > n) b[i] = 1;
	}
	for(ll i = 1; i <= n; i++){
		c[b[i]]++;
	}
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == 0) continue;
		if(b[a[i]] == b[i]){
			c[b[i]]--;
			if(b[i] == 1) continue;
			if(p[i] * p[i] <= n) continue;
			if(par[p[i]] && par[p[i]] != p[i]){
				cout << 0;
				return 0;
			}
			if(!par[p[i]]){
				c2[n / p[i]]--;
				par[p[i]] = p[i];
			}
		}
		else{
			if(b[i] == 1 || b[a[i]] == 1){
				cout << 0;
				return 0;
			}
			if(p[i] * p[i] <= n || p[a[i]] * p[a[i]] <= n){
				cout << 0;
				return 0;
			}
			if(n / p[i] != n / p[a[i]] || b[i / p[i]] != b[a[i] / p[a[i]]]){
				cout << 0;
				return 0;
			}
			if(par[p[a[i]]] && par[p[a[i]]] != p[i]){
				cout << 0;
				return 0;
			}
			if(!par[p[a[i]]]){
				c2[n / p[a[i]]]--;
				par[p[a[i]]] = p[i];
			}
			c[b[i]]--;
		}
	}
	
	ll ans = 1;
	for(ll i = 1; i <= n; i++){
		ans = ans * f[c[i]] % mod;
	}
	for(ll i = 2; i <= n; i++){
		ans = ans * f[c2[i]] % mod;
	}
	cout << ans;
	
    return 0;
}
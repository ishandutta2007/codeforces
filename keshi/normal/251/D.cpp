//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 4e5 + 100;
const ll maxm = 8e6 + 100;
const ll lg = 63;
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

ll n, t, a[maxn], basis[lg], b[maxn], xa, ba[lg], b2[lg], c[maxm];
bool vis[maxn];
pll g[maxm];

int main(){
    fast_io;

	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		xa ^= a[i];
		b[i] = i;
	}
	t = n;
	for(ll j = lg; j--;){
		basis[j] = -1;
		for(ll i = 0; i < n; i++){
			if(!vis[i] && ((a[i] >> j) & 1)){
				basis[j] = i;
			}
		}
		if(basis[j] == -1) continue;
		vis[basis[j]] = 1;
		for(ll i = 0; i < n; i++){
			if(i != basis[j] && ((a[i] >> j) & 1)){
				g[t].F = b[i];
				g[t].S = b[basis[j]];
				b[i] = t++;
				a[i] ^= a[basis[j]];
			}
		}
	}
	for(ll i = 0; i < lg; i++){
		if(basis[i] != -1){
			ba[i] = a[basis[i]];
		}
	}
	ll y = 0;
	for(ll j = lg; j--;){
		if((xa >> j) & 1) continue;
		ll x = 0;
		for(ll i = 0; i < lg; i++){
			if((ba[i] >> j) & 1) x += (1ll << i);
		}
		x = x * 2 + 1;
		for(ll i = lg; i--;){
			if(((x >> i) & 1) == 0) continue;
			if(b2[i] == 0){
				b2[i] = x;
				break;
			}
			x ^= b2[i];
		}
		if(b2[0] == 0){
			y += (1ll << j);
		}
		b2[0] = 0;
	}
	for(ll j = lg; j--;){
		if(((xa >> j) & 1) == 0) continue;
		ll x = 0;
		for(ll i = 0; i < lg; i++){
			if((ba[i] >> j) & 1) x += (1ll << i);
		}
		x = x * 2;
		for(ll i = lg; i--;){
			if(((x >> i) & 1) == 0) continue;
			if(b2[i] == 0){
				b2[i] = x;
				break;
			}
			x ^= b2[i];
		}
		if(b2[0]){
			y += (1ll << j);
		}
		b2[0] = 0;
	}
	for(ll i = 0; i < lg; i++){
		if(basis[i] != -1 && ((y >> i) & 1)){
			c[b[basis[i]]]++;
		}
	}
	for(ll i = t; i >= n; i--){
		c[g[i].F] += c[i];
		c[g[i].S] += c[i];
	}
	for(ll i = 0; i < n; i++){
		cout << 2 - (c[i] & 1) << " ";
	}


    return 0;
}
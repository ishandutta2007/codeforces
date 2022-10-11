//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn], b[maxn], r[maxn], mn[maxn];
map<ll, ll> mp;

int main(){
	fast_io;
	
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(ll i = 1; i <= m; i++){
		cin >> b[i];
		mp[b[i]] = i;
	}
	for(ll i = 1; i <= n; i++){
		r[mp[a[i]]] = i;
	}
	if(r[m] == 0){
		cout << 0;
		return 0;
	}
	for(ll i = 1; i < m; i++){
		if(r[i] == 0 || r[i] > r[i + 1]){
			cout << 0;
			return 0;
		}
	}
	mn[n + 1] = inf;
	for(ll i = n; i > 0; i--){
		mn[i] = min(mn[i + 1], a[i]);
	}
	ll s, sp = 1;
	for(ll i = m; i > 1; i--){
		s = 0;
		for(ll j = r[i]; j > r[i - 1]; j--){
			if(mn[j] == b[i]) s = (s + sp) % mod;
		}
		sp = s;
	}
	if(mn[1] != b[1]) sp = 0;
	cout << sp;
	
	return 0;
}
#ifndef __PROGTEST__
#include <bits/stdc++.h>
using namespace std;
#endif // __PROGTEST__

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define ff first
#define ss second
#define vec vector
#define all(x) (x).begin(), (x).end()
#define inf 9223372036854775807
#define mod 998244353
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);
ll nxt() {ll x; cin >> x; return x;}


void solve(){
	ll n = nxt(), m = nxt();
	vec<vec<ll>> vals(n);
	for (ll i = 0; i < n; ++i){
		vals[i].resize(m);
		for (ll j = 0; j < m; ++j){
			vals[i][j] = nxt();
		}
	}
	ll r = 0;
	for (ll i = 0; i < m; ++i){
		vec<ll> g(n);
		ll gcnt = 0;
		for (ll j = 0; j < n; ++j){
			if ((vals[j][i] - 1 - i) >= 0 && (vals[j][i] - 1 - i) % m == 0 && vals[j][i] <= m*n)
				++g[(n + j - (vals[j][i] - 1 - i) / m)%n];			
		}
		ll mn = inf;
		for (ll j = 0; j < n; ++j)
			mn = min(mn, j + n - g[j]);
		r += mn;
	}
	cout << r << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t = 1;
	// cin >> t;
	for (ll i = 1; i < t+1; ++i){ 
		solve();
	}
}
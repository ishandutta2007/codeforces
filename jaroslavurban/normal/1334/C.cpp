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
#define endl '\n'
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
	ll n = nxt();
	vec<pair<ll,ll>> m;
	for (ll i = 0; i < n; ++i)
		m.push_back({nxt(), nxt()});
	vec<ll> over(n);
	ll sm = 0;
	for (ll i = 0; i < n; ++i){
		over[i] = max(0ll, m[i].ff - m[(i-1+n)%n].ss);
		sm += over[i];
	}
	ll mn = inf;
	for (ll i = 0; i < n; ++i)
		mn = min(mn, sm - over[i] + m[i].ff);
	cout << mn << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t = 1;
	cin >> t;
	for (ll i = 1; i < t+1; ++i){ 
		solve();
	}
}
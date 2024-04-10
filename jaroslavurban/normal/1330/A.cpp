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
	ll n =nxt(), x = nxt();
	vec<ll> places(n);
	generate(all(places), nxt);
	sort(all(places));
	unique(all(places));
	ll i = 0;
	while (1){
		if (i >= (ll)places.size() || places[i] != i+1){
			if (x == 0) break;
			places.insert(places.begin() + i, i);
			--x;
		}
		++i;
	}
	cout << i << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t = 1;
	cin >> t;
	while (t--) solve();
}
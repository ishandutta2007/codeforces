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
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use generate(all(vec), nxt) for filling a vector with function calls
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// vec to a set -> use "set s(all(vec));"
// is key in a set/map? use s.count(key)
// ll pos = partition_point(all(vec), p) - vec.begin();
// print number in binary -> cout << bitset<20>(n);
// use min({a, b, c})
// use reverse(str.begin(), str.end()) to reverse a string
ll nxt() {ll x; cin >> x; return x;}

void solve(){
	ll n = nxt(), m = nxt(), k = nxt();
	cout << n + m + n*m - 3 << endl;
	for (ll i = 0; i < n-1; ++i)
		cout << "D";
	for (ll i = 0; i < m-1; ++i)
		cout << "L";
	for (ll i = 0; i < n; ++i){
		for (ll j = 0; j < m-1; ++j){
			if (i%2) cout << "L";
			else cout << "R";
		}
		if (i!=n-1) cout << "U";
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t = 1;
	// cin >> t;
	while (t--) solve();
}
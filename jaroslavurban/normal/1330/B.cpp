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

bool sn[200020];
bool l[200020];
bool r[200020];

void solve(){
	ll n = nxt();
	for (ll i = 0; i < n; ++i)
		sn[i] = l[i] = r[i] = false;
	vec<ll> a(n);
	generate(all(a), nxt);
	ll sum = 0;
	for (ll i = 0; i < n; ++i){
		if (sn[a[i]]) break;
		sn[a[i]] = true;
		sum += a[i];
		l[i] = (i+1)*(i+2)/2 == sum;
	}
	for (ll i = 0; i < n; ++i) sn[i] = false;
	sum = 0;
	for (ll i = 0; i < n; ++i){
		if (sn[a[n-i-1]]) break; 
		sn[a[n-i-1]] = true;
		sum += a[n-i-1];
		r[n-i-1] = (i+1)*(i+2)/2 == sum;
	}
	ll cnt = 0;
	for (ll i = 0; i < n-1; ++i) cnt += l[i] && r[i+1];
	cout << cnt << endl;
	for (ll i = 0; i < n-1; ++i)
		if (l[i] && r[i+1])
			cout << i+1 << " " << n-i-1 << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t = 1;
	cin >> t;
	while (t--) solve();
}
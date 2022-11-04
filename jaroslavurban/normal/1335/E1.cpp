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
// #define endl '\n'
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);
ll nxt() {ll x; cin >> x; return x;}

int nat[27][2020];

void solve(){
	ll n = nxt();
	vec<ll> nums(n);
	generate(all(nums), nxt);
	for (ll j = 0; j < 27; ++j)
		nat[j][0] = nums[0] == j;
	for (ll i = 1; i < n; ++i)
		for (ll j = 1; j < 27; ++j)
			nat[j][i] = (nat[j][i-1] + (nums[i] == j));
	ll res = 0;
	for (ll i = 1; i < 27; ++i){
		ll l = 0, r = n-1;
		ll cnt = 0;
		while (l <= r){
			while (l < n && nums[l] != i) ++l;
			if (l == n) break;
			// cout << nums.size() << endl;
			while (r >= 0 && nums[r] != i) --r;
			if (l > r) break;
			cnt += 1 + (l != r);
			// cout << cnt <<" " << i << " "<< res <<  endl;
			res = max(res, cnt);
			for (ll j = 1; j < 27; ++j){
				if (j != i) res = max(res, cnt + nat[j][r] - nat[j][l]);
			}
			++l; --r;
		}
	}
	cout << res << endl;
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
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<17, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll cb(ll x) {return x*x*x;}
array<ll, 2> up(array<ll, 2> a, ll b) {return {a[0]+1, a[1]+b};}
map<ll, array<ll, 2>> memo;
array<ll, 2> solve(ll m) {
	if(memo.count(m)) return memo[m];
	if(m < 0) return {-100, -100};
	if(m == 0) return {0, 0};
	ll bc = 0;
	while(cb(bc+1) <= m) bc++;
	array<ll, 2> ans = {0, 0};
	for(auto i : {bc, bc-1}) {
		ans = max(up(solve(min(cb(i+1)-1-cb(i), m - cb(i))), cb(i)), ans);
	}
	return memo[m] = ans;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	ll m;
	cin >> m;
	auto f = solve(m);
	cout << f[0] << " " << f[1] << endl;
}
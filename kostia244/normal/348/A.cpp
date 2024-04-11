#pragma GCC optimize("trapv")
#pragma GCC target("avx,avx2,ssse3,sse2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pair<int, int>>;
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n;
vi a;
bool check(ll x) {
	ll u = 0;
	for(auto i : a) {
		if(x<i) return false;
	}
	for(auto i : a) {
		u += x-i;
		if(u>=x) break;
	}
	return u>=x;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	ll ans = 0;
	for(ll z = 1ll<<60; z>>=1;) if(!check(ans+z)) ans+=z;
	cout << ans+1;
	return 0;
}
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
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pair<int, int>>;
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
ll f(ll g, ll b, ll n) {
	ll t = (n/(g+b))*g;
	return t + min(n%(g+b), g);
}
void  solve() {
	ll b, g, n;
	ll ans = 0;
	cin >> n >> g >> b;
	ll on = n;
	n = (n+1)/2;
	for(ll z = 1ll<<60; z>>=1;)
		if(f(g, b, ans+z)<n)
			ans+=z;
	cout << max(on, ans+1) << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
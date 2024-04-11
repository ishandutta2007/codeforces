#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
void solve() {
	ll n, t;
	map<int, vi> x;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t;
		x[t].pb(i);
	}
	ll ans = 1e18;
	for(auto i : x)
		for(int j = 1; j < i.second.size(); j++)
		ans = min(ans, i.second[j]-i.second[j-1]+1);
	if(ans>n) ans=-1;
	cout << ans << "\n";
}
int main() {
	 ios::sync_with_stdio(0);
	 cin.tie(0);
	 cout.tie(0);
	 ll t;
	 cin >> t;
	 while(t--) solve();
	 return 0;
}
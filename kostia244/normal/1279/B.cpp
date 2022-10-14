//#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,avx,sse,sse2,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using ld = long double;
const int maxn = 2e6 + 55, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n;
	vi a;
	ll t;
	cin >> n >> t;
	a.resize(n);
	for(auto &i : a) cin >> i;
	pi ans = {0, 0};
	ll s = 0;
	multiset<pair<ll, ll>, greater<pi>> x;
	for(int i = 0; i < n; i++) {
		s += a[i], x.insert(pi{a[i], i});
		if(s<=t) ans = max(ans, {i+1, 0});
		if(s-x.begin()->first<=t) ans = max(ans, pi{i, 1 + x.begin()->second});//, cout << i << " ";;
	}
	cout << ans.second << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while(t--) solve();
}
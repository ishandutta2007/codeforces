#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 5e3 + 22, mod = 998244353;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vi a;
	a.resize(n);
	for(auto & i : a) cin >> i;
	vi ans;
	ans.pb(a[0]);
	ll mx = max(a[0], 0ll);
	for(int i = 1; i < n; i++) {
		ans.pb(mx+a[i]);
		mx += max(a[i], 0ll);
	}
	for(auto i : ans) cout << i << " ";
}
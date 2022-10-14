#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
const int maxn = 1e5 + 55;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	vpi x;
	ll total = 0;
	for(int l, i = 1; i <= m; i++) {
		cin >> l;
		total += l;
		x.pb({-l, i});
	}
	
	if(total<n) return cout << -1, 0;
	vi ans(m+1);
	
	for(ll np = 1, i = 1; i <= m; i++) {
		auto t = x[i-1];
		if(np>n+t.first+1) return cout << -1, 0;
		ans[t.second] = np;
		total += t.first;
		np = max(min(np-t.first, n - total + 1), np+1);
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
}
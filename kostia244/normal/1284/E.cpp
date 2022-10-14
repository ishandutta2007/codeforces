#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1010, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ld = long double;
using vec = complex<ld>;
const ld eps = 1e-9;
ld dot(vec a, vec b) {
	return (a*conj(b)).real();
}
ld cross(vec a, vec b) {
	return (a*conj(b)).imag();
}
vector<vec> _a;
ll count(int i) {
	vector<vec> a;
	vector<pair<ld, int>> b;
	for(int j = 0; j < _a.size(); j++) if(j^i) b.push_back({arg(_a[j]-_a[i]), j});
	sort(all(b));
	for(auto [t, x] : b) a.push_back(_a[x]-_a[i]);
	int n = a.size();
	for(int i = 0; i < n; i++) a.push_back(a[i]);
	ll ans = 0;
	for(int i = 0, j = 0; i < n; i++) {
		j = max(j, i+1);
		while(j != i+n && cross(a[i], a[j]) < eps) j++;
		ll t = j-i;
		ans += (t-1)*(t-2)*(t-3)/6;
	}
	ans = n*1ll*(n-1)*(n-2)*(n-3)/24 - ans;
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	for(int x, y, i = 0; i < n; i++) cin >> x >> y, _a.push_back(vec(x, y));
	ll ans = 0;
	for(int i = 0; i < n; i++) ans += count(i);
	cout << ans << '\n';
}
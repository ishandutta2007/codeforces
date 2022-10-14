#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using ll = long long;
using namespace std;
const int maxn = 1<<17;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	ll s = 0, mx = 0;
	for(auto &i : a) cin >> i, s += i, mx = max(mx, i);
	ll pairs = 0;
	if(mx <= s/2) pairs = s/2;
	else pairs = s - mx;
	s -= pairs*2;
	cout << (s==0?"HL":"T") << '\n';
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}
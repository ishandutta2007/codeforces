#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int ll
using ll = long long;
using namespace std;
const int maxn = 1<<22, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	vector<int> a(n), b(n);
	for(auto &i : a) cin >> i;
	for(auto &i : b) cin >> i;
	priority_queue<array<int,2>> x;
	for(int i = 0; i < n; i++) x.push({abs(b[i]-a[i]), i});
	while(k1--) {
		int i = x.top()[1];
		x.pop();
		a[i] += a[i] > b[i] ? -1 : 1;
		x.push({abs(b[i]-a[i]), i});
	}
	while(!x.empty()) x.pop();
	for(int i = 0; i < n; i++) x.push({abs(a[i]-b[i]), i});
	while(k2--) {
		int i = x.top()[1];
		x.pop();
		b[i] += b[i] > a[i] ? -1 : 1;
		x.push({abs(a[i]-b[i]), i});
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) ans += (a[i]-b[i])*1ll*(a[i]-b[i]);
	cout << ans << '\n';
}
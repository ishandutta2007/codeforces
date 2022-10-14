#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<20;
void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	ll x = 0;
	for(auto &i : a) {
		cin >> i; x += i;
	}
	if(x%n) {
		cout << "-1\n";
		return;
	}
	x/=n;
	vector<array<ll, 3>> ops;
	for(int i = 1; i < n; i++) {
		ll f = (i+1 - (a[i]%(i+1))) % (i+1);
		ops.push_back({1, i+1, f});
		a[i] += f;
		a[0] -= f;
		ops.push_back({i+1, 1, a[i]/(i+1)});
		a[0] += a[i];
		a[i] = 0;
	}
	for(int i = 1; i < n; i++) {
		ops.push_back({1, i+1, x - a[i]});
	}
	cout << ops.size() << '\n';
	for(auto [x, y, z] : ops) cout << x << " " << y << " " << z << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}
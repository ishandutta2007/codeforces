#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 3e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	sort(all(a), greater<>());
	ll t = 0;
	int bad = 0;
	for(int i = 0; i < n; i++) {
		t += a[i];
		if(!t) {bad = 1;}
	}
	if(bad) {
		reverse(all(a));
		bad = 0;
		for(int i = 0; i < n; i++) {
			t += a[i];
			if(!t) {bad = 1;}
		}
	}
	if(bad) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(auto &i : a) cout << i << " "; cout << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
	int t;cin >> t;
	while(t--) {
		solve();
	}
}
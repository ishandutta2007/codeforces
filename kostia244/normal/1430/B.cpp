#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 1e3 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<ll> a(n);
		for(auto &i : a) cin >> i;
		sort(all(a), greater<>());
		ll ans = 0;
		for(int i = 0; i < min(n, k+1); i++) ans += a[i];
		cout << ans << '\n';
	}
}
#include<iostream> 

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	int ans = n * (n + 1) / 2;
	int cp = 1;
	while (cp <= n) {
		ans -= 2 * cp;
		cp *= 2;
	}
	cout << ans << endl;
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
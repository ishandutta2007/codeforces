#include <bits/stdc++.h>

using namespace std;

#define int long long


bool check(int n) {
	int kek = n;
	while (kek != 0LL) {
		int lol = kek % 10LL;
		if (lol != 0 && n % lol != 0LL) {
			return false;
		}
		kek /= 10LL;
	}
	return true;
}
void solve() {
	int n;
	cin >> n;
	while (!check(n)) {
		n++;
	}
	cout << n << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}
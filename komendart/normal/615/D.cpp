#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int pow(int x, int n) {
	if (n == 0) return 1;
	if (n & 1) return x * pow(x, n - 1) % MOD;
	return pow(x * x % MOD, n / 2);
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	vector<int> cnt((int) 2e5 + 5);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int p; cin >> p;
		cnt[p]++;
	}
	
	int res = 1;
	int div = 1;
	for (int i = 2; i < (int) cnt.size(); i++) {
		if (cnt[i]) {
			int t = pow(res, cnt[i] + 1);
			int p = cnt[i] * (cnt[i] + 1) / 2 % (MOD - 1);
			int tt = pow(i, div * p);
			res = t * tt % MOD;
			div = div * (cnt[i] + 1) % (MOD - 1);
		}
	}
	
	cout << res << '\n';
}
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int power(int x, int p) {
	if (p == 0) return 1;
	if (p & 1) return power(x, p - 1) * x % mod;
	return power(x * x % mod, p / 2);
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("t.in", "r", stdin);

	int n;
	cin >> n;
	vector<int> degree(n + 1);
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		++degree[a];
		++degree[b];
	}
	int leafs = 0;
	for (int i = 1; i <= n; ++i) {
		if (degree[i] == 1) {
			++leafs;
		}
	}

	cout << (leafs * power(2, n - leafs + 1) + (n - leafs) * power(2, n - leafs)) % mod << endl;
}
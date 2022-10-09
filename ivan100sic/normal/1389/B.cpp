// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[100005];

map<array<int, 3>, int> mp;

int solve(int p, int m, int k) {
	if (m == 0) {
		return 0;
	}

	auto it = mp.find({p, m, k});
	if (it != mp.end()) {
		return it->second;
	}

	auto& sol = mp[{p, m, k}];

	if (p > 0 && k > 0) {
		sol = max(sol, a[p-1] + solve(p-1, m-1, k-1));
	}

	if (p < n-1) {
		sol = max(sol, a[p+1] + solve(p+1, m-1, k));
	}

	return sol;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		mp.clear();

		int k, z;

		cin >> n >> k >> z;
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}

		cout << a[0] + solve(0, k, z) << '\n';
	}
}
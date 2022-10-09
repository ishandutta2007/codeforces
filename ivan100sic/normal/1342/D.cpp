// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, k;
int a[200005], af[200005], c[200005], f[200005];

bool moze(int w) {
	ll cap = 0;
	for (int i=k; i>=1; i--) {
		cap += w * 1ll * f[i];
		if (af[i] > cap) {
			return false;
		}
		cap -= af[i];
	}
	return true;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a[i] = x;
		af[x]++;
	}
	sort(a, a+n, greater<int>());

	for (int i=1; i<=k; i++)
		cin >> c[i];

	for (int i=1; i<=k; i++)
		f[i] = c[i] - c[i+1];

	int l = 1, r = n-1, o = n;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (moze(m)) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	cout << o << '\n';

	vector<vector<int>> sol(o);
	for (int i=0; i<n; i++) {
		sol[i % o].push_back(a[i]);
	}

	for (auto v : sol) {
		cout << v.size();
		for (int x : v)
			cout << ' ' << x;
		cout << '\n';
	}
}
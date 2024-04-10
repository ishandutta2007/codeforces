#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
ll a[200005];
ll z[200005];

ll solve(int l, int r) {
	map<int, int> mp;

	if (l > r)
		return 0;

	// cerr << l << ' ' << r << '\n';

	ll sol = 0;

	for (int i=l-1; i<=r; i++) {
		ll u = z[i];
		sol += mp[u];
		sol += mp[u-1];
		mp[u]++;
	}

	// cerr << sol << '\n';

	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		if (x < m)
			a[i] = -1;
		else if (x > m)
			a[i] = +1;
		else
			a[i] = 0;
	}

	for (int i=1; i<=n; i++) {
		z[i] = z[i-1] + a[i];
	}

	ll sol = solve(1, n);

	// cerr << "sol: " << sol << '\n';

	vector<int> va;

	for (int i=1; i<=n; i++) {
		if (a[i] == 0)
			va.push_back(i);
	}

	if (va.size() == 0) {
		cout << 0;
		return 0;
	}

	sol -= solve(1, va[0]-1);
	for (int i=0; i<(int)va.size()-1; i++) {
		sol -= solve(va[i]+1, va[i+1]-1);
	}
	sol -= solve(va.back()+1, n);

	cout << sol;

}
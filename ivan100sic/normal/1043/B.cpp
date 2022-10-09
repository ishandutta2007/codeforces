#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n;
ll a[1005];
ll x[1005];
ll y[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	vector<int> sol;

	for (int k=1; k<=n; k++) {
		for (int i=1; i<=k; i++) {
			x[i-1] = a[i] - a[i-1];
		}

		bool ok = true;

		for (int i=1; i<=n; i++) {
			y[i] = y[i-1] + x[(i-1) % k];
			if (y[i] != a[i])
				ok = false;
		}

		if (ok)
			sol.push_back(k);
	}

	cout << sol.size() << '\n';
	for (int x : sol)
		cout << x << ' ';

}
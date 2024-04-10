#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, t;
ll a[200005], x[200005];

void no(string no = "No") {
	cout << no << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> t;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		cin >> x[i];

	// x validan?
	for (int i=1; i<n; i++)
		if (x[i] > x[i+1])
			no();
	for (int i=1; i<=n; i++)
		if (x[i] < i)
			no();
	for (int i=1; i<=n; i++)
		if (x[i] > i && x[i] != x[i+1])
			no();

	// napravi
	vector<int> cp;
	for (int i=1; i<=n; i++)
		if (x[i] == i)
			cp.push_back(i);


	vector<ll> sol;
	for (int i=0; i<(int)cp.size(); i++) {
		// post uslov
		int il = i == 0 ? 1 : cp[i-1] + 1;
		int ir = cp[i];

		if (ir != n) {
			ll kraj_bloka = a[ir] + t + 1;
			if (ir == il)
				kraj_bloka = a[ir] + t;

			if (kraj_bloka - a[ir+1] >= t)
				no();
		}

		for (int j=il; j<=ir; j++) {
			ll x;
			if (j == ir)
				x = a[ir] + t + 1;
			else
				x = a[j+1] + t;
			if (il == ir)
				x = a[ir] + t;

			sol.push_back(x);
		}
	}

	cout << "Yes\n";
	for (ll x : sol)
		cout << x << ' ';
}
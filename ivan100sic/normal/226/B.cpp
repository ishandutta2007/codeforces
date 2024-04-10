#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];
ll z[100005];
ll ans[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n, greater<int>());
	for (int i=0; i<n; i++)
		z[i+1] = z[i] + a[i];

	for (int k=1; k<=100000; k++) {
		ll sz = 1, cost = 0;
		ll reach = 0, step = 0;
		while (reach < n) {
			ll f = z[min<ll>(n, reach + sz)] - z[reach];
			cost += step * f;
			step++;
			reach += sz;
			sz *= k;
		}
		ans[k] = cost;
	}

	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << ans[x] << ' ';
	}
	cout << '\n';
}
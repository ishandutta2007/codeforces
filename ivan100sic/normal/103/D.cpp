#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
int a[300005];
int x[300005], b[300005];
ll ans[300005];
ll tmp[300005];
basic_string<int> e[505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[n-1-i];
	cin >> q;
	for (int i=0; i<q; i++) {
		cin >> x[i] >> b[i];
		x[i] = n-x[i];
		if (b[i] <= 500)
			e[b[i]] += i;
	}

	for (int k=1; k<=500; k++) {
		for (int i=0; i<n; i++) {
			tmp[i] = a[i] + (i >= k ? tmp[i-k] : 0);
		}
		for (int j : e[k]) {
			ans[j] = tmp[x[j]];
		}
	}

	for (int i=0; i<q; i++) {
		if (b[i] > 500) {
			ll z = 0;
			int p = x[i];
			while (p >= 0) {
				z += a[p];
				p -= b[i];
			}
			ans[i] = z;
		}
	}	

	for (int i=0; i<q; i++)
		cout << ans[i] << '\n';
}
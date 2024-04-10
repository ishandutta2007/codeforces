#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int q;
int a[500005], n;
ld naj;
int p;
ll z;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	cout << setprecision(10) << fixed;

	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			a[n++] = x;
			while (p < n-1 && (a[p] + z + a[n-1]) / ld(p+2) <= (z + a[n-1]) / ld(p+1))
				z += a[p++];
			naj = max(naj, a[n-1] - (z + a[n-1]) / ld(p+1));
		} else {
			cout << naj << '\n';
		}
	}
}
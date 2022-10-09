#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[555], b[555];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int j=0; j<m; j++)
		cin >> b[j];

	ll sol = 8e18;

	for (int i=0; i<n; i++) {
		// ovaj sakriva ai
		ll hi = -8e18;		
		for (int j=0; j<n; j++) {
			for (int k=0; k<m; k++) {
				if (j != i) {
					hi = max(hi, a[j] * 1ll * b[k]);
				}
			}
		}
		sol = min(sol, hi);
	}
	cout << sol << '\n';

}
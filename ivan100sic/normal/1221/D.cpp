#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[300005], b[300005];
ll d[300005][5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> a[i] >> b[i];
			fill(d[i], d[i]+5, 4e18);
		}
		fill(d[n], d[n]+5, 4e18);

		d[0][0] = 0;
		for (int j=0; j<5; j++)
			d[1][j] = b[0] * j;

		for (int i=1; i<n; i++) {
			for (int j=0; j<5; j++) {
				for (int k=0; k<5; k++) {
					if (a[i-1] + j != a[i] + k) {
						d[i+1][k] = min(d[i+1][k], d[i][j] + k*b[i]);
					}
				}
			}
		}

		cout << *min_element(d[n], d[n]+5) << '\n';
	}
}
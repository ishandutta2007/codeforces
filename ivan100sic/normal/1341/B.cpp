// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n), z(n+1);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}

		for (int i=0; i<n; i++) {
			z[i+1] = z[i] + (i > 0 && i < n-1 && a[i] > a[i-1] && a[i] > a[i+1]);
		}

		int vb = -1, lb = -1;

		for (int l=0; l+k<=n; l++) {
			int v = z[l+k-1] - z[l+1];
			if (v > vb) {
				vb = v;
				lb = l;
			}
		}

		cout << vb+1 << ' ' << lb+1 << '\n';
	}
}
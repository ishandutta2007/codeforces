#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int t, n, m;
bool b[105];
int a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=1; i<=n; i++) {
			cin >> a[i];
		}
		memset(b, 0, sizeof b);
		for (int i=0; i<m; i++) {
			int x;
			cin >> x;
			b[x] = 1;
		}
		for (int i=1; i<=n; i++) {
			for (int j=1; j<n; j++) {
				if (b[j] && a[j] > a[j+1]) {
					swap(a[j], a[j+1]);
				}
			}
		}

		if (is_sorted(a+1, a+n+1)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
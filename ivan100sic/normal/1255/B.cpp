#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int z = 0;
		for (int i=0; i<n; i++)
			cin >> a[i], z += a[i];
		if (n == m && n > 2) {
			cout << 2*z << '\n';
			for (int i=1; i<=n; i++)
				cout << i << ' ' << 1+i%n << '\n';
		} else {
			cout << "-1\n";
		}
	}
}
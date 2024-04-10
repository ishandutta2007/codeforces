#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	set<pair<int, int>> s;

	int n, m;
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y)
			swap(x, y);
		s.insert({x, y});
	}

	for (int i=1; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			// heheheh
			if (!s.count({i, j})) {
				cout << "YES\n";

				a[i] = 1;
				a[j] = 2;
				int z = 2;
				for (int k=1; k<=n; k++) {
					if (!a[k])
						a[k] = ++z;
				}
				
				for (int k=1; k<=n; k++) {
					cout << a[k] << ' ';
				}
				cout << '\n';

				for (int k=1; k<=n; k++) {
					cout << (a[k] == 2 ? 1 : a[k]) << ' ';
				}
				cout << '\n';
				return 0;
			}
		}
	}

	cout << "NO\n";

}
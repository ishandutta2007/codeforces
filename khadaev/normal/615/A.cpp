#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	int n, m;
	cin >> n >> m;
	vector<bool> ok(m, false);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		for (int j = 0; j < x; ++j) {
			int y;
			cin >> y;
			--y;
			ok[y] = true;
		}
	}
	for (int i = 0; i < m; ++i)
		if (!ok[i]) {
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	return 0;
}
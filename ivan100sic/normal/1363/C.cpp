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
		int n, x;
		cin >> n >> x;
		vector<basic_string<int>> e(n+1);
		for (int i=1; i<n; i++) {
			int x, y;
			cin >> x >> y;
			e[x] += y;
			e[y] += x;
		}

		if (e[x].size() <= 1) {
			cout << "Ayush\n";
			continue;
		}

		cout << (n % 2 == 0 ? "Ayush\n" : "Ashish\n");
	}
}
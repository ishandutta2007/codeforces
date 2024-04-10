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
		int n, sum = 0;
		cin >> n;
		vector<int> a(n+1);
		for (int i=1; i<=n; i++) {
			cin >> a[i];
			sum += a[i];
		}

		if (sum % n) {
			cout << "-1\n";
			continue;
		}

		vector<tuple<int, int, int>> sol;

		auto mv = [&](int i, int j, int x) {
			a[i] -= i*x;
			a[j] += i*x;
			sol.emplace_back(i, j, x);
		};

		for (int k=2; k<=n; k++) {
			int r = (k - a[k] % k) % k;
			if (r) mv(1, k, r);
			mv(k, 1, a[k] / k);
		}

		int avg = sum / n;

		for (int i=2; i<=n; i++) {
			mv(1, i, avg - a[i]);
		}

		cout << sol.size() << '\n';
		for (auto [x, y, z] : sol) {
			cout << x << ' ' << y << ' ' << z << '\n';
		}

		// cerr << "! ";
		// for (int i=1; i<=n; i++) {
		// 	cerr << a[i] << " \n"[i==n];
		// }
	}
}
// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct seg {
	int r, v;
};

int a[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, d;
	cin >> n >> d;

	int l = 0;
	vector<seg> dp = {{0, 0}};

	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=0; i<n; i++) {
		vector<seg> tmp;
		// jutro
		if (dp.size() == 1) {
			if (dp[0].r == d) {
				tmp = dp;
			} else {
				tmp = dp;
				tmp.push_back(dp[0]);
				tmp[1].r = d;
				tmp[1].v++;
			}
		} else {
			tmp = dp;
			tmp[1].r = d;
		}

		int x = a[i];

		// dan
		dp = {};
		if (x == 0) {
			// provera, levi trim
			l = max(l, 0);
			for (auto [r, v] : tmp) {
				if (l <= r) {
					dp.push_back({r, v});
				}
			}
		} else {
			// opusteno, samo delta
			l += x;
			for (auto [r, v] : tmp) {
				r += x;
				r = min(r, d);
				if (l <= r) {
					dp.push_back({r, v});
				}
			}

			// rip
			if (l > d) {
				cout << "-1\n";
				return 0;
			}

			// bla bla
			if (dp.size() == 2 && dp[0].r == dp[1].r)
				dp.pop_back();
		}

		if (dp.size() == 0) {
			cout << "-1\n";
			return 0;
		}
	}

	int z = 123123123;
	for (auto [r, v] : dp) {
		if (l <= r) {
			z = min(z, v);
		}
	}
	if (z == 123123123)
		z = -1;
	cout << z << '\n';
}
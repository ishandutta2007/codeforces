#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, x[5005], y[5005];
vector<pair<int, int>> e[10005];

int p[5005], s[5005], q[5005];

pair<int, int> ep(int x) {
	int c = 0;
	while (x != p[x]) {
		c ^= q[x];
		x = p[x];
	}
	return {x, c};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> x[i] >> y[i];
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			e[abs(x[i] - x[j]) + abs(y[i] - y[j])].emplace_back(i, j);
		}
	}

	if (n == 2) {
		cout << "0\n2\n";
		return 0;
	}

	fill(s, s+n, 1);
	iota(p, p+n, 0);

	int last_size = n;
	for (int i=10000; i>=0; i--) {
		bool bad = false;
		int chk_size = last_size;
		for (auto [x, y] : e[i]) {
			auto [xe, xc] = ep(x);
			auto [ye, yc] = ep(y);

			if (xe == ye && xc == yc) {
				bad = true;
				break;
			}

			if (xe != ye) {
				if (s[xe] < s[ye])
					swap(xe, ye);
				p[ye] = xe;
				q[ye] = 1 ^ xc ^ yc;
				s[xe] += s[ye];
				last_size--;
			}

		}

		if (bad) {
			cout << i << '\n';
			int z = 1;
			while (chk_size--)
				z = z * 2 % 1'000'000'007;
			cout << z << '\n';
			return 0;
		}
	}
}
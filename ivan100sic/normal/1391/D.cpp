// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, m;
	cin >> n >> m;
	vector<string> a(n), b;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	if (n < m) {
		// transpose
		b.resize(m, string(n, 0));
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				b[j][i] = a[i][j];
			}
		}
		swap(a, b);
		swap(n, m);
	}

	if (m >= 4) {
		cout << "-1\n";
		return 0;
	}

	if (m == 1) {
		cout << "0\n";
		return 0;
	}

	vector<int> d(1<<m, 1e9);

	auto vr = [&](int r) {
		int z = 0;
		for (int i=0; i<m; i++) {
			z += (a[r][i] == '1' ? 1 : 0) << i;
		}
		return z;
	};

	for (int k=0; k<(1<<m); k++) {
		int v = vr(0);
		d[k] = __builtin_popcount(v ^ k);
	}

	for (int i=1; i<n; i++) {
		int r = vr(i);
		vector<int> d2(1<<m, 1e9);
		for (int j=0; j<(1<<m); j++) {
			for (int k=0; k<(1<<m); k++) {
				bool ok = 1;
				int t = j ^ k;
				t ^= t>>1;
				ok &= (bool)(t & 1);
				if (m == 3) ok &= (bool)(t & 2);
				if (ok) {
					int ch = __builtin_popcount(k ^ r);
					d2[k] = min(d2[k], d[j] + ch);
				}
			}
		}
		swap(d, d2);
	}

	cout << *min_element(begin(d), end(d)) << '\n';
}
// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cout << setprecision(14) << fixed;

	int t;
	cin >> t;
	while (t--) {
		int n, l;
		cin >> n >> l;
		vector<int> a(n+2);
		a[0] = 0;
		a[n+1] = l;
		for (int i=1; i<=n; i++) cin >> a[i];

		ld e = 0, f = 0, t = 0, u = 1, v = 1, sol = 0;
		int i = 0, j = n+1;
		while (1) {
			// sudar?
			if (j-i == 1) {
				sol = t + (a[j] - a[i] - e - f) / (u + v);
				break;
			}

			ld t1 = (a[i+1] - a[i] - e) / u;
			ld t2 = (a[j] - a[j-1] - f) / v;

			if (t1 < t2) {
				t += t1;
				i++;
				e = 0;
				f += v * t1;
				u += 1;
			} else {
				t += t2;
				j--;
				f = 0;
				e += u * t2;
				v += 1;
			}
		}

		cout << sol << '\n';

	}
}
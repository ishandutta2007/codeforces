#include <bits/stdc++.h>
using namespace std;

long double e[55][5005];
int n, r;
int f[55], s[55];
long double p[55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> r;
	for (int i=1; i<=n; i++) {
		cin >> f[i] >> s[i] >> p[i];
		p[i] /= 100.0L;
	}

	long double lo = 0, hi = 1e50;
	int steps = 200;

	while (steps--) {
		long double mid = (lo + hi) / 2.0;

		for (int t=0; t<=r; t++) {
			e[n][t] = 0.0;
		}

		for (int i=n-1; i>=0; i--) {
			for (int t=0; t<=r; t++) {

				if (t + f[i+1] > r) {
					// nikako ne stizem, resetuj
					e[i][t] = mid;
				} else if (t + s[i+1] > r) {
					// stizem samo ako predjem brzo
					e[i][t] = p[i+1] * (e[i+1][t + f[i+1]] + f[i+1])
						+ (1L - p[i+1]) * (s[i+1] + mid);
				} else {
					// stizem neakko
					e[i][t] = p[i+1] * (e[i+1][t + f[i+1]] + f[i+1])
						+ (1L - p[i+1]) * (e[i+1][t + s[i+1]] + s[i+1]);
				}

				e[i][t] = min(e[i][t], mid);
			}				
		}

		if (e[0][0] == mid) {
			lo = mid;
		} else {
			hi = mid;
		}
	}

	cout.precision(20);
	cout << fixed << (lo+hi) / 2;

}
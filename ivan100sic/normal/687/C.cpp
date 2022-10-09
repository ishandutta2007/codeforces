#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[505];
bitset<512> d[505], w, sol, b[505][505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	d[0][0] = 1;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		d[i] = d[i-1] | (d[i-1] << a[i]);
	}

	w[k] = 1;
	b[n][k][0] = 1;
	for (int i=n; i>=1; i--) {
		auto w2 = (w | (w >> a[i])) & (d[i-1]);
		for (int j=0; j<512; j++) {
			if (w2[j]) {
				// horizontala, nista
				if (w[j])
					b[i-1][j] |= b[i][j];
				// dijagonala
				if (j + a[i] < 512 && w[j + a[i]])
					b[i-1][j] |= b[i][j + a[i]] | (b[i][j + a[i]] << a[i]);
			}
		}
		w = w2;
	}

	sol = b[0][0];

	cout << sol.count() << '\n';
	for (int i=0; i<512; i++)
		if (sol[i])
			cout << i << ' ';
	cout << '\n';
}
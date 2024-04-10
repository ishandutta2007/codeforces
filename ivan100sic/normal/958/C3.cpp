#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int vreds[105];
int prefiks[105], sufiks[105];

int n, k, p;

void recalc() {
	prefiks[0] = vreds[0];
	for (int i=1; i<p; i++)
		prefiks[i] = min(prefiks[i-1], vreds[i]);
	sufiks[p-1] = vreds[p-1];
	sufiks[p] = 1123123123;
	for (int i=p-2; i>=0; i--)
		sufiks[i] = min(sufiks[i+1], vreds[i]);
}

int dp[2][500005];
int a[500005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> p;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a[i] %= p;
	}

	dp[0][0] = 0;
	fill(dp[0]+1, dp[0]+n+1, 1123123123);

	for (int i=1; i<=k; i++) {
		auto ol = dp[1-i%2];
		auto nu = dp[i%2];

		int w = 0;

		// drvo.init();
		fill(vreds, vreds+p, 1123123123);

		if (i == 1) {
			// drvo.set(0, ol[0]);
			vreds[0] = 0;
		}

		recalc();

		for (int j=1; j<=n; j++) {
			// racunaj
			w = (w + a[j]) % p;
			// nu[j] = min(w + drvo.get(0, w), w+p+drvo.get(w+1, p-1));
			nu[j] = min(w + prefiks[w], w + p + sufiks[w+1]);

			// dodaj ol[j] staro
			if (ol[j] - w < vreds[w]) {
				// drvo.set(w, ol[j] - w);
				vreds[w] = ol[j] - w;
				recalc();
			}

			// cerr << nu[j] << ' ';
		}
		// cerr << '\n';
	}

	cout << dp[k%2][n] << '\n';
}
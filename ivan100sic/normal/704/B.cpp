/*
	Morao sam da bacim pogled na editorial, jbg
	Ti nisi normalan. Ko jos daje CC-DP kao jebeni div1-B???
	Pa sve i da zadatak vredi 1250
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, s, e;
ll a[5005], b[5005], c[5005], d[5005], x[5005];
ll dp[2][5005][2][2];

void mn(ll& x, ll y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n >> s >> e;
	for (int i=1; i<=n; i++) cin >> x[i];
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) cin >> b[i];
	for (int i=1; i<=n; i++) cin >> c[i];
	for (int i=1; i<=n; i++) cin >> d[i];

	for (int i=1; i<=n; i++) {
		a[i] += x[i];
		b[i] -= x[i];
		c[i] += x[i];
		d[i] -= x[i];
	}

	memset(dp, 63, sizeof dp);
	dp[0][0][0][0] = 0;

	// -> i           A
	//    i <-        B
	// <- i           C
	//    i ->        D          

	for (int i=1; i<=n; i++) {
		ll A = ::a[i], B = ::b[i], C = ::c[i], D = ::d[i];
		auto ol = dp[1-i%2];
		auto nu = dp[i%2];
		memset(nu, 63, sizeof dp[0]);

		for (int j=0; j<=i; j++) {
			for (int k=0; k<2; k++) {
				for (int l=0; l<2; l++) {
					ll v = ol[j][k][l];
					if (v > 1e17)
						continue;

					if (i == s) {
						// mozes da se ukacis samo na pocetak puta

						if (k == 0) {
							// novi, prazan put
							mn(nu[j][k+1][l], v + D);
						}

						if (j > 0 && k == 0) {
							// zakaci se na postojeci put
							mn(nu[j-1][k+1][l], v + C);
						}

						if (l > 0 && k == 0) {
							mn(nu[j][0][0], v + C);
						}

					} else if (i == e) {
						// mozes samo na kraj puta

						if (l == 0) {
							mn(nu[j][k][l+1], v + B);
						}

						if (l == 0 && j > 0) {
							mn(nu[j-1][k][l+1], v + A);
						}

						if (k > 0 && l == 0) {
							mn(nu[j][0][0], v + A);
						}
					} else {
						// whatever

						// skroz novi put
						mn(nu[j+1][k][l], v + B + D);

						// nakaci se samo na pocetak nekog puta
						if (j > 0 || l > 0) {
							mn(nu[j][k][l], v + B + C);
						}

						// nakaci se samo na kraj nekog puta
						if (j > 0 || k > 0) {
							mn(nu[j][k][l], v + A + D);
						}

						// prevezi neka dva postojeca puta
						if (j >= 2) {
							mn(nu[j-1][k][l], v + A + C);
						}

						if (k > 0 && l > 0) {
							mn(nu[j][0][0], v + A + C);
						}

						if (j > 0 && k > 0) {
							mn(nu[j-1][k][l], v + A + C);
						}

						if (j > 0 && l > 0) {
							mn(nu[j-1][k][l], v + A + C);
						}
					}			
				}
			}
		}
			
	}
	cout << dp[n%2][0][0][0] << "\n";
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct prob {
	ld diff;
	int skor;

	bool operator< (const prob& o) const {
		return diff > o.diff;
	}
};

int n;
prob a[105];

// dokle, broj uradjenih, skor
ld dp[105][105][1015];
ld pw11[105];
// najmanje potrebno vreme da se uradi to pod pretp. da je poc. skil = 1
// (ne racunajuci gledanje serija)

void mn(ld& x, ld y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	pw11[0] = 1;
	for (int i=1; i<105; i++)
		pw11[i] = pw11[i-1] * 10 / 9;

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		ld c, t;
		cin >> c >> t;
		for (int i=1; i<=n; i++)
			cin >> a[i].diff >> a[i].skor;
		sort(a+1, a+n+1);

		for (int i=0; i<105; i++)
			for (int j=0; j<105; j++)
				for (int k=0; k<1015; k++)
					dp[i][j][k] = 1e50;

		dp[0][0][0] = 0;

		for (int i=1; i<=n; i++) {
			for (int j=0; j<i; j++) {
				for (int k=0; k<1000; k++) {
					if (dp[i-1][j][k] > 1e40)
						continue;

					// radim ovaj zad
					mn(dp[i][j+1][k + a[i].skor],
						dp[i-1][j][k] + pw11[j+1] * a[i].diff);

					// ne radim ovaj zad
					mn(dp[i][j][k],	dp[i-1][j][k]);
				}
			}
		}

		for (int k=1000; k>=0; k--) {
			int ok = 0;
			for (int j=0; j<=n; j++) {
				ld baza = dp[n][j][k];

				ld t_opt = (sqrt(baza * c) - 1) / c;
				if (t_opt < 0)
					t_opt = 0;

				if (t_opt + baza / (1 + c * t_opt) + 10 * j <= t) {
					// cerr << t_opt << ' ' << baza << ' '
					// 	<< t_opt + baza / (1 + c * t_opt) + 10 * j << '\n';
					ok = 1;
					break;
				}
			}
			if (ok) {
				cout << k << '\n';
				break;
			}
		}
	}
}
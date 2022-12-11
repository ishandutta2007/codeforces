#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

struct pt {
	ld x, y;
	pt() {}
	pt(ld x, ld y) : x(x), y(y) {}
};

const int nmax = 2550;

ld dp[nmax][nmax][2][2];

ld dist(const pt& a, const pt& b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	//ofstream cout("output.txt");
	
	int n;
	cin >> n;
	vector<pt> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i].x >> p[i].y;
	}

	for (int i = 0; i < n; ++i) {
		int j = i + 1;
		if (j == n) {
			j = 0;
		}
		dp[i][j][1][1] = dist(p[i], p[j]);
	}

	for (int delta = 1; delta + 1 < n; ++delta) {
		for (int a = 0; a < 2; ++a) {
			for (int b = 0; b < 2; ++b) {
				for (int i = 0; i < n; ++i) {
					int j = i + delta;
					if (j >= n) {
						j -= n;
					}
					if (dp[i][j][a][b] == 0) {
						continue;
					}
					int iprev = i - 1;
					if (iprev < 0) {
						iprev += n;
					}
					int jnext = j + 1;
					if (jnext >= n) {
						jnext -= n;
					}

					if (a == 1) {
						dp[iprev][j][1][b] = max(dp[iprev][j][1][b], dp[i][j][a][b] + dist(p[i], p[iprev]));
						dp[i][jnext][0][1] = max(dp[i][jnext][0][1], dp[i][j][a][b] + dist(p[i], p[jnext]));
					}

					if (b == 1) {
						dp[iprev][j][1][0] = max(dp[iprev][j][1][0], dp[i][j][a][b] + dist(p[j], p[iprev]));
						dp[i][jnext][a][1] = max(dp[i][jnext][a][1], dp[i][j][a][b] + dist(p[j], p[jnext]));
					}
				}
			}
		}
	}

	ld ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int a = 0; a < 2; ++a) {
			for (int b = 0; b < 2; ++b) {
				int j = i + n - 1;
				if (j >= n) {
					j -= n;
				}
				ans = max(ans, dp[i][j][a][b]);
			}
		}
	}

	/*for (int a = 0; a < 2; ++a) {
		for (int b = 0; b < 2; ++b) {
			cout << dp[0][2][a][b] << "\n";
		}
	}*/
	//cout << dp[0][1][1][1] << "\n";

	cout << fixed;
	cout.precision(12);
	cout << ans << "\n";

}
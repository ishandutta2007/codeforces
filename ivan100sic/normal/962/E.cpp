#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll

int n;
int x[300005];
char c[300005];

int g[300005], m;

struct chetvorka {
	int bf, bl, rf, rl;
};

const char BOJA1 = 'R';
const char BOJA2 = 'B';
const char COMMON = 'P';

chetvorka daj(int l, int r) {
	chetvorka ch = {-1, -1, -1, -1};
	for (int i=l; i<=r; i++) {
		(c[i] == BOJA1 ? ch.rl : ch.bl) = x[i];
	}
	for (int i=r; i>=l; i--) {
		(c[i] == BOJA1 ? ch.rf : ch.bf) = x[i];
	}
	return ch;
}

int min_gap(int l, int r, char color) {
	int last = x[l];
	int largest = 0;

	for (int i=l+1; i<=r; i++) {
		if (i == r || c[i] == color) {

			int diff = x[i] - last;
			last = x[i];

			largest = max(largest, diff);
		}
	}

	return x[r] - x[l] - largest;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> x[i] >> c[i];
	}

	for (int i=1; i<=n; i++) {
		if (c[i] == COMMON) {
			g[++m] = i;
		}
	}

	if (m == 0) {
		auto ch = daj(1, n);

		cout << (ch.bl-ch.bf) + (ch.rl-ch.rf) << '\n';
		return 0;
	}

	ll sol = 0;
	// prvi
	{
		auto ch = daj(1, g[1]-1);

		if (ch.bl != -1) {
			sol += x[g[1]] - ch.bf;
		}
		if (ch.rl != -1) {
			sol += x[g[1]] - ch.rf;
		}
	}

	// zadnji
	{
		auto ch = daj(g[m]+1, n);

		if (ch.bl != -1) {
			sol += ch.bl - x[g[m]];
		}
		if (ch.rl != -1) {
			sol += ch.rl - x[g[m]];
		}
	}

	// izmedju
	for (int i=1; i<m; i++) {

		if (g[i] + 1 != g[i+1]) {
			// stavljam most preko
			ll c1 = min_gap(g[i], g[i+1], BOJA2) + min_gap(g[i], g[i+1], BOJA1)
				+ (x[g[i+1]] - x[g[i]]);

			// ne stavljam most preko
			ll c2 = 2ll * (x[g[i+1]] - x[g[i]]);

			sol += min(c1, c2);
		} else {
			sol += x[g[i+1]] - x[g[i]];
		}
	
			
	}

	cout << sol << '\n';

}
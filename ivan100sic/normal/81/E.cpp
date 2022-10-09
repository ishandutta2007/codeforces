#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int v[100005], s[100005];
ll w[100005];
basic_string<int> e[100005];

bool vis1[100005]; int backedge, fb1, fb2;
bool inst[100005];

int adj(int i, int x) {
	return i == x ? v[x] : i;
}

void dfs1(int x, int i) {
	vis1[x] = true;
	inst[x] = true;
	// cerr << "entering " << x << ' ' << i << '\n';
	for (int j : e[x]) {
		if (i == j)
			continue;
		int y = adj(j, x);
		// cerr << "examining " << j << ' ' << y << '\n';
		if (vis1[y]) {
			if (inst[y]) {
				// cerr << "backedge set " << j << '\n';
				backedge = j;
			}
		} else {
			dfs1(y, j);
		}
	}
	// cerr << "leaving " << x << '\n';
	inst[x] = false;
}

ll dp[100005][2];
int nx[100005];

void dfs2(int x, int i) {
	nx[x] = -1;
	dp[x][0] = 0;
	ll vr = -123123123123123123ll;
	for (int j : e[x]) {
		if (i == j)
			continue;
		if (j == backedge)
			continue;
		int y = adj(j, x);
		dfs2(y, j);

		bool bad = y == fb1 || y == fb2;

		if (!bad) {
			dp[x][0] += max(dp[y][0], dp[y][1]);
			ll cand = dp[y][0] - max(dp[y][0], dp[y][1]) + w[j];
			if (cand > vr) {
				nx[x] = j;
				vr = cand;
			}
		} else {
			dp[x][0] += dp[y][0];
		}
	}
	dp[x][1] = dp[x][0] + vr;
	// cerr << "done solving " << x << ' ' << dp[x][0] << ' ' << dp[x][1] << '\n';
}

void rekonstruisi(int x, int i, int st, basic_string<int>& gr) {
	// nisi mecovan, radi sta oces
	if (x == fb1 || x == fb2)
		st = 1;

	if (st == 0 && dp[x][1] > dp[x][0]) {
		gr += nx[x];
		for (int j : e[x]) {
			if (i == j)
				continue;
			if (j == backedge)
				continue;
			int y = adj(j, x);
			if (j == nx[x]) {
				rekonstruisi(y, j, 1, gr);
			} else {
				rekonstruisi(y, j, 0, gr);
			}
		}
	} else {
		for (int j : e[x]) {
			if (i == j)
				continue;
			if (j == backedge)
				continue;
			int y = adj(j, x);
			rekonstruisi(y, j, 0, gr);
		}
	}
}

ll tezina(basic_string<int>& gr) {
	ll z = 0;
	for (int i : gr)
		z += w[i];
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> v[i] >> s[i];
		e[v[i]] += i;
		e[i] += i;
	}

	for (int i=1; i<=n; i++) {
		w[i] = 1000000 + (s[i] != s[v[i]]);
	}

	basic_string<int> global_ans;

	for (int i=1; i<=n; i++) {
		if (!vis1[i]) {
			dfs1(i, -1);
			// cerr << "i backedge " << i << ' ' << backedge << '\n';
			// resi normalno
			fb1 = fb2 = -1;
			dfs2(i, -1);
			basic_string<int> gr1;
			rekonstruisi(i, -1, 0, gr1);

			fb1 = backedge;
			fb2 = v[backedge];
			dfs2(i, -1);
			basic_string<int> gr2;
			rekonstruisi(i, -1, 0, gr2);
			gr2 += backedge;

			if (tezina(gr2) > tezina(gr1)) {
				swap(gr2, gr1);
			}

			global_ans += gr1;
		}
	}

	ll finalwt = tezina(global_ans);
	cout << finalwt/1000000 << ' ' << finalwt%1000000 << '\n';
	for (int i : global_ans)
		cout << i << ' ' << v[i] << '\n';
}
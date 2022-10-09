// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
vector<string> a, d;

pair<int, int> mv(char c) {
	if (c == 'U') return {-1, 0};
	if (c == 'R') return {0, 1};
	if (c == 'D') return {1, 0};
	if (c == 'L') return {0, -1};
	return {0, 0};
}

// -2 unvis
// -1 temp vis
// >= 0 done
vector<vector<int>> state;
vector<vector<int>> group;
vector<pair<int, int>> st;
vector<int> clen;
int gg;

void dfs(int x, int y) {
	state[x][y] = -1;
	st.emplace_back(x, y);
	auto [xx, yy] = mv(d[x][y]);
	xx += x, yy += y;

	if (state[xx][yy] == -1) {
		// ciklus
		vector<pair<int, int>> cyc;
		for (int i=st.size()-1;; i--) {
			cyc.push_back(st[i]);
			if (st[i] == pair(xx, yy))
				break;
		}

		st = {};
		int v = 0;
		for (auto [x, y] : cyc)
			state[x][y] = v++, group[x][y] = gg;
		clen[gg] = v;
		gg++;
		return;
	}

	if (state[xx][yy] == -2)
		dfs(xx, yy);
	state[x][y] = state[xx][yy] + 1;
	group[x][y] = group[xx][yy];
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		a.resize(n);
		d.resize(n);
		state.assign(n, vector<int>(m, -2));
		group.assign(n, vector<int>(m, -1));
		clen.assign(n*m, 0);
		gg = 0;
		for (int i=0; i<n; i++)
			cin >> a[i];
		for (int i=0; i<n; i++)
			cin >> d[i];

		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if (state[i][j] == -2) {
					dfs(i, j);
				}
			}
		}

		vector<vector<pair<int, int>>> e(gg);

		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				e[group[i][j]].emplace_back(i, j);
			}
		}
		int uu = 0, vv = 0;

		for (int i=0; i<gg; i++) {
			int l = clen[i];
			string hb(l, 0);
			for (auto [x, y] : e[i]) {
				if (a[x][y] == '0') {
					hb[state[x][y] % l] = 1;
				}
			}
			int x = count(begin(hb), end(hb), 1);
			uu += x;
			vv += l;
		}
		cout << vv << ' ' << uu << '\n';
	}
}
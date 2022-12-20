#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int ids[51][51];
char grid[51][51];
int n, m;
pair<int, int> dir[8];

void dfs(int x, int y) {
	rep(i, 0, 8) {
		int xx = dir[i].first+x;
		int yy = dir[i].second+y;
		if (xx >= n || xx < 0 || yy >= m || yy < 0) continue;

		if (grid[xx][yy] != '*') continue;
		if (ids[xx][yy] != 0) continue;

		ids[xx][yy] = ids[x][y];
		dfs(xx, yy);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	dir[0] = mp(-1, 0);
	dir[1] = mp(1, 0);
	dir[2] = mp(0, -1);
	dir[3] = mp(0, 1);
	dir[4] = mp(1, 1);
	dir[5] = mp(-1, 1);
	dir[6] = mp(1, -1);
	dir[7] = mp(-1, -1);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		rep(i, 0, n) rep(j, 0, m) {
			cin >> grid[i][j];
			ids[i][j] = 0;
		}

		int currid = 1;
		rep(i, 0, n) rep(j, 0, m) {
			if (grid[i][j] == '*' && ids[i][j] == 0) {
				ids[i][j] = currid;
				currid++;
				dfs(i, j);
			}
		}

		map<int, int> amts;
		bool ok = true;
		rep(i, 0, n) rep(j, 0, m) {
			if (grid[i][j] == '*') amts[ids[i][j]]++;
		}

		for (pii blah : amts) {
			//cout << blah.first << ' ' << blah.second << endl;
			if (blah.second != 3) {
				ok = false;
				break;
			}
		}

		set<int> good;
		rep(i, 0, n) rep(j, 0, m) {
			if (grid[i][j] != '*') continue;
			set<int> nbrs;
			for (int k = 0; k < 8; k++) {
				int xx = i + dir[k].first;
				int yy = j + dir[k].second;
				if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;

				if (ids[xx][yy] == ids[i][j]) {
					nbrs.insert(k);
				}
			}

			if (sz(nbrs) != 2) continue;

			//cout << ids[i][j] << endl;
			//for (int y : nbrs) cout << y << ' ';
			//cout << endl;

			if (nbrs.count(0) > 0 && nbrs.count(2) + nbrs.count(3) == 1) good.insert(ids[i][j]);
			if (nbrs.count(1) > 0 && nbrs.count(2) + nbrs.count(3) == 1) good.insert(ids[i][j]);
			if (nbrs.count(2) > 0 && nbrs.count(0) + nbrs.count(1) == 1) good.insert(ids[i][j]); 
			if (nbrs.count(3) > 0 && nbrs.count(0) + nbrs.count(1) == 1) good.insert(ids[i][j]);

			//if (nbrs == 2) good.insert(ids[i][j]);
		}
		
		//cout << sz(good) << endl;
		//for (int x : good) cout << x << ' ';
		//cout << endl;

		if (sz(good) != sz(amts)) ok = false;
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
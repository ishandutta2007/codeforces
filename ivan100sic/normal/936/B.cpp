#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> e[100005], er[100005];

bool vis[100005], stek[100005];

bool has_cycle(int x) {

	vis[x] = true;
	stek[x] = true;

	for (int y : e[x]) {
		if (stek[y]) {
			return true;
		}
		if (!vis[y]) {
			if (has_cycle(y)) {
				return true;
			}
		}
	}

	stek[x] = false;

	return false;
}

int d[100005][2];
int nx[100005][2];

void bfs() {

	queue<pair<int, int>> q;

	for (int i=1; i<=n; i++) {
		if (e[i].size() == 0) {
			q.push({i, 0});
			d[i][0] = 0;
		}
	}

	while (!q.empty()) {
		auto p = q.front(); q.pop();

		for (int y : er[p.first]) {
			int z = p.second ^ 1;

			if (d[y][z] > 1234567) {
				d[y][z] = d[p.first][p.second] + 1;
				nx[y][z] = p.first;
				q.push({y, z});
			}
		}
	}
}

void printsol(int x) {
	cout << "Win\n";

	int z = 1;

	while (e[x].size() > 0) {
		cout << x << ' ';
		x = nx[x][z];
		z ^= 1;
	}

	cout << x << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;

	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		while (x--) {
			int j;
			cin >> j;
			e[i].push_back(j);
			er[j].push_back(i);
		}
	}

	memset(d, 63, sizeof(d));

	int start;
	cin >> start;

	bool hc = has_cycle(start);

	bfs();

	if (d[start][1] < 1234567) {
		printsol(start);
	} else if (hc) {
		cout << "Draw\n";
	} else {
		cout << "Lose\n";
	}
}
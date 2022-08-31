// stop creating shitty problems

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
pair<int, int> pos[444];
int cell[22][22];
int n, m;

void Move(vector<int> p) {
	ans.push_back(p);
	int m = p.size();
	for (int i = m - 2; i >= 0; i--) {
		swap(pos[p[i]], pos[p[m - 1]]);
		auto x = pos[p[i]];
		cell[x.first][x.second] = p[i];
		x = pos[p[m - 1]];
		cell[x.first][x.second] = p[m - 1];
	}
}

void rotL(int x, int y) {
	Move(vector<int> {cell[x][y], cell[x + 1][y], cell[x + 1][y + 1], cell[x][y + 1]});
}

void rotR(int x, int y) {
	Move(vector<int> {cell[x][y], cell[x][y + 1], cell[x + 1][y + 1], cell[x + 1][y]});
}

void goX(int x, int dx) {
	int u = pos[x].first, v = pos[x].second;
	if (u == n - 1)
		Move(vector<int> {cell[u][v], cell[u][v + dx], cell[u - 1][v + dx], cell[u - 1][v]});
	else
		Move(vector<int> {cell[u][v], cell[u][v + dx], cell[u + 1][v + dx], cell[u + 1][v]});
}
void goY(int x, int dy) {
	int u = pos[x].first, v = pos[x].second;
	if (v != m - 1)
		Move(vector<int> {cell[u][v], cell[u + dy][v], cell[u + dy][v + 1], cell[u][v + 1]});
	else
		Move(vector<int> {cell[u][v], cell[u + dy][v], cell[u + dy][v - 1], cell[u][v - 1]});
}

int perm[444];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n * m; i++) perm[i] = i;
	random_shuffle(perm, perm + n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &cell[i][j]);
			--cell[i][j];
			pos[cell[i][j]] = make_pair(i, j);
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int x = i * m + j;
			while (pos[x].second > j) {
				goX(x, -1);
			}
			while (pos[x].second < j) {
				goX(x, 1);
			}
			while (pos[x].first > i) {
				goY(x, -1);
			}

		}
		int x = i * m + m - 1;
		if (pos[x] == make_pair(i, m - 1)) continue;
		if (pos[x] == make_pair(i + 1, m - 2)) {
			rotL(i + 1, m - 2);
		}
		rotR(i, m - 2);
		while (pos[x].second < m - 1) {
			goX(x, 1);
		}
		while (pos[x].first > i + 1) {
			goY(x, -1);
		}
		rotL(i, m - 2);
	}

	for (int j = 0; j < m - 2; j++) {
		int x = (n - 2) * m + j;
		while (pos[x].second > j) {
			goX(x, -1);
		}
		while (pos[x].first > n - 2) {
			goY(x, -1);
		}
		x = (n - 1) * m + j;
		if (pos[x] == make_pair(n - 1, j)) continue;
		if (pos[x] == make_pair(n - 2, j + 1)) rotR(n - 2, j + 1);
		rotL(n - 2, j);
		while (pos[x].first < n - 1) {
			goY(x, 1);
		}
		while (pos[x].second > j + 1) {
			goX(x, -1);
		}
		rotR(n - 2, j);
	}
	while (cell[n - 2][m - 2] != ((n - 2)*m + m - 2)) {
		rotL(n - 2, m - 2);
	}
	while (1) {
		bool valid = 1;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
				if (cell[i][j] != i * m + j) valid = 0;
		if (valid) break;
		int ty = rand() % 3;
		if (ty == 0) {
			rotL(n - 2, m - 2);
		} else if (ty == 1) {
			rotL(n - 2, m - 3);
		} else {
			Move(vector<int> {cell[n - 2][m - 3], cell[n - 2][m - 2], cell[n - 2][m - 1],
			                  cell[n - 1][m - 1], cell[n - 1][m - 2], cell[n - 1][m - 3]
			                 });
		}
	}
	printf("%d\n", ans.size());
	for (auto p : ans) {
		printf("%d", p.size());
		for (auto q : p) printf(" %d", q + 1);
		puts("");
	}
}
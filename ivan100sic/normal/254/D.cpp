#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, d;
string a[1005];

struct pt {
	int x, y;

	pt(int x=0, int y=0) : x(x), y(y) {}

	bool operator< (const pt& b) const {
		return tie(x, y) < tie(b.x, b.y);
	}
};

int dist[1005][1005];

vector<pt> bfs(pt p) {
	dist[p.x][p.y] = 0;
	vector<pt> q = {p};
	size_t qs = 0;
	while (qs != q.size()) {
		auto p = q[qs++];
		int g = dist[p.x][p.y];
		if (g == d)
			continue;
		g++;
		auto go = [&](int xx, int yy) {
			if (a[xx][yy] == 'X')
				return;
			if (dist[xx][yy] != -1)
				return;
			dist[xx][yy] = g;
			q.emplace_back(xx, yy);
		};

		go(p.x, p.y+1);
		go(p.x, p.y-1);
		go(p.x+1, p.y);
		go(p.x-1, p.y);
	}

	for (auto p : q)
		dist[p.x][p.y] = -1;
	return q;
}

bool check[1005][1005];
vector<pt> killed[1005][1005], ch;
pt buff[10005];

int main() {
	fin >> n >> m >> d;
	for (int i=0; i<n; i++)
		fin >> a[i];

	memset(dist, 0xff, sizeof(dist));

	vector<pt> rats;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (a[i][j] == 'R')
				rats.emplace_back(i, j);

	if (rats.size() >= 300) {
		fout << "-1\n";
		return 0;
	}

	for (auto p : rats) {
		auto q = bfs(p);
		for (auto r : q)
			check[r.x][r.y] = true;
	}

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) {
			// cisto da bacim jos jednu bombu
			if (!check[i][j] && a[i][j] == '.') {
				check[i][j] = true;
				i = 1123321;
				break;
			}
		}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (check[i][j]) {
				ch.emplace_back(i, j);
			}
		}
	}

	for (auto [i, j] : ch) {
		auto t = bfs({i, j});
		for (auto p : t) {
			if (a[p.x][p.y] == 'R') {
				killed[i][j].push_back(p);
			}
		}
		sort(killed[i][j].begin(), killed[i][j].end());
	}

	for (auto [i, j] : ch) {
		for (auto [k, l] : ch) {
			if (i == k && j == l)
				continue;
			auto c = set_union(killed[i][j].begin(), killed[i][j].end(),
				killed[k][l].begin(), killed[k][l].end(), buff) - buff;
			if (c == (int)rats.size()) {
				fout << i+1 << ' ' << j+1 << ' ' << k+1 << ' ' << l+1 << '\n';
				return 0;
			}
		}
	}
	fout << "-1\n";
}
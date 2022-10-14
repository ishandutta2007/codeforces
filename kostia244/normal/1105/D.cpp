#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long
using namespace std;

struct point {
	long long x, y, dist;
	point(long long _x, long long _y, long long _dist) {
		x = _x;
		y = _y;
		dist = _dist;
	}
};

long long n, m, p, sp[15], cnt[15] = { 0, }, dirx[4] = { 1, -1, 0, 0 }, diry[4] = { 0,
		0, 1, -1 };
char grid[1019][1019] = { { '\0', } };
bool vis[1019][1019] = { { 0, } };
list<point> go[15][2];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> p;
	for (long long i = 1; i <= p; i++) {
		cin >> sp[i];
	}
	for (long long i = 0; i < n; i++)
		for (long long j = 0; j < m; j++) {
			cin >> grid[i][j];
			if ((grid[i][j] - '0') > 0 && (grid[i][j] - '0') < 10) {
				go[(grid[i][j] - '0')][1].emplace_front(i, j, 0);
			}
		}
	long long i;
	bool cont = true;
	for (long long t = 1; cont; t++) {
		cont = false;
		i = t & 1;
		for (int ply = 1; ply <= p; ply++) {
			cont |= !go[ply][i].empty();
			while (!go[ply][i].empty()) {
				point v = go[ply][i].back();
				go[ply][i].pop_back();
				grid[v.x][v.y] = '0' + ply;
				if (v.dist == sp[ply]) {
					go[ply][i ^ 1].emplace_front(v.x, v.y, 0);
				} else {
					for (int j = 0; j < 4; j++) {
						if (v.y + diry[j] >= 0 && v.x + dirx[j] >= 0 && v.y + diry[j] < m && v.x + dirx[j] < n
								&& grid[v.x + dirx[j]][v.y + diry[j]] == '.' && !vis[v.x + dirx[j]][v.y + diry[j]]) {
							go[ply][i].emplace_front(v.x + dirx[j], v.y + diry[j],
									v.dist + 1), vis[v.x + dirx[j]][v.y + diry[j]] = 1;
						}
					}
				}
			}
		}
	}
	for (long long i = 0; i < n; i++)
		for (long long j = 0; j < m; j++) {
			if ((grid[i][j] - '0') > 0 && (grid[i][j] - '0') < 10) {
				cnt[(grid[i][j] - '0')]++;
			}
		}
	for (long long i = 1; i <= p; i++) {
			printf("%lld ", cnt[i]);
	}
}
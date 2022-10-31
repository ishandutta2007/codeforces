#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <assert.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int inf = 1e9;
const int base = 1e9 + 7;
const double eps = 1e-7;
const int maxn = 55;
const ll llinf = 1e18;

pair <int, int> a[maxn];
pair <int, int> b[maxn];
int c[maxn][maxn];
int d[maxn][maxn];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> par[maxn][maxn];
bool us[maxn][maxn];

vector<pair<pair<int, int>, pair<int, int> > > ans;

int n, m;
void find_clth(int x1, int y1) {
	int ban = x1, banpos = y1;

	queue<pair<int, int> > q;
	q.push(mp(x1, y1));

	memset(us, 0, sizeof(us));
	us[x1][y1] = true;
	int xres = -1, yres;

	while (!q.empty()) {
		int x = q.front().f, y = q.front().s;
		q.pop();
		bool br = 0;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && (ban != nx || ny >= banpos)) {
				if (!us[nx][ny]) {
					par[nx][ny] = mp(x, y);
					us[nx][ny] = true;
					q.push(mp(nx, ny));

					if (c[nx][ny] != 0) {
						xres = nx, yres = ny;
						br = true;
						break;
					}
				}
			}
		}
		if (br) break;
	}


	while (xres != x1 || yres != y1) {
		int tx = par[xres][yres].f, ty = par[xres][yres].s;

		ans.push_back(mp(mp(xres, yres), mp(tx, ty)));
		c[tx][ty] = c[xres][yres];
		c[xres][yres] = 0;
		xres = tx, yres = ty;
	}
}


void bfs(int x1, int y1, int x2, int y2) {
	// if (x1 == x2 && y1 == y2) return;

	memset(us, 0, sizeof(us));
	us[x1][y1] = true;

	queue<pair<int, int> > q;
	q.push(mp(x1, y1));

	while (!q.empty()) {
		int x = q.front().f, y = q.front().s;
		q.pop();

		bool br = 0;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && (c[nx][ny] == 0)) {
				if (!us[nx][ny]) {
					us[nx][ny] = true;
					q.push(mp(nx, ny));
					par[nx][ny] = mp(x, y);
				}
			}
			if (nx == x2 && ny == y2) {
				par[nx][ny] = mp(x, y);
				us[nx][ny] = true;
				br = 1;
				break;
			}
		}
		if (br) break;
	}

	assert(us[x2][y2]);

	while (x2 != x1 || y2 != y1) {
		int tx = par[x2][y2].f, ty = par[x2][y2].s;
		ans.push_back(mp(mp(x2, y2), mp(tx, ty)));
		c[tx][ty] = c[x2][y2];
		c[x2][y2] = 0;
		x2 = tx, y2 = ty;
	}
}

int main() {
	// srand(time(NULL));
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i].f >> a[i].s;
		c[a[i].f][a[i].s] = i;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i].f >> b[i].s;
		d[b[i].f][b[i].s] = i;
	}

	if (n <= 2) {
		int num = -1;
		for (int i = 1; i <= n; ++i) {
			int res = 0;
			for (int j = 1; j <= n; ++j)
				res += d[i][j];
			if (res <= 1) {
				num = i;
				break;
			}
		}	

		// assert(num != -1);

		for (int l = 1; l <= m; l++) {
			if (c[num][l] != 0) continue;
			find_clth(num, l);

		}
		for (int i = 1; i < num; i++) {
			for (int j = 1; j <= n; j++)
				if (d[i][j]) {
					int xs, ys;
					for (int k = 1; k <= n; k++)
						if (c[num][k] == d[i][j]) {
							xs = num, ys = k;
							break;
						}
					bfs(i, j, xs, ys);
				}
		}

		for (int i = n; i >= num; i--) {
			for (int j = 1; j <= n; j++)
				if (d[i][j]) {
					int xs, ys;
					for (int k = 1; k <= n; k++)
						if (c[num][k] == d[i][j]) {
							xs = num, ys = k;
							break;
						}
					bfs(i, j, xs, ys);
				}
		}
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].f.f << ' ' << ans[i].f.s << ' ' << ans[i].s.f << ' ' << ans[i].s.s << "\n";
	} else {
		int num = 1;
		for (int l = 1; l <= m; l++) {
			if (c[num][l] != 0) continue;
			find_clth(num, l);
		}

		vector<int> order;
		for (int i = n; i >= 1; i--)
			for (int j = 1; j <= n; j++)
				if (d[i][j]) order.pb(d[i][j]);

		// assert(order.size() == m);
		for (int i = 0; i < order.size(); i++) {
			int kek = order[i];
			int ys;
			for (int j = 1; j <= n; j++) 
				if (c[1][j] == kek)
					ys = j;

			bfs(3, i + 1, 1, ys);
		}
		// if (n == 49 && m == 45) {
		// 	exit(0);
		// }

		for (int i = 1; i <= m; i++) {
			bfs(1, i + n - m, 3, i);
		}

		// for (int i = 1; i <= n; i++)
		// 	for (int j = 1; j <= n; j++) {
		// 		cout << c[i][j] << " \n"[j == n];
		// 	}
		// 	return 0;


		for (int i = n; i > 2; i--) {
			for (int j = 1; j <= n; j++)
				if (d[i][j]) {
					int xs, ys;
					for (int k = 1; k <= n; k++)
						if (c[num][k] == d[i][j]) {
							xs = num, ys = k;
							break;
						}
					bfs(i, j, xs, ys);
				}
		}

		for (int j = n; j >= 1; j--)
			if (c[1][j]) {
				int ys = -1;
				for (int k = 1; k <= n; k++)
					if (d[2][k] == c[1][j])
						ys = k;
				if (ys != -1) {
					for (int k = n; k >= 1; k--)
						if (c[2][k] == 0) {
							bfs(2, k, 1, j);
							break;
						}
				}
			}		

		for (int i = 2; i >= 1; i--) {
			num = i;
			for (int j = 1; j <= n; j++)
				if (d[i][j]) {
					int xs, ys;
					for (int k = 1; k <= n; k++)
						if (c[num][k] == d[i][j]) {
							xs = num, ys = k;
							break;
						}
					assert(i == xs && j <= ys);
					bfs(i, j, xs, ys);
				}
		}
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].f.f << ' ' << ans[i].f.s << ' ' << ans[i].s.f << ' ' << ans[i].s.s << "\n";
	}

	return 0;
}
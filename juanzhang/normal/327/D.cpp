#include <bits/stdc++.h>
using namespace std;

#define fir first
#define sec second

typedef pair <int, int> pii;
typedef pair <char, pii> pcp;
const int maxn = 510;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int n, m, nx, ny;
char a[maxn][maxn];
bool vis[maxn][maxn];

vector <pcp> ans;

bool pd(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m && a[x][y] == '.';
}

void write(const int& x) {
	if (x > 9) {
		write(x / 10);
	}
	putchar((x % 10) | 48);
}

void dfs(int x, int y) {
	if (!pd(x, y)) {
		return;
	}
	a[x][y] = '*';
	ans.push_back(make_pair('B', make_pair(x, y)));
	for (int i = 0; i < 4; i++) {
		dfs(x + dx[i], y + dy[i]);
	}
	if (x != nx || y != ny) {
		ans.push_back(make_pair('D', make_pair(x, y)));
		ans.push_back(make_pair('R', make_pair(x, y)));
	}
}

int main() {
	scanf("%d %d", &n, &m);
	gets(a[0]);
	for (int i = 1; i <= n; i++) {
		gets(a[i] + 1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == '.') {
				nx = i, ny = j;
				dfs(i, j);
			}
		}
	}
	write(ans.size());
	putchar('\n');
	for (pcp p : ans) {
		putchar(p.fir), putchar(' ');
		write(p.sec.fir), putchar(' ');
		write(p.sec.sec), putchar('\n');
	}
	return 0;
}
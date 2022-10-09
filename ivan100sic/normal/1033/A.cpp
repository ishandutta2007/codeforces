#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int qx, qy, px, py, tx, ty;
bool blok[1005][1005];
int d[1005][1005];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	cin >> qx >> qy >> px >> py >> tx >> ty;

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (i == qx || j == qy || abs(i-qx) == abs(j-qy))
				blok[i][j] = 1;

	queue<pair<int, int>> q;
	q.push({px, py});
	
	memset(d, 255, sizeof(d));
	d[px][py] = 0;

	while (q.size()) {
		auto p = q.front(); q.pop();
		for (int dx=-1; dx<=1; dx++)
			for (int dy=-1; dy<=1; dy++) {
				int xx = p.first + dx;
				int yy = p.second + dy;

				if (1 <= xx && xx <= n && 1 <= yy && yy <= n && d[xx][yy] == -1) {
					if (!blok[xx][yy]) {
						d[xx][yy] = d[p.first][p.second] + 1;
						q.push({xx, yy});
					}
				}
			}
	}
	cout << (d[tx][ty] != -1 ? "YES\n" : "NO\n");
}
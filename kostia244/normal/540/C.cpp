#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
#define mod 1000000007ll
using namespace std;

int n, m, sx, sy, ex, ey, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
char a[505][505];

void dfs(int x, int y) {
	a[x][y] = '#';
	int tx, ty;
	for(int i = 0; i < 4; i++) {
		tx = x + dx[i];
		ty = y + dy[i];
		if(tx < 1 || ty < 1 || tx > n || ty > m || a[tx][ty] != '.') continue;
		dfs(tx, ty);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i  = 1; i <= n; i++)
		for(int j  = 1; j <= m; j++)
			cin >> a[i][j];
	cin >> sx >> sy >> ex >> ey;
	int tx, ty, c = (a[ex][ey] == 'X'), t = 0;
	dfs(sx, sy);
	for(int i = 0; i < 4; i++) {
		tx = ex + dx[i];
		ty = ey + dy[i];
		if(tx < 1 || ty < 1 || tx > n || ty > m || a[tx][ty] == 'X') continue;
		if(a[tx][ty] == '#') t++;
		c++;
	}
	cout << (t && c > 1 ? "YES" : "NO");
}
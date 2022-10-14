#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1010, mod = 1e9 + 7;
int T, n, m;
char mat[maxn][maxn];
bool single(int i, int j) {
	int ok = 1;
	ok &= !i || mat[i-1][j]!=mat[i][j];
	ok &= !j || mat[i][j-1]!=mat[i][j];
	ok &= j==m-1 || mat[i][j+1]!=mat[i][j];
	ok &= i==n-1 || mat[i+1][j]!=mat[i][j];
	return ok;
}
ll dist[maxn][maxn], p[maxn][maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> T;
	char t;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> t, mat[i][j] = t;
	queue<pair<int, int>> q;
	memset(dist, 0x3f, sizeof dist);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!single(i, j)) q.push({i, j}), dist[i][j] = 0, p[i][j] = mat[i][j] - '0';
		}
	}
	int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for(int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if(tx < 0 || ty < 0 || tx >= n || ty >= m || !single(tx, ty) || dist[tx][ty] <= dist[x][y]+1) continue;
			dist[tx][ty] = dist[x][y] + 1;
			p[tx][ty] = p[x][y];
			q.push(pair<int, int>{tx, ty});
		}
	}
	ll x, y, z;
	while(T--) {
		cin >> x>> y >> z;
		x--, y--;
		if(single(x, y) && dist[x][y] > z) cout << mat[x][y] << '\n';
		else {
			cout << char('0' + ((p[x][y]^z)&1)) << '\n';
		}
	}
}
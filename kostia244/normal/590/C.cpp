#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1010, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, ds[3][3];
array<array<int, maxn>, maxn> d[3];
char mat[maxn][maxn];
void bfs(vector<array<int, 2>> src, array<array<int, maxn>, maxn> &dist) {
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			dist[i][j] = 1<<30;
	queue<array<int, 2>> q;
	for(auto [x, y] : src) {
		dist[x][y] = 0;
		q.push({x, y});
	}
	vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for(int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if(tx < 1 || tx > n || ty < 1 || ty > m || mat[tx][ty] == '#') continue;
			if(dist[tx][ty] == 1<<30) {
				dist[tx][ty] = dist[x][y] + 1;
				q.push({tx, ty});
			}
		}
	}
	//for(int i = 1; i <= n; i++, cout << endl)
	//	for(int j = 1; j <= m; j++)
	//		cout << (dist[i][j]>n+m?-1:dist[i][j]) << " ";
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(ds, 0x3f, sizeof ds);
	cin >> n >> m;
	vector<array<int, 2>> p[3];
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++) {
			cin >> mat[i][j];
			if(mat[i][j]>='1'&&mat[i][j]<='3') {
				p[mat[i][j]-'1'].push_back({i, j});
			}
		}
	for(int i = 0; i < 3; i++) bfs(p[i], d[i]);
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++) {
			if(mat[i][j]>='1'&&mat[i][j]<='3') {
				for(int k = 0; k < 3; k++)
					ds[mat[i][j]-'1'][k] = min(ds[mat[i][j]-'1'][k], d[k][i][j]);
			}
		}
	//for(int i = 0; i < 3; i++)
	//	for(int j = 0; j < 3; j++)
	//		cout << i << " " << j << " " << ds[i][j] << endl;
	ll ans = 1<<30;
	vector<int> ord = {0, 1, 2};
	do {
		ans = min(ans, max(0ll, (ll)ds[ord[0]][ord[1]]-1) + max(0ll, ds[ord[1]][ord[2]]-1ll));
	} while(next_permutation(all(ord)));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ans = min(ans, (ll)d[0][i][j]+d[1][i][j]+d[2][i][j]-2ll);
	if(ans > n*m) ans = -1;
	cout << ans << endl;
}
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 60, mod = 1e9 + 7, i2 = (mod+1)/2;
char mat[maxn][maxn], vis[maxn][maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				cin >> mat[i][j];
		using pi = pair<int, int>;
		queue<pi> q;
		memset(vis, 0, sizeof vis);
		for(int i = 1; i <= n; i++) {
			if(mat[i][n] == '1' && !vis[i][n]) q.push({i, n}), vis[i][n] = 1;
			if(mat[n][i] == '1' && !vis[n][i]) q.push({n, i}), vis[n][i] = 1;
		}
		//cout << " TC \n";
		int dx[] = {-1, 0}, dy[] = {0, -1};
		while(!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			//cout << x << " " << y << '\n';
			for(int i = 0; i < 2; i++) {
				int tx = x+dx[i], ty = y+dy[i];
				if(tx > 0 && tx <= n && ty > 0 && ty <= n && mat[tx][ty] == '1' && !vis[tx][ty]) {
					vis[tx][ty] = 1;
					q.push({tx, ty});
				}
			}
		}
		int ok = 1;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(mat[i][j] == '1') ok &= vis[i][j];
		cout << (ok?"YES\n":"NO\n");
	}
	return 0;
}
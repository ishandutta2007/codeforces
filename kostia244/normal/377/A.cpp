#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k, s = 0, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
	char mat[550][550];
	cin >> n >> m >> k;
	queue<pair<int, int>> fill;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j], s+=(mat[i][j]=='.');
			if(s==1&&mat[i][j]=='.')
				fill.push({i, j});
			if(mat[i][j]=='.')mat[i][j]='X';
		}
	k=s-k-1;
	int x, y;
	while(fill.size()) {
		tie(x, y) = fill.front();
		fill.pop();
		mat[x][y]='.';
		for(int i = 0; k&&i < 4; ++i) {
			int tx = x + dx[i], ty = y + dy[i];
			if(tx<1||tx>n||ty<1||ty>m||mat[tx][ty]!='X') continue;
			mat[tx][ty]='.';
			k--;
			fill.push({tx, ty});
		}
	}
	for (int i = 1; i <= n; i++, cout << "\n")
		for (int j = 1; j <= m; j++)
			cout << mat[i][j];

}
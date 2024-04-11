#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<ll>
#define pi pair<int, int>
using namespace std;
//1 + 1 + 2 + 3 + 4 + 5 + 6 + 8
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
ll n, r1, c1, r2, c2, ans = 100000000000ll, c = 1;
char g[100][100];
int col[100][100];

void dfs(int x, int y) {
	if (col[x][y] != 0 || g[x][y] == '1' || x <= 0 || y <= 0 || x > n || y > n)
		return;
	col[x][y] = c;
	for (int i = 0; i < 4; i++)
		dfs(x + dx[i], y + dy[i]);
}

int main() {
	memset(col, 0, sizeof col);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> r1 >> c1 >> r2 >> c2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> g[i][j];
	dfs(r1, c1);
	if (col[r2][c2] == 1)
		return cout << 0, 0;
	c = 2, dfs(r2, c2);
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++) {
			if(col[i][j] != 1)
				continue;
			for (ll i1 = 1; i1 <= n; i1++)
				for (ll ij = 1; ij <= n; ij++) {
					if(col[i1][ij] != 2)
						continue;
					ans = min(ans, ((i-i1)*(i-i1)) + ((j-ij)*(j-ij)));
				}
		}
	printf("%I64d", ans);
}
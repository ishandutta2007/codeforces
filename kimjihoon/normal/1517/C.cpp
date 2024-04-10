#include <iostream>
#include <algorithm>
using namespace std;

int p[509], ans[509][509], dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= n; i++) {
		int x = i, y = i;
		ans[y][x] = p[i];
		for (int j = 1; j < p[i]; j++) {
			for (int k = 0; k < 4; k++) {
				int tx = x + dx[k], ty = y + dy[k];
				if (tx < 1 || tx > n || ty < 1 || ty > n || tx > ty || ans[ty][tx]) continue;
				ans[ty][tx] = p[i];
				x = tx; y = ty;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
	return 0;
}
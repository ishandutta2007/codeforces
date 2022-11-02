#include <iostream>
#include <algorithm>
using namespace std;

const int M = 1000, inf = 1000000009;
int d[1009], b[1009], c[1009], rd[1009][20009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	for (int i = 1; i <= M; i++)
		d[i] = inf;
	d[1] = 0;
	for (int i = 1; i <= M; i++) 
		for (int j = 1; j <= i; j++)
			if (i + i / j <= M)
				d[i + i / j] = min(d[i + i / j], d[i] + 1);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, k; cin >> n >> k;
		k = min(k, n * 20);
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
			b[i] = d[b[i]];
		}
		for (int i = 1; i <= n; i++)
			cin >> c[i];
		for (int i = 0; i <= k; i++)
			rd[0][i] = -inf;
		rd[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= k; j++) {
				rd[i][j] = rd[i - 1][j];
				if (j >= b[i] && rd[i - 1][j - b[i]] >= 0)
					rd[i][j] = max(rd[i][j], rd[i - 1][j - b[i]] + c[i]);
			}
		}
		int ans = 0;
		for (int i = 0; i <= k; i++)
			ans = max(ans, rd[n][i]);
		cout << ans << '\n';
	}
	return 0;
}
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
using namespace std;

#define fs first
#define sc second
#define pb push_back 
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 500 + 10;
const int mo = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mo)
		if(b & 1) ans = (ll) ans * a % mo;
	return ans;
}
int n, m, q, sum[4][N][N], Map[N], f[N][N][N];
char s[N][N];
int query(int a[N][N], int x1, int y1, int x2, int y2) {
	return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
}
bool judge(int x, int y, int l) {
	int mx = x + (l / 2), my = y + (l / 2);
	int sz = l * l / 4, ex = x + l - 1, ey = y + l - 1;
	if(query(sum[0], x, y, mx - 1, my - 1) != sz) return 0;
	if(query(sum[2], mx, y, ex, my - 1) != sz) return 0;
	if(query(sum[1], x, my, mx - 1, ey) != sz) return 0;
	if(query(sum[3], mx, my, ex, ey) != sz) return 0;
	return 1;
}
int main() {
	Map['R'] = 0; Map['G'] = 1; Map['Y'] = 2; Map['B'] = 3;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; i ++) {
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= m; j ++) {
			sum[Map[s[i][j]]][i][j] = 1;
		}
	}
	for(int k = 0; k < 4; k ++) {
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				sum[k][i][j] += sum[k][i - 1][j] + sum[k][i][j - 1] - sum[k][i - 1][j - 1];
			}
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) if(s[i][j] == 'R') {
			int lim = min(n - i + 1, m - j + 1);
			for(int k = 2; k <= lim; k += 2) {
				if(judge(i, j, k)) {
					f[k][i][j] = 1; break ;
				}
			}
		}
	}
	for(int k = 2; k <= max(n, m); k += 2) {
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				f[k][i][j] += f[k][i - 1][j] + f[k][i][j - 1] - f[k][i - 1][j - 1];
			}
		}
	}
	for(int i = 0; i < q; i ++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int ans = 0, lim = min(x2 - x1 + 1, y2 - y1 + 1);
		for(int k = 2; k <= lim; k += 2) {
			int ex = x2 - k + 1, ey = y2 - k + 1;
			if(query(f[k], x1, y1, ex, ey)) {
				ans = k * k;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
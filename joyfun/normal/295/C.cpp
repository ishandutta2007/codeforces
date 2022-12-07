#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 55;
const int mod = 1e9+7;
int n, K, a[N], cnt[2];
int d[N][N][2], f[N][N][2], C[N][N];
struct Q {
	int x, y, z;
	Q() {}
	Q(int x, int y, int z) : x(x), y(y), z(z) {}
} q[N * N * 2];

void bfs() {
	int qn = 0;
	memset(d, -1, sizeof(d));
	q[qn++] = Q(cnt[0], cnt[1], 0);
	d[cnt[0]][cnt[1]][0] = 0;
	f[cnt[0]][cnt[1]][0] = 1;
	for (int i = 0; i < qn; i++) {
		int x = q[i].x, y = q[i].y, z = q[i].z;
		for (int j = 0; j <= x; j++) {
			if (j * 50 > K) break;
			for (int k = 0; k <= y; k++) {
				if (j + k == 0) continue;
				if (j * 50 + k * 100 > K) break;
				int xx = cnt[0] - q[i].x + j;
				int yy = cnt[1] - q[i].y + k;
				int tmp = 1ll * f[x][y][z] * C[x][j] % mod * C[y][k] % mod;
				if (d[xx][yy][!z] != -1) {
					if (d[x][y][z] + 1 == d[xx][yy][!z]) f[xx][yy][!z] = (f[xx][yy][!z] + tmp) % mod;
					continue;
				}
				d[xx][yy][!z] = d[x][y][z] + 1;
				f[xx][yy][!z] = tmp;
				q[qn++] = Q(xx, yy, !z);
			}
		}
	}
	printf("%d\n%d\n", d[cnt[0]][cnt[1]][1], f[cnt[0]][cnt[1]][1]);
}

int main() {
	for (int i = 0; i < N; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		cnt[x == 100]++;
	}
	bfs();
	return 0;
}
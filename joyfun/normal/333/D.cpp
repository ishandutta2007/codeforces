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

const int N = 1005;
int n, m;

struct Q {
	int x, y, w;
	Q() {}
	Q(int x, int y, int w): x(x), y(y), w(w) {}
	bool operator < (const Q& c) const {
		return w > c.w;
	}
} q[N * N];
int qn;
vi h[N];
int vis[N][N];

int main() {
	scanf("%d%d", &n, &m);
	int x;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &x);
			q[qn++] = Q(i, j, x);
		}
	sort(q, q + qn);
	for (int i = 0; i < qn; i++) {
		for (int j = 0; j < sz(h[q[i].x]); j++) {
			int y1 = h[q[i].x][j];
			int y2 = q[i].y;
			if (y1 > y2) swap(y1, y2);
			if (vis[y1][y2]) {
				printf("%d\n", q[i].w);
				return 0;
			}
			vis[y1][y2]++;
		}
		h[q[i].x].pb(q[i].y);
	}
	return 0;
}
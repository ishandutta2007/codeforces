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

const int N = 105;

int n, m, a[N][N], r[N], c[N], rv[N], cv[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			r[i] += a[i][j];
			c[j] += a[i][j];
		}
	}
	int f = 1;
	while (f) {
		f = 0;
		for (int i = 0; i < n; i++) {
			if (r[i] < 0) {
				r[i] = 0;
				for (int j = 0; j < m; j++) {
					c[j] -= a[i][j];
					a[i][j]  *= -1;
					c[j] += a[i][j];
					r[i] += a[i][j];
				}
				f = 1;
				rv[i] ^= 1;
				break;
			}
		}
		for (int i = 0; i < m; i++) {
			if (c[i] < 0) {
				c[i] = 0;
				for (int j = 0; j < n; j++) {
					r[j] -= a[j][i];
					a[j][i] *= -1;
					r[j] += a[j][i];
					c[i] += a[j][i];
				}
				f = 1;
				cv[i] ^= 1;
				break;
			}
		}
	}
	int rs = 0, cs = 0;
	for (int i = 0; i < n; i++) if (rv[i]) rs++;
	printf("%d", rs); for (int i = 0; i < n; i++) if (rv[i]) printf(" %d", i + 1); printf("\n");
	for (int i = 0; i < m; i++) if (cv[i]) cs++;
	printf("%d", cs); for (int i = 0; i < m; i++) if (cv[i]) printf(" %d", i + 1); printf("\n");
	return 0;
}
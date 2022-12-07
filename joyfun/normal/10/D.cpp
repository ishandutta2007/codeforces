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

const int N = 505;
int n, m, a[N], b[N], f[N], p[N];
int ans[N], an;

int main() {
	scanf("%d", &n); for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%d", &m); for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) {
		int mv = 0;
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				if (f[j] < f[mv] + 1) {
					f[j] = f[mv] + 1;
					p[j] = mv;
				}
			} else if (b[j] < a[i]) {
				if (f[j] > f[mv]) mv = j;
			}
		}
	}
	int mv = 0;
	for (int i = 1; i <= m; i++) if (f[i] > f[mv]) mv = i;
	while (mv) ans[an++] = b[mv], mv = p[mv];
	printf("%d\n", an);
	while (an--) printf("%d ", ans[an]);
	return 0;
}
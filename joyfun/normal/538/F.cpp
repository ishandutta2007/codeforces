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

const int N = 200005;
int n, a[N], f[N], h[N], hn;

struct Q {
	int x, id, f;
	Q() {}
	Q(int x, int id, int f) : x(x), id(id), f(f) {}
};
vector<Q> q[N];
#define lowbit(x) (x&(-x))
int bit[N];
void add(int x, int w) {
	while (x <= hn) {
		bit[x] += w;
		x += lowbit(x);
	}
}

int get(int x) {
	int ans = 0;
	while (x) {
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}

ll ans[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), h[hn++] = a[i];
	sort(h, h + hn); hn = unique(h, h + hn) - h;
	for (int i = 1; i <= n; i++) a[i] = lower_bound(h, h + hn, a[i]) - h + 1;
	for (int i = 1; i <= n - 1; i++) {
		int sn = 1, s = 1;
		int f = 0;
		while (f == 0) {
			for (int j = 1; j <= s; j++) {
				int l = sn + s - j + (j - 1) * i + 1;
				if (l > n) {
					f = 1; break;
				}
				int r = min(l + i - 1, n);
				q[l - 1].pb(Q(a[sn], i, -1));
				q[r].pb(Q(a[sn], i, 1));
				sn++;
			}
			s *= i;
		}
	}
	for (int i = 1; i <= n; i++) {
		add(a[i], 1);
		for (int j = 0; j < sz(q[i]); j++) {
			ans[q[i][j].id] += get(q[i][j].x - 1) * q[i][j].f;
		}
	}
	for (int i = 1; i <= n - 1; i++) printf("%lld ", ans[i]); printf("\n");
	return 0;
}
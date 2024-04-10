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
const int inf = 0x3f3f3f3f;
int n;
map<int, int> h;
pii x[N];
int w[N], H[N];
int bit[N];
#define lowbit(x) (x&(-x))

int get(int x) {
	int ans = 0;
	while (x) {
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}

int add(int x) {
	while (x <= n) {
		bit[x]++;
		x += lowbit(x);
	}
}

int main() {
	scanf("%d", &n);
	int a, b;
	while (n--) {
		scanf("%d%d", &a, &b);
		if (!h.count(a)) h[a] = a;
		if (!h.count(b)) h[b] = b;
		swap(h[a], h[b]);
	}
	n = 0;
	for (map<int, int>::iterator it = h.begin(); it != h.end(); it++)
		x[++n] = mp(it->fi, it->se);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int v = upper_bound(x + 1, x + 1 + n, mp(x[i].se - 1, inf)) - x - 1;
		int vv = i + 1;
		if (x[i].se - 1 > x[i].fi) ans += max(0, x[i].se - 1 - x[i].fi - (v - vv + 1));
		v = upper_bound(x + 1, x + 1 + n, mp(x[i].se, inf)) - x;
		vv = i - 1;
		if (x[i].fi - 1 > x[i].se) ans += max(0, x[i].fi - 1 - x[i].se - (vv - v + 1));
	}
	for (int i = 1; i <= n; i++) w[i] = H[i] = x[i].se;
	sort(H + 1, H + 1 + n);
	for (int i = 1; i <= n; i++) w[i] = lower_bound(H + 1, H + 1 + n, w[i]) - H;
	for (int i = 1; i <= n; i++) {
		ans += get(n) - get(w[i]);
		add(w[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
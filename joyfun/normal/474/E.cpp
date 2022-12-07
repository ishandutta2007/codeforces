#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 100005;
int n, hn;
ll d, h[N], hh[N];
int dp[N];
map<ll, int> hash;
map<ll, int>::iterator it;

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)

struct Node {
	int l, r, Max;
} node[N * 4];

ll abss(ll x) {
	if (x < 0) return -x;
	return x;
}

void build(int l, int r, int x = 0) {
	node[x].l = l; node[x].r = r; node[x].Max = 0;
	if (l == r) {
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, lson(x));
	build(mid + 1, r, rson(x));
}

void pushup(int x) {
	node[x].Max = max(node[lson(x)].Max, node[rson(x)].Max);
}

void add(int v, int val, int x = 0) {
	if (node[x].l == node[x].r) {
		node[x].Max = max(node[x].Max, val);
		return;
	}
	int mid = (node[x].l + node[x].r) / 2;
	if (v <= mid) add(v, val, lson(x));
	if (v > mid) add(v, val, rson(x));
	pushup(x);
}

int query(int l, int r, int x = 0) {
	if (node[x].l >= l && node[x].r <= r)
		return node[x].Max;
	int ans = -INF;
	int mid = (node[x].l + node[x].r) / 2;
	if (l <= mid) ans = max(ans, query(l, r, lson(x)));
	if (r > mid) ans = max(ans, query(l, r, rson(x)));
	return ans;
}

int out[N], on = 0;
int main() {
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &h[i]);
		hh[i] = h[i];
	}
	sort(h + 1, h + n + 1);
	for (int i = 1; i <= n; i++) {
		if (hash.count(h[i])) continue;
		hash[h[i]] = hn++;
	}
	build(0, hn - 1);
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		it = hash.upper_bound(hh[i] - d);
		if (it != hash.begin()) {
			it--;
			int l = it->second;
			int tmp = query(0, l);
			if (tmp)
				dp[i] = max(dp[i], tmp + 1);
		}
		it = hash.lower_bound(hh[i] + d);
		if (it != hash.end()) {
			int r = it->second;
			int tmp = query(r, hn - 1);
			if (tmp)
				dp[i] = max(dp[i], tmp + 1);
		}
		add(hash[hh[i]], dp[i]);
	}
	int ans = 0, ans_v;
	for (int i = 1; i <= n; i++) {
		if (ans < dp[i]) ans = dp[i], ans_v = i;
	}
	printf("%d\n", dp[ans_v]);
	int tot = dp[ans_v];
	ll pre = hh[ans_v];
	out[0] = ans_v;
	on = 1;
	tot--;
	for (int i = ans_v; i >= 1; i--) {
		if (dp[i] == tot && abss(hh[i] - pre) >= d) {
			out[on++] = i;
			pre = hh[i];
			tot--;
		}
	}
	for (int i = on - 1; i >= 0; i--) printf("%d%c", out[i], i == 0 ? '\n' : ' ');
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second

const int N = 100005;
const int inf = 0x3f3f3f3f;
int n, a[N];

#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)
typedef vector<int> vi;

struct Node {
	int l, r, Min;
	vi a;
} node[N<<2];

void meg(vi &c, vi &a, vi &b) {
	int i = 0, j = 0;
	while (i < a.size() || j < b.size()) {
		if (i == a.size()) c.push_back(b[j++]);
		else if (j == b.size()) c.push_back(a[i++]);
		else {
			if (a[i] < b[j]) c.push_back(a[i++]);
			else c.push_back(b[j++]);
		}
	}
}

void build(int l, int r, int x = 1) {
	node[x].l = l; node[x].r = r; node[x].Min = inf;
	if (l == r) {
		scanf("%d", &a[l]);
		node[x].a.push_back(a[l]);
		return;
	}
	int mid = (l + r)>>1;
	build(l, mid, lson(x));
	build(mid + 1, r, rson(x));
	meg(node[x].a, node[lson(x)].a, node[rson(x)].a);
}

struct Q {
	int l, r, id;
	void read(int id) {
		this->id = id;
		scanf("%d%d", &l, &r);
	}

	bool operator < (const Q& c) const {
		return r < c.r;
	}
} q[N * 3];

int m, ans[N * 3], Min;

void ins(int l, int r, int w, int x = 1) {
	if (l > r) return;
	if (node[x].l == node[x].r) {node[x].Min = min(node[x].Min, abs(node[x].a[0] - w)); Min = min(Min, node[x].Min); return;}
	int v = lower_bound(node[x].a.begin(), node[x].a.end(), w) - node[x].a.begin();
	if ((v == 0 || node[x].a[v - 1] + Min <= w) && (v == node[x].a.size() || node[x].a[v] - Min >= w)) {Min = min(Min, node[x].Min); return;}
	int mid = (node[x].l + node[x].r)>>1;
	if (r > mid) ins(l, r, w, rson(x));
	if (l <= mid) ins(l, r, w, lson(x));
	node[x].Min = min(node[lson(x)].Min, node[rson(x)].Min);
}

int get(int l, int r, int x = 1) {
	if (node[x].l >= l && node[x].r <= r) return node[x].Min;
	int mid = (node[x].l + node[x].r)>>1;
	int ans = inf;
	if (l <= mid) ans = min(ans, get(l, r, lson(x)));
	if (r > mid) ans = min(ans, get(l, r, rson(x)));
	return ans;
}

int main() {
	scanf("%d", &n);
	build(1, n);
	scanf("%d", &m); for (int i = 0; i < m; i++) {q[i].read(i); ans[i] = inf;}
	sort(q, q + m);
	int j = 1;
	for (int i = 0; i < m; i++) {
		while (j <= q[i].r) Min = inf, ins(1, j - 1, a[j]), j++;
		ans[q[i].id] = get(q[i].l, q[i].r);
	}
	for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
	return 0;
}
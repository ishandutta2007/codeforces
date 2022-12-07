#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, s[N];
map<int, vector<int> > g;

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)

struct Node {
	int l, r, gcd, Min;
} node[N * 4];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void pushup(int x) {
	node[x].gcd = gcd(node[lson(x)].gcd, node[rson(x)].gcd);
	node[x].Min = min(node[lson(x)].Min, node[rson(x)].Min);
}

void build(int l, int r, int x = 0) {
	node[x].l = l; node[x].r = r;
	if (l == r) {
		node[x].Min = node[x].gcd = s[l];
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, lson(x));
	build(mid + 1, r, rson(x));
	pushup(x);
}

const int INF = 0x3f3f3f3f;
int gc, an, cnt[N];

void query(int l, int r, int x = 0) {
	if (node[x].l >= l && node[x].r <= r) {
		if (an > node[x].Min) {
			an = node[x].Min;
		}
		gc = gcd(gc, node[x].gcd);
		return;
	}
	int mid = (node[x].l + node[x].r) / 2;
	if (l <= mid) query(l, r, lson(x));
	if (r > mid) query(l, r, rson(x));
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
		if (g[s[i]].size() == 0) cnt[i] = 0;
		else cnt[i] = cnt[g[s[i]][g[s[i]].size() - 1]] + 1;
		g[s[i]].push_back(i);
	}
	build(1, n);
	int m;
	scanf("%d", &m);
	int l, r;
	while (m--) {
		scanf("%d%d", &l, &r);
		an = INF;
		gc = 0;
		query(l, r);
		if (an != gc) printf("%d\n", r - l + 1);
		else {
			int left = *lower_bound(g[an].begin(), g[an].end(), l);
			int right = *--upper_bound(g[an].begin(), g[an].end(), r);
			left = cnt[left];
			right = cnt[right];
			printf("%d\n", r - l - right + left);
		}
	}
	return 0;
}
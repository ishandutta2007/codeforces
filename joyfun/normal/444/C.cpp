#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 100005;
typedef long long ll;
inline int lson(int x) {return x<<1;}
inline int rson(int x) {return x<<1|1;}

struct Node {
    int l, r;
    ll sum, col, add;
    int size() {return r - l + 1;}
    int mid() {return (r + l)>>1;}
} node[N * 4];

void pushup(int x) {
    node[x].col = (node[lson(x)].col == node[rson(x)].col?node[lson(x)].col : 0);
    node[x].sum = node[lson(x)].sum + node[rson(x)].sum;
}

void pushdown(int x) {
    if (node[x].add) {
	node[lson(x)].add += node[x].add;
	node[rson(x)].add += node[x].add;
	node[lson(x)].sum += node[x].add * node[lson(x)].size();
	node[rson(x)].sum += node[x].add * node[rson(x)].size();
	node[lson(x)].col = node[rson(x)].col = node[x].col;
	node[x].col = node[x].add = 0;
    }
}

void build(int x, int l, int r) {
    node[x].l = l; node[x].r = r;
    node[x].sum = node[x].col = node[x].add = 0;
    if (l == r) {
	node[x].col = l;
	return;
    }
    build(lson(x), l, node[x].mid());
    build(rson(x), node[x].mid() + 1, r);
    pushup(x);
}

void update(int x, int l, int r, ll col) {
    if (node[x].l >= l && node[x].r <= r && node[x].col) {
	node[x].add += abs(node[x].col - col);
	node[x].sum += abs(node[x].col - col) * node[x].size();
	node[x].col = col;
	return;
    }
    pushdown(x);
    if (l <= node[x].mid())
	update(lson(x), l, r, col);
    if (r > node[x].mid())
	update(rson(x), l, r, col);
    pushup(x);
}

long long query(int x, int l, int r) {
    if (node[x].l >= l && node[x].r <= r)
	return node[x].sum;
    pushdown(x);
    long long ans = 0;
    if (l <= node[x].mid())
	ans += query(lson(x), l, r);
    if (r > node[x].mid())
	ans += query(rson(x), l, r);
    return ans;
}

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    int q, l, r;
    ll x;
    while (m--) {
	scanf("%d", &q);
	if (q == 1) {
	    scanf("%d%d%lld", &l, &r, &x);
	    update(1, l, r, x);
	}
	else {
	    scanf("%d%d", &l, &r);
	    printf("%lld\n", query(1, l, r));
	}
    }
    return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; bool f = 0;
	char c = getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-')f=1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	if (f) x = -x;
}
const int N = 3002000;
int n, op, x, y, l, r;
int id[N], m, cnt;
struct node{
	int l, r;
	int lnum, rnum;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define lnum(x) tree[x].lnum
	#define rnum(x) tree[x].rnum
}tree[N];
#define p1 p << 1
#define p2 p << 1 | 1
ll h[N], ne[N], to[N];
ll w[N], dis[N];
ll d, tot;
inline void add(ll x,ll y,ll z) {
	ne[++tot] = h[x], h[x] = tot;
	w[tot] = z, to[tot] = y;
}
void build(int l,int r,int p) {
	l(p) = l, r(p) = r, lnum(p) = ++cnt, rnum(p) = ++cnt;
	if (l(p) == r(p)) {
		id[l] = ++cnt;
		add(lnum(p), id[l], 0); add(id[l], rnum(p), 0);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, p1); build(mid + 1, r, p2);
	add(lnum(p), lnum(p1), 0); add(rnum(p1), rnum(p), 0);
	add(lnum(p), lnum(p2), 0); add(rnum(p2), rnum(p), 0);
}
void add_e(int l,int r,int k,int p,ll d,ll poi) {
	if (l(p) >= l && r(p) <= r) {
		if (k) add(poi, lnum(p), d);
		else add(rnum(p), poi, d);
		return;
	}
	if (l <= r(p1)) add_e(l, r, k, p1, d, poi);
	if (r >= l(p2)) add_e(l, r, k, p2, d, poi);
}
int q, s;
#include<queue>
#define MP make_pair
priority_queue<pair<ll, int> > qu;
ll INF, v[N];
void diji(void) {
	memset(dis, 0x3f, sizeof(dis)); INF = dis[0];
	dis[id[s]] = 0;
	qu.push(MP(0, id[s]));
	while (qu.size()) {
		int x = qu.top().second; qu.pop();
		if (v[x]) continue; v[x] = 1;
		for (int i = h[x]; i; i = ne[i]) {
			y = to[i];
			if (dis[x] + w[i] < dis[y]) {
				dis[y] = dis[x] + w[i];
				qu.push(MP(-dis[y], y));
			}
		}
	}
}
int main() {
	read(n), read(q), read(s);
	build(1, n, 1);
	while (q--) {
		read(op);
		if (op == 1) {
			read(x), read(y), read(d);
			add(id[x], id[y], d);
		}
		else if (op == 2) {
			read(x), read(l), read(r), read(d);
			add_e(l, r, 1, 1, d, id[x]);
		}
		else {
			read(x), read(l), read(r), read(d);
			add_e(l, r, 0, 1, d, id[x]);
		}
	}
	diji();
	for (int i = 1;i <= n; i++) {
		if (dis[id[i]] < INF)
		printf ("%lld ", dis[id[i]]);
		else printf ("-1 ");
	}
	return 0;
}
/*

3 5 1
2 3 2 3 17
2 3 2 2 16
2 2 2 3 3
3 3 1 1 12
1 3 3 17

*/
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x)
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar('\n');
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

int m, n;

const int N = 100500;
struct node {
	int x, y, val, id;
}q[N<<3];

set<int> s[N];
int Pre(int x, int y) {
	auto it = s[y].lower_bound(x);
	return *(--it);
}

int Aft(int x, int y) {
	auto it = s[y].upper_bound(x);
	return *it;
}

int pre[N], aft[N], t[N], cnt;
void insert(int x, int pr) {
	q[++cnt] = (node) {x, pre[x], pre[x] - x, 0};
	pre[x] = pr;
	q[++cnt] = (node) {x, pre[x], x - pre[x], 0};
}

bool cmp(node a, node b) {
	int ta = (a.id != 0), tb = (b.id != 0);
	if (ta != tb) return ta < tb;
	if (ta) return a.y < b.y;
	return a.x < b.x;
}

ll d[N]; int ask;
void add(int x, int k) {
	if (!x) return;
	for (; x <= n; x += x & -x) d[x] += k;
}

ll query(int x) {
	ll sum = 0;
	for (; x ; x -= x & -x) sum += d[x];
	return sum;
}

ll ans[N], a[N];
void solve(int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;
	solve(l, mid), solve(mid + 1, r);
	int p = l - 1;
	for (int i = mid + 1;i <= r; i++)
		if (q[i].id) {
			while (p < mid && (q[p+1].id || q[p+1].x <= q[i].y))
				if (!q[++p].id) add(q[p].y, q[p].val);
			ans[q[i].id] += query(n) - query(q[i].x-1);
		}
	for (int i = l;i <= p; i++) if (!q[i].id) add(q[i].y, -q[i].val);
	sort(q + l, q + r + 1, cmp);
}

int main() {
	read(n), read(m);
	for (int i = 1;i <= n; i++) { 
		read(a[i]), pre[i] = t[a[i]], t[a[i]] = i;
		s[a[i]].insert(i);
	}
	for (int i = 1;i <= n; i++) 
		s[i].insert(0), s[i].insert(t[i] = n + 1);
	for (int i = n;i >= 1; i--)
		aft[i] = t[a[i]], t[a[i]] = i,
		q[++cnt] = (node) {i, pre[i], i - pre[i], 0};
	while (m--) {
		int op, x, y; read(op), read(x), read(y);
		if (op == 1) {
			if (y == a[x]) continue;
			int pr = Pre(x, y), af = Aft(x, y); 
			s[a[x]].erase(x), s[a[x] = y].insert(x);
			if (aft[x] != n + 1) insert(aft[x], pre[x]);
			if (pre[x] != 0) aft[pre[x]] = aft[x];
			if (pr) aft[pr] = x;
			if (af != n + 1) insert(af, x);
			insert(x, pr), aft[x] = af;
		}
		else q[++cnt] = (node) {x, y, 0, ++ask};
	}
	solve(1, cnt);
	for (int i = 1;i <= ask; i++) write(ans[i]);
	return 0;
}

/*

10 10
8 10 1 4 4 2 1 2 10 1
1 5 6
1 6 8
1 6 1
1 10 5
1 5 8
1 2 8
2 5 6
2 1 5
2 1 2
2 5 8

*/
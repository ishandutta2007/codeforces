
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

#include <queue>
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
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 800050;
struct node {
	int x, y, z, id;
	node (int xx = 0, int yy = 0, int zz = 0, int ii = 0) {
		x = xx, y = yy, z = zz, id = ii;
	}
	bool operator < (const node &i) const {
		if (x != i.x) return x < i.x;
		if (y != i.y) return y < i.y;
		if (z != i.z) return z < i.z;
		return (!id) > (!i.id);
	}
}p[N], q[N];

int d[N], ans[N], pre[N], n;
void add(int x, int c) {
	x++;
	for (; x <= n + 1; x += x & -x) d[x] += c;
}

int sum(int x) {
	int res = 0; x++;
	for (; x; x -= x & -x) res += d[x];
	return res;
}

void solve(int l, int r) {
	if (l >= r) return;
	int mid = (l + r) >> 1;
	solve(l, mid), solve(mid + 1, r);
	int j = l, t1 = l - 1;
	for (int i = mid + 1; i <= r; i++) {
		while (p[j].y <= p[i].y && j <= mid) {
			if (!p[j].id) add(p[j].z, 1);
			q[++t1] = p[j], j++;
		}
		q[++t1] = p[i];
		if (p[i].id < 0) ans[-p[i].id] -= sum(p[i].z);
		if (p[i].id > 0) ans[p[i].id] += sum(p[i].z);
	}
	for (int i = l;i < j; i++) if (!p[i].id) add(p[i].z, -1);
	for (int i = j;i <= mid; i++) q[++t1] = p[i];
	for (int i = l;i <= r; i++) p[i] = q[i];
}

int t[N], vis[N], tp, cnt;
int main() {
	read(n); cnt = n; int fl = 0;
	for (int i = 1;i <= n; i++) {
		read(p[i].x), p[i].y = i, p[i].z = pre[p[i].x], pre[p[i].x] = i, t[i] = p[i].x;
		if (p[i].x != 1) fl = 1;
	}
	if (!fl) return write(1), 0;
	for (int i = 1;i <= n; i++) pre[i] = 0;
	for (int i = 1;i <= n; i++) {
		if (pre[t[i]] != i - 1) {
			p[++cnt] = node(p[i].x - 1, pre[t[i]], pre[t[i]], -i);
			p[++cnt] = node(p[i].x - 1, i, pre[t[i]], i);
		}
		pre[t[i]] = i;
	}
	tp = n;
	for (int i = 1;i <= n + 1; i++) {
		tp++;
		if (pre[i] != n) {
			p[++cnt] = node(i - 1, pre[i], pre[i], -tp);
			p[++cnt] = node(i - 1, n, pre[i], tp);
		}
	}
	sort(p + 1, p + cnt + 1), solve(1, cnt);
	for (int i = 1;i <= n; i++) 
		if (ans[i] == t[i] - 1) vis[t[i]] = 1;
	for (int i = n + 1;i <= n + n + 1; i++)
		if (ans[i] == i - n - 1) vis[i - n] = 1;
	for (int i = 1;i <= n + 1; i++)
		if (!vis[i]) return write(i), 0;
	write(n + 2);
	return 0;
}

/*



*/
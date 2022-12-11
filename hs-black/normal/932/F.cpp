#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define re register
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 200500;
const int Delta = 100005;
const int Len = Delta << 1;


int h[N], ne[N<<1], to[N<<1];
int T[N], tot, cnt;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[tot] = y, h[x] = tot;
}

int ls[N<<5], rs[N<<5], p[N<<5];
ll n, ans[N], a[N], b[N];
struct node {
	ll k, b;
}line[N];

inline ll calc(int num, ll x) {
	return line[num].k * x + line[num].b;
}

void insert(int &x, int l, int r, int num) {
	if (!x) return x = ++cnt, p[x] = num, void();
	int mid = (l + r) >> 1;
	if (calc(p[x], mid) > calc(num, mid)) swap(p[x], num);
	if (calc(p[x], l) <= calc(num, l) && 
		calc(p[x], r) <= calc(num, r)) return;
	if (calc(p[x], l) > calc(num, l)) insert(ls[x], l, mid, num);
	else insert(rs[x], mid + 1, r, num);
}

const ll INF = 0x7fffffffffff;
ll query(int now, int l, int r, ll x) {
	if (!now) return INF;
	int mid = (l + r) >> 1;
	return min(calc(p[now], x), x <= mid ?
		query(ls[now], l, mid, x) : query(rs[now], mid + 1, r, x));
}

int merge(int x, int y, int l, int r) {
	if (!x || !y) return x | y;
	insert(x, l, r, p[y]);
	int mid = (l + r) >> 1;
	ls[x] = merge(ls[x], ls[y], l, mid);
	rs[x] = merge(rs[x], rs[y], mid + 1, r);
	return x;
}

void dfs(int x, int fa) {
	for (re int i = h[x], y; i; i = ne[i]) {
		if ((y = to[i]) == fa) continue;
		dfs(y, x); 
		T[x] = merge(T[x], T[y], 1, Len);
	}
	ans[x] = query(T[x], 1, Len, a[x] + Delta);
	if (ans[x] == INF) ans[x] = 0;
	line[x] = (node){b[x], ans[x] - b[x] * Delta}; 
	insert(T[x], 1, Len, x);
}

int main() {
	read(n);
	for (re int i = 1;i <= n; i++) read(a[i]);
	for (re int j = 1;j <= n; j++) read(b[j]);
	for (re int i = 1;i < n; i++) {
		int x, y; read(x), read(y);
		add(x, y), add(y, x);
	} dfs(1, 0);
	for (re int i = 1;i <= n; i++) 
		write(ans[i]), putchar(' ');
	return 0;
}
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
inline void write(F x)
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(' ');
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y, 0); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }


#define ls son[x][0]
#define rs son[x][1]
const int N = 200500;
int tag[N], val[N], rnd[N], son[N][2], add[N], ans[N], cnt;
int build(int x) {
	val[++cnt] = x, rnd[cnt] = rand();
	return cnt; 
}

void spread(int x) {
	if (tag[x]) {
		if (ls) tag[ls] += tag[x], ans[ls] += tag[x];
		if (rs) tag[rs] += tag[x], ans[rs] += tag[x];
		tag[x] = 0;
	}
	if (add[x]) {
		if (ls) add[ls] += add[x], val[ls] += add[x];
		if (rs) add[rs] += add[x], val[rs] += add[x];
		add[x] = 0;
	}
}

void split(int nw, int k, int &x, int &y) {
	if (!nw) return x = y = 0, void();
	spread(nw);
	if (val[nw] <= k) x = nw, split(rs, k, rs, y);
	else y = nw, split(son[y][0], k, x, son[y][0]);
}

int getmx(int rt) {
	while (son[rt][1]) 
		spread(rt), rt = son[rt][1];
	return val[rt];
}

int merge(int x, int y) {
	if (!x || !y) return x | y;
	if (rnd[x] < rnd[y]) return spread(x), rs = merge(rs, y), x;
	return spread(y), son[y][0] = merge(x, son[y][0]), y;
}

void insert(int &rt, int k) {
	int x, y;
	split(rt, val[k], x, y);
	rt = merge(merge(x, k), y);
}

struct node {
	int c, q;
	bool operator < (const node &i) const {
		if (q != i.q) return q > i.q;
		return c < i.c;
	}
}t[N];

int f[N], b[N], m, n;
bool cmp(int a, int y) {
	return b[a] < b[y];
}

void rebuild(int nw, int &rt) {
	if (!nw) return;
	spread(nw);
	rebuild(son[nw][0], rt);
	rebuild(son[nw][1], rt);
	son[nw][0] = son[nw][1] = 0;
	insert(rt, nw);
}

void spreadit(int x) {
	if (!x) return;
	spread(x);
	spreadit(ls), spreadit(rs);
}

int rt;
int main() {
	read(m);
	for (int i = 1;i <= m; i++) 
		read(t[i].c), read(t[i].q);
	sort(t + 1, t + m + 1);
	read(n);
	for (int i = 1;i <= n; i++) 
		read(b[f[i] = i]), build(b[i]);
	sort(f + 1, f + n + 1, cmp);
	for (int i = 1;i <= n; i++) 
		rt = merge(rt, f[i]);
	for (int i = 1;i <= m; i++) {
		int x, y, z;
		split(rt, t[i].c - 1, x, y);
		if (!y) { rt = x; continue; }
		val[y] -= t[i].c, ans[y]++;
		add[y] -= t[i].c, tag[y]++;
		int mx = getmx(x);
		split(y, mx - 1, z, y);
		rebuild(z, x), rt = merge(x, y);
	}
	spreadit(rt);
	for (int i = 1;i <= n; i++) write(ans[i]);
	return 0;
}

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

const int N = 200500;
struct node {
	int x, y; ll val;
}p[N];

bool cmp(node x, node y) {
	return x.val > y.val;
}


int f[N], vis[N], a[N], b[N], cnt, sz, x, m, n;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main() {
	read(m), read(n);
	for (int i = 1;i <= m; i++) read(a[i]);
	for (int i = 1;i <= n; i++) read(b[i]);
	ll ans = 0, all = 0;
	for (int i = 1;i <= m; i++) {
		read(sz), f[i] = i;
		for (int j = 1;j <= sz; j++) {
			read(x), all += a[i] + b[x];
			p[++cnt] = (node) {i, x, a[i] + b[x]};
		}
	}
	sort(p + 1, p + cnt + 1, cmp);
	for (int i = 1;i <= cnt; i++) {
		int x = find(p[i].x), y = find(vis[p[i].y]);
		if (!y) vis[p[i].y] = x, ans += p[i].val;
		else {
			if (x == y) continue;
			ans += p[i].val, f[y] = x;
		}
	}
	write(all - ans);
	return 0;
}
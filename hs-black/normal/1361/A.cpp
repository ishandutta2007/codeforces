/*

 
| _ _|
 ` _x 
  /  |
 /  c ?
| |||
| (c_c_)_)


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

const int N = 500500;
int ne[N<<1], to[N<<1], vis[N], h[N], id[N], t[N], tot, m, n;
inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }
int main() {
	read(n), read(m);
	for (int i = 1, x, y;i <= m; ++i)
		read(x), read(y), add(x, y), add(y, x);
	for (int i = 1;i <= n; ++i) read(t[i]), id[i] = i;
	sort(id + 1, id + n + 1, [&](int x, int y) { return t[x] < t[y]; });
	for (int k = 1;k <= n; ++k) {
		int x = id[k];
		for (int i = h[x]; i; i = ne[i]) 
			vis[t[to[i]]] = 1;
		int tim = 1;
		while (vis[tim]) ++tim;
		for (int i = h[x]; i; i = ne[i]) 
			vis[t[to[i]]] = 0;
		if (t[x] != tim) return write(-1), 0;
	}
	for (int i = 1;i <= n; ++i) write(id[i], ' ');
	return 0;
}
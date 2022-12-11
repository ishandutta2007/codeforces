
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

const int N = 300050;
ll sum[N], ans; int a[N], h[N], siz[N], to[N], ne[N], tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}
void dfs(int x) {
	sum[x] = a[x];
	if (!h[x]) siz[x] = 1;
	for (int i = h[x]; i ; i = ne[i]) {
		int y = to[i]; dfs(to[i]);
		sum[x] += sum[y], siz[x] += siz[y];
	}
	if (sum[x]) Mx(ans, (sum[x] - 1) / siz[x] + 1);
}

int n;
int main() {
	read(n);
	for (int i = 2, x;i <= n; i++) read(x), add(x, i);
	for (int i = 1;i <= n; i++) read(a[i]);
	dfs(1), write(ans);
	
	return 0;
}
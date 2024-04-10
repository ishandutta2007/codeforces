
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

#define YES puts("YES")
#define NO puts("NO")
const int N = 200500;
int T, n, k, m, vis[N], st[N], sum[N], tp;
int main() {
	for (read(T); T; --T) {
		read(n), read(k), read(m);
		memset(vis, 0, n * 4 + 20), tp = 0;
		for (int i = 1, x;i <= m; i++) read(x), vis[x] = 1;
		if ((n - m) % (k - 1)) { NO; continue; }
		for (int i = 1;i <= n; i++) {
			sum[i] = sum[i-1] + vis[i];
			if (!vis[i]) st[++tp] = i;
		}
		int t = tp / 2, rd = (k - 1) >> 1;
		if ((sum[st[t + 1]] - sum[st[rd]]) || (sum[st[tp - rd + 1]] - sum[st[t]])) YES;
		else NO;
	}
	return 0;
}

/*

1
4 3 2
1 2

*/
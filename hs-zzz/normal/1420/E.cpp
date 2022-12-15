
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

const int N = 82;
int f[N][N][N*N], a[N], n;
int dis(int x, int y) {
	return x - y > 0 ? x - y : y - x; 
}
inline int calc(int n) { return n * (n - 1) / 2; }
int st[N], s[N], tp;
int main() {
	read(n);
	for (int i = 1;i <= n; i++) 
		read(a[i]), a[i] && (st[++tp] = i);
	st[++tp] = n + 1;
	memset(f, 0x3f, sizeof(f)), f[0][0][0] = 0;
	int inf = f[0][0][1] * 2;
	for (int i = 1;i <= n + 1; i++) {
		int lima = min(i, tp);
		for (int j = 1;j <= lima; j++) {
			int lim = min(j * (n - 1), n * (n - 1) / 2), dd = dis(st[j], i);
			for (int k = dd;k <= lim; k++) {
				int pre = inf;
				for (int p = 1;p <= i; p++) {
					int val = f[p-1][j-1][k-dd] + calc(i - p);
					if (val > pre) break;
					Mn(f[i][j][k], pre = val);
				}
			}
			for (int k = 1;k <= lim; k++)
				Mn(f[i][j][k], f[i][j][k-1]);
		}
	}
	int sum = (n - tp + 1) * (n - tp) / 2, lim = n * (n - 1) / 2;
	int (*ans) = f[n+1][tp];
	for (int i = 0;i <= lim; i++)
		write(sum - ans[i], ' '), Mn(ans[i+1], ans[i]);
	return 0;
}
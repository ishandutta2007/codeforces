
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

const int N = 400050;
ll f[10][N], T, n, k, z, a[N];
int main() {
	for (read(T); T; T--) {
		read(n), read(k), read(z);
		for (int i = 1;i <= n; i++) read(a[i]);
		ll ans = 0;
		for (int i = 1;i <= n; i++) f[0][i] = f[0][i-1] + a[i];
		ans = f[0][k + 1];
		for (int t = 1;t <= z; t++) 
			for (int i = 1;i < n; i++) {
				f[t][i] = max(f[t-1][i+1] + a[i], f[t][i-1] + a[i]);
				if (t * 2 + i - 1 == k) Mx(ans, f[t][i]);
			}
		write(ans);
	}
}

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

const int N = 1000500;
int x[N], y[N], cnt, n;
inline void add(int a, int b) {
	x[++cnt] = a, y[cnt] = b;
}
void work(int st, int l) {
	for (int j = 1;j < l; j <<= 1) 
		for (int k = 0;k < l; k += j << 1) 
			for (int t = 0;t < j; t++) 
				add(st + k + t, st + k + t + j);
}

int main() {
//	freopen ("hs.out","w",stdout);
	read(n);
	if (n == 1) { write(0); return 0; }
	if (n == 2) return write(0), 0;
	for (int l = 15;l >= 0; l--) 
		if (n >> l & 1) {
			work(1, 1 << l);
			if (n != (1 << l)) work(n - (1 << l) + 1, 1 << l);
			break;
		}
	write(cnt);
	for (int i = 1;i <= cnt; i++) write(x[i], ' '), write(y[i]);
	return 0;
}
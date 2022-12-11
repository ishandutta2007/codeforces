
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
int T, n, a[N], b[N], c[N], p[N];
int main() {
	for (read(T); T; T--) {
		read(n);
		for (int i = 1;i <= n; i++) read(a[i]);
		for (int j = 1;j <= n; j++) read(b[j]);
		for (int j = 1;j <= n; j++) read(c[j]);
		p[1] = a[1];
		for (int i = 2;i < n; i++) 
			if (a[i] == p[i-1]) p[i] = b[i];
			else p[i] = a[i];
		if (a[n] != p[1] && a[n] != p[n-1]) p[n] = a[n];
		if (b[n] != p[1] && b[n] != p[n-1]) p[n] = b[n];
		if (c[n] != p[1] && c[n] != p[n-1]) p[n] = c[n];
		for (int i = 1;i <= n; i++) write(p[i], ' '); puts("");
	}
	return 0;
}
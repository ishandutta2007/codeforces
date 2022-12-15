
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

const int N = 4000050;
int T, n, q, a[N];
int getit(int i) {
	if (a[i] > a[i-1] && a[i] > a[i+1]) return a[i];
	else if (a[i] < a[i-1] && a[i] < a[i+1]) return -a[i];
	return 0;
}

int main() {
	for (read(T); T; T--) {
		read(n), read(q); a[0] = a[n+1] = -1;
		for (int i = 1;i <= n; i++) read(a[i]);
		ll ans = 0;
		for (int i = 1;i <= n; i++) ans += getit(i);
		write(ans);
		for (int i = 1;i <= q; i++) {
			int x, y; read(x), read(y);
			ans -= getit(x), ans -= getit(y);
			swap(a[x], a[y]);
			ans += getit(x), ans += getit(y);
		}
	}
	return 0;
}
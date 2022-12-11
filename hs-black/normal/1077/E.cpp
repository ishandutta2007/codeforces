
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
ll a[N], siz[N], cnt, n;
int main() {
	read(n);
	for (int i = 1;i <= n; i++) read(a[i]);
	sort(a + 1, a + n + 1);
	for (int l = 1, r = 1;l <= n; l = r + 1, r = l) {
		while (r <= n && a[r+1] == a[r]) r++;
		siz[++cnt] = r - l + 1;
	}
	sort(siz + 1, siz + cnt + 1);
	ll ans = 0;
	for (int j = 1;j <= cnt; j++) {
		for (int i = 1;i <= siz[j]; i++) {
			ll res = i, tp = i;
			int nw = j;
			while (nw < cnt) {
				tp <<= 1, nw++;
				nw = lower_bound(siz + nw, siz + cnt + 1, tp) - siz;
				if (nw > cnt) break;
				res += tp;
			}
			Mx(ans, res);
		}
	}
	write(ans);
	return 0;
}
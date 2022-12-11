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

const int P = 1e9 + 7;
const int N = 1000500;
int t[N], n, p, T;
ll fpw(ll x, ll mi, ll res = 1) {
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}
int main() {
	for (read(T); T; --T) {
		read(n), read(p);
		for (int i = 1;i <= n; ++i) read(t[i]);
		if (p == 1) { write(n & 1); continue; }
		sort(t + 1, t + n + 1);
		int ans = 0;
		for (int r = n, l;r >= 1; r = l - 1) {
			l = r; while (l > 1 && t[l - 1] == t[r]) --l;
			if ((r - l) & 1) continue;
			ll tmp = 1; int nw = t[l];
			while (l > 1 && tmp) {
				--l;
				while (nw > t[l] && tmp <= n) --nw, tmp *= p;
				if (tmp > n) {
					for (int i = l;i >= 1; --i) ans = (ans + P - fpw(p, t[i])) % P;
					break;
				}
				--tmp;
			}
			if (tmp) { ans = (ans + tmp * fpw(p, nw)) % P; break; }
		}
		write(ans);
	}
	return 0;
}
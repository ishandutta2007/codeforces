
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

int T, n, k, l1, l2, r1, r2;
int main() {
//	freopen ("hs.in","r",stdin);
	for (read(T); T; T--) {
		read(n), read(k), read(l1), read(r1), read(l2), read(r2);
		if (l1 >= l2) swap(l1, l2), swap(r1, r2);
		ll rest = k;
		if (l2 <= r1) {
			int t = min(r1, r2) - l2;
			rest -= (ll)t * n;
			if (rest <= 0) { write(0); continue; }
			ll nd = (ll)((max(r2, r1) - l1) - t) * n;
			if (nd >= rest) { write(rest); continue; }
			write(nd + (rest - nd) * 2); continue;
		}
		ll ans = 1e15, st = 0;
		for (int i = 1;i <= n; i++) {
			st += l2 - r1;
			st += min((ll)r2 - l1, rest);
			rest -= min((ll)r2 - l1, rest);
			Mn(ans, st + rest * 2);
			if (!rest) break;
		}
		write(ans);
	}
	return 0;
}
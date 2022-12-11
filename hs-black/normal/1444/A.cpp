
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

const int N = 2000500;
int T; ll p, q;

ll divd(ll pre, ll t) {
	ll ans = 1, tp = pre; int fl = 0;
	for (int i = 2;i * i <= t; i++) {
		if (t % i) continue;
//		if (!fl) {
//			fl = 1;
//			for (int j = 2;j < i; j++) {
//				if (pre % j == 0) { Mx(ans, pre / j); break; }
//			}
//		}
		ll p1 = 1, p2 = 1;
		while (t % i == 0) t /= i, p1 *= i;
		while (tp % i == 0) tp /= i, p2 *= i;
		Mx(ans, pre / p2 * p1 / i);
	}
	if (t != 1) {
		ll p2 = 1;
		while (tp % t == 0) p2 *= t, tp /= t;
		Mx(ans, pre / p2);
	}
	return ans;
}

int main() {
	for (read(T); T; T--) {
		read(p), read(q);
		if (p % q != 0) write(p);
		else write(divd(p, q));
	}
	return 0;
}
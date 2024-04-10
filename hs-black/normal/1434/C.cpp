
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

const int N = 100500;
ll T, a, b, c, d;
ll calc(ll t) {
	ll t1 = (t - 1) / d + 1;
	ll t2 = t - c; t2 = (t2 - 1) / d + 2;
	if (t <= c) t2 = 1;
	ll t3 = t1 - t2 + 1;
	ll p1 = (t2 - 1) * d + 1, p2 = (t1 - 1) * d + 1;
	ll res = t1 * a - (t - p1 + t - p2) * t3 / 2 * b - b * c * (t2 - 1);
	return res;
}

int main() {
	for (read(T); T; T--) {
		read(a), read(b), read(c), read(d);
		if (b * c < a) { puts("-1"); continue; }
		ll t = a / b;
		write(max(a, calc(t / d * d + 1)));
	}
	return 0;
}

/*

1
228 21 11 3

1000000 1 1000000 1



*/
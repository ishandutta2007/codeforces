
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

const int N = 3000500;
ll st[N], h[N], tp, top, n, sum;

void work(int i) {
	ll d = h[i] - top - 1;
	while (tp) {
		int ned = i - st[tp]; d = h[i] - top - 1;
		if (d <= ned) { h[i] -= d, st[tp] += d; break; }
		h[i] -= ned, top++, tp--;
	}
	ll l = 1, r = d;
	while (l <= r) {
		ll mid = (l + r) >> 1, t = h[i] - mid * (i - 1);
		if (top + mid <= t) l = mid + 1;
		else r = mid - 1;
	}
	top += r, h[i] -= r * (i - 1), d = h[i] - top - 1;
	if (d > 0) st[++tp] = d + 1, h[i] -= d;
	if (h[i] == top) st[++tp] = i; top = h[i];
}

int main() {
	read(n);
	for (int i = 1;i <= n; i++) read(h[i]), sum += h[i];
	top = h[1];
	for (int i = 2;i < n; i++) work(i);
	work(n);
	for (int i = n;i >= 1; i--) {
		h[i] = top;
		if (st[tp] == i) tp--;
		else top--;
	}
	for (int i = 1;i <= n; i++) write(h[i], ' '), sum -= h[i];
//	write(sum);
	return 0;
}

/*

20
12 15 16 18 25 36 48 56 78 99 100 115 161 169 206 305 699 705 806 999

*/
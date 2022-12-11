
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

#include <cmath>
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
int a[N], A[N], n, d, b;
bool check(int del) {
	for (int i = 1;i <= n; i++) a[i] = A[i];
	int nw = 1, L = del + 1, R = n - del;
	for (int i = L;i <= R; i++) {
		int nd = b, tim = min(i, n - i + 1);
		while (nd && nw <= n) {
			if (abs(i - nw) <= (ll)d * tim) {
				int t = min(a[nw], nd);
				nd -= t, a[nw] -= t;
				if (!nd) break;
			}
			nw++;
		}
		if (nd) return 0;
	}
	return 1;
}

int main() {
	read(n), read(d), read(b);
	for (int i = 1;i <= n; i++) read(A[i]);
	int l = 0, r = n / 2;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	write(l);
	return 0;
}
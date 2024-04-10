
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
int a[N], n, k;
ll sum[N], pre[N], nxt[N], d[N], mn[N];

ll work(void) {
	ll res = max(0ll, sum[n] - a[1] - d[2]);
	Mx(res, sum[n] - a[2] - d[1]);
	for (int i = 2;i < n; i++) {
		Mx(res, sum[i] - mn[i] + pre[i+1]);
		Mx(res, pre[i+1] + max(sum[i] - d[1], 0ll));
		if (i != n - 1) Mx(res, max(sum[i-1] - d[1], 0ll) + sum[n] - sum[i-1] - a[i+1] - d[i]);
	}
	return res;
}

ll work2(void) {
	ll res = 0;
	for (int i = 2;i < n - 1; i++) 
		Mx(res, nxt[i-1] + sum[n] - sum[i-1] - a[i+1] - d[i]);
	return res;
}

int main() {
	read(n), read(k);
	for (int i = 1;i <= n; i++) 
		read(a[i]), sum[i] = sum[i-1] + a[i];
	mn[0] = 1e15;
	for (int i = 1;i <= n; i++) read(d[i]), mn[i] = min(d[i], mn[i-1]);
	for (int i = n;i >= 1; i--) pre[i] = max(pre[i+1], sum[n] - sum[i-1] - d[i]);
	for (int i = 1;i <= n; i++) nxt[i] = max(nxt[i-1], sum[i] - d[i]);
	ll ans;
	if (k == 0) {
		ans = 0;
		for (int i = 1;i <= n; i++)
			Mx(ans, sum[n] - sum[i-1] - d[i]);
	}
	else if (k == 1) {
		ans = work(); int t = a[1];
		for (int i = 1;i < n; i++) Mn(t, a[i]);
		Mx(ans, sum[n] - t - d[1]);
	}
	else {
		ans = 0;
		for (int i = 1;i <= n; i++)
			Mx(ans, sum[n] - sum[i-1] - d[i]);
		Mx(ans, work()), Mx(ans, work2()), Mx(ans, sum[n] - mn[n-1]);
	}
	if (k != 1)
	for (int i = 1;i <= n; i++)
		Mx(ans, sum[n] - sum[i-1] - d[i]);
	if (k == 0) return write(ans), 0;
	Mx(ans, sum[n-1] - mn[n-1] + max(0ll, a[n] - d[n]));
	Mx(ans, sum[n] - a[1] - d[2] + max(0ll, a[1] - d[1]));
	write(ans);
	return 0;
}

/*

8 2
100 100 100 1 1 10 10 10
111111 11111 11 10000 100 1 10000 10000 

4 15
0 0 0 0
13132 135153 153 135

*/
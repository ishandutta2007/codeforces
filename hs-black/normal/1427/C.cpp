
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

#include <cmath>
const int N = 505000;
int dp[N], r, n;
int t[N], x[N], y[N], mx[N];
int main() {
	read(r), read(n);
	x[0] = 1, y[0] = 1;
	for (int i = 1;i <= n; i++) {
		dp[i] = -191919;
		read(t[i]), read(x[i]), read(y[i]);
		for (int j = i;j >= 0; j--) {
			if (t[i] - t[j] >= r + r) { Mx(dp[i], mx[j] + 1); break; }
			if (abs(x[j] - x[i]) + abs(y[j] - y[i]) + t[j] <= t[i]) Mx(dp[i], dp[j] + 1);
		}
		mx[i] = max(mx[i-1], dp[i]);
	}
	write(mx[n]);
	return 0;
}
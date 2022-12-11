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
inline void write(F x)
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar('\n');
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 2000;
ll a1[N], a2[N], b1[N], b2[N], g[N], d[N], m, n;

void solve(ll x, int n, ll *c1, ll *c2) {
	if (n == 0) return c1[0] = c2[0] = 0, void();
	if (n == 1) return c1[1] = (x == 2), c2[1] = (x == 1), void();
	if (x <= d[n-1]) {
		solve(x, n - 1, c1, c2);
		c1[n] = min(c1[n-1], c2[n-1] + 2);
		c2[n] = min(c1[n-1], c2[n-1]) + 1 + g[n-2];
	}
	else {
		solve(x - d[n-1], n - 2, c1, c2);
		c1[n] = c1[n-2] + 1, c2[n] = c2[n-2];
	}
}

ll Dis(ll x, ll y, int n) {
	if (n <= 1) return x != y;
	if (x <= d[n-1]) {
		if (y > d[n-1]) return min(a1[n-1], a2[n-1]) + 1 + b1[n-2];
		return min(Dis(x, y, n - 1), 
				   min(a1[n-1] + b2[n-1], a2[n-1] + b1[n-1]) + 2);
	}
	return Dis(x - d[n-1], y - d[n-1], n - 2);
}


int main() {
	read(m), read(n), Mn(n, 80ll), d[0] = 1, d[1] = 2;
	for (int i = 2;i <= 80; i++) d[i] = d[i-1] + d[i-2];
	g[1] = g[2] = 1;
	for (int i = 3;i <= 80; i++) g[i] = g[i-2] + 1;
	while (m--) {
		ll x, y; read(x), read(y);
		if (x > y) swap(x, y);
		solve(x, n, a1, a2), solve(y, n, b1, b2);
		write(Dis(x, y, n));
	}
	return 0;
}
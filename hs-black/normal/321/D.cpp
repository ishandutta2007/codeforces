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

const int N = 105;
int a[N][N], b[N][N], n, x;

inline ll jue(ll x) {
	return x > 0 ? x : -x;
}

ll get(int li) {
	ll tp = 0;
	for (int i = 1;i < x; i++)
		tp += jue(a[li][i] + (b[li][x] ? -a[li][i+x] : a[li][i+x])
						   + (b[x][i] ? -a[li+x][i] : a[li+x][i])
						   + (b[x][i] ^ b[li+x][x] ? -a[li+x][i+x] : a[li+x][i+x]));
	tp += (b[li][x] ? -a[li][x] : a[li][x]) + (b[li+x][x] ? -a[li+x][x] : a[li+x][x]);
	return tp;
}

int main() {
	read(n); x = (n + 1) >> 1;
	for (int i = 1;i <= n; i++)
		for (int j = 1;j <= n; j++) read(a[i][j]);
	int all = (1 << x) - 1; ll ans = -1e15;
	for (int i = 0;i <= all; i++) {
		ll res = 0;
		for (int j = 1;j <= x; j++)
			if (i & (1 << (j - 1))) b[x][j] = 1;
			else b[x][j] = 0;
		for (int j = 1;j < x; j++)
			b[x][x+j] = b[x][j] ^ b[x][x];
		for (int j = 1;j <= n; j++)
			res += b[x][j] ? -a[x][j] : a[x][j];
		for (int j = 1;j < x; j++) {
			ll tp = -1e15;
			b[j][x] = 1, b[j + x][x] = !b[x][x], Mx(tp, get(j));
			b[j][x] = 0, b[j + x][x] = b[x][x], Mx(tp, get(j));
			res += tp;
		}
		Mx(ans, res);
	}
	write(ans);
	return 0;
}
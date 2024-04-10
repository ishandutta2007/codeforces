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

ll dp[12][62][2048];
ll (*f)[2048]; 

inline int To(int x) {
	return 1 << x;
}

ll bin[1005], q, tp, B;
ll dfs(int x, int s, int up, int qaq) {
	if (x == 0) return s == 0;
	if (qaq && !up && ~f[x][s]) return f[x][s];
	int lim = up ? bin[x] : B - 1;
	ll sum = 0;
	for (int i = 1;i <= lim; i++)
		sum += dfs(x - 1, s ^ To(i), up && i == lim, 1);
	if (qaq) sum += dfs(x - 1, s ^ 1, up && lim == 0, 1);
	else sum += dfs(x - 1, s, up && lim == 0, 0);
	if (qaq && !up) f[x][s] = sum;
	return sum;
}

ll work(ll res) {
	if (!res) return 1;
	ll x = res; tp = 0;
	f = dp[B];
	while (x) {
		bin[++tp] = x % B;
		x /= B;
	}
	return dfs(tp, 0, 1, 0);
}

int main() {
	read(q); memset(dp, -1, sizeof(dp));
	while (q--) {
		ll l, r; read(B), read(l), read(r);
//		write(work(r)), write(work(l-1));
		write(work(r) - work(l-1));
	}
	return 0;
}

/*

2
5 1 100
2 1 100

*/
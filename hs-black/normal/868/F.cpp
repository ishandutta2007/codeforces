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

const int N = 200500;
ll cnt[N], a[N], ans, L, R, m, n;
ll dp[22][N];
inline void inc(int c) {
	ans += cnt[c] * (cnt[c] - 1) >> 1;
}

inline void dec(int c) {
	ans -= cnt[c] * (cnt[c] - 1) >> 1;
}

ll mov(int l, int r) {
	while (L < l) ans -= --cnt[a[L]], L++;
	while (L > l) L--, ans += cnt[a[L]]++;
	while (R < r) R++, ans += cnt[a[R]]++;
	while (R > r) ans -= --cnt[a[R]], R--;
	return ans;
}

int nw;
void solve(int L, int R, int l, int r) {
	if (L > R || l > r) return;
	int mid = (l + r) >> 1;
	ll res = 1e18, d = L;
	for (int i = L;i <= min(R, mid); i++) {
		ll tp = mov(i + 1, mid);
		if (res > dp[nw-1][i] + tp) 
			res = dp[nw-1][i] + tp, d = i;
	}
	dp[nw][mid] = res;
	solve(L, d, l, mid - 1), solve(d, R, mid + 1, r);
}

int main() {
	memset(dp, 0x3f, sizeof(dp));
	read(n), read(m); dp[0][0] = 0;
	for (int i = 1;i <= n; i++) read(a[i]);
	cnt[a[L = R = 1]]++;
	for (int i = 1;i <= m; i++) 
		nw = i, solve(0, n - 1, 1, n);
	write(dp[m][n]);
	return 0;
}
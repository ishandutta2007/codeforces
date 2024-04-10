
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

const int N = 3005;
ll f[N][N], dp[N], t[N], Ans, n, k;
void solve(int l, int r) {
	if (l == r) {
		for (int i = 0;i <= t[l]; i++) 
			Mx(Ans, dp[k-i] + f[l][i]);
		return;
	}
	int mid = (l + r) >> 1; ll tmp[N];
	memcpy(tmp, dp, k * 8 + 16);
	for (int i = l;i <= mid; i++) 
		for (int j = k;j >= t[i]; j--)
			Mx(dp[j], dp[j - t[i]] + f[i][t[i]]);
	solve(mid + 1, r); 
	memcpy(dp, tmp, k * 8 + 16);
	for (int i = mid + 1;i <= r; i++) 
		for (int j = k;j >= t[i]; j--)
			Mx(dp[j], dp[j - t[i]] + f[i][t[i]]);
	solve(l, mid);
	memcpy(dp, tmp, k * 8 + 16);
}

int main() {
//	freopen ("hs.in","r",stdin);
	read(n), read(k);
	for (int i = 1;i <= n; i++) {
		read(t[i]); int res = min(t[i], k);
		for (int j = 1;j <= res; j++) read(f[i][j]), f[i][j] += f[i][j-1];
		for (int j = res + 1;j <= t[i]; j++) read(f[0][0]);
		t[i] = res;
	}
	solve(1, n), write(Ans);
	return 0;
}

/*

1 100
19 717 1522 2592 2895 3542 3974 5395 5603 5625 9701 10549 10884 11091 11397 12482 13186 16198 16338 18377

*/
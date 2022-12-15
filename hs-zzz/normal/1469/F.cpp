/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
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

const int N = 400500;
int n, k, l[N], dep = 1;

#define ls p << 1
#define rs p << 1 | 1
ll d[N], sum[N<<2], add[N<<2];
inline void Tag(int p, int l, int r, int c) {
	sum[p] += 1ll * (r - l + 1) * c, add[p] += c;
}
inline void spread(int p, int l, int mid, int r) {
	add[ls] += add[p], add[rs] += add[p];
	sum[ls] += add[p] * (mid - l + 1);
	sum[rs] += add[p] * (r - mid);
	add[p] = 0;
}

inline void change(int p, int l, int r, int L, int R, int c) {
	if (L <= l && r <= R) return Tag(p, l, r, c);
	int mid = (l + r) >> 1; spread(p, l, mid, r);
	if (L <= mid) change(ls, l, mid, L, R, c);
	if (R > mid) change(rs, mid + 1, r, L, R, c);
	sum[p] = sum[ls] + sum[rs];
}

inline int query(int p, int l, int r, int x) {
	if (l == r) return sum[p];
	int mid = (l + r) >> 1; spread(p, l, mid, r);
	if (x <= mid) return query(ls, l, mid, x);
	return query(rs, mid + 1, r, x);
}

inline int split(int p, int l, int r, int t) {
	if (sum[p] < t) return 1e9;
	if (l == r) return l;
	int mid = (l + r) >> 1; spread(p, l, mid, r);
	if (sum[ls] >= t) return split(ls, l, mid, t);
	return split(rs, mid + 1, r, t - sum[ls]);
}

int main() {
	read(n), read(k); ll sum = 1, ans = 1e9;
	for (int i = 1;i <= n; i++) read(l[i]), sum += l[i];
	sort(l + 1, l + n + 1), sum -= n * 2;
	if (sum < k) return write(-1), 0;
	int nw = 1, ad = 0, lim = 4e5;
	change(1, 1, lim, 1, 1, 1);
	for (int i = n;i >= 1; i--) {
		while (!nw) ++dep, ad += d[dep], nw = ad;
		int tl = (l[i] - 1) >> 1, tr = l[i] >> 1;
		nw--, change(1, 1, lim, dep, dep, -1);
		d[dep + 2] += 2, d[dep + 2 + tl]--, d[dep + 2 + tr]--;
		change(1, 1, lim, dep + 2, dep + tl + 1, 1);
		change(1, 1, lim, dep + 2, dep + tr + 1, 1);
		Mn(ans, 1ll * split(1, 1, lim, k));
	}
	write(ans - 1);
	return 0;
}
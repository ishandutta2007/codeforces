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

const int N = 205000;
int tag[N<<2], sum[N<<2];
char s[N], t[N];
#define ls p << 1
#define rs ls | 1
void spread(int p, int l, int r, int mid) {
	if (tag[p] == -1) return;
	if (tag[p] == 1) sum[ls] = mid - l + 1, sum[rs] = r - mid;
	else sum[ls] = sum[rs] = 0;
	tag[ls] = tag[rs] = tag[p], tag[p] = -1;
}

void build(int p, int l, int r) {
	tag[p] = -1;
	if (l == r) return sum[p] = t[l] - '0', void();
	int mid = (l + r) >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	sum[p] = sum[ls] + sum[rs];
}

void change(int p, int l, int r, int L, int R, int c) {
	if (L <= l && r <= R) {
		tag[p] = c; sum[p] = c ? r - l + 1 : 0;
		return;
	}
	int mid = (l + r) >> 1; spread(p, l, r, mid);
	if (L <= mid) change(ls, l, mid, L, R, c);
	if (R > mid) change(rs, mid + 1, r, L, R, c);
	sum[p] = sum[ls] + sum[rs];
}

int query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return sum[p];
	int mid = (l + r) >> 1; spread(p, l, r, mid);
	int res = 0;
	if (L <= mid) res += query(ls, l, mid, L, R);
	if (R > mid) res += query(rs, mid + 1, r, L, R);
	return res;
}

int fl;
void spr(int p, int l, int r) {
	if (l == r) return fl &= sum[p] == s[l] - '0', void();
	int mid = (l + r) >> 1; spread(p, l, r, mid);
	spr(ls, l, mid), spr(rs, mid + 1, r);
}

int l[N], r[N], T, n, q;
int main() {
	for (read(T); T; T--) {
		read(n), read(q);
		scanf ("%s", s + 1);
		scanf ("%s", t + 1);
		for (int i = 1;i <= q; ++i) read(l[i]), read(r[i]);
		build(1, 1, n);
		fl = 1;
		for (int i = q;i >= 1; --i) {
			int t = query(1, 1, n, l[i], r[i]), len = r[i] - l[i] + 1;
			int md = len >> 1;
			if (md + md == len) md--;
			if (t > md && len - t > md) { fl = 0; break; }
			if (t <= md) change(1, 1, n, l[i], r[i], 0);
			else change(1, 1, n, l[i], r[i], 1);
		}
		spr(1, 1, n);
		if (!fl) { puts("NO"); continue; }
		puts("YES");
	}
	return 0;
}

/*

1
10 6
1111111111
0110001110
1 10
5 9
7 10
1 7
3 5
6 10


*/
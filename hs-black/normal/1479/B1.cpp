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

const int N = 100500;
int a[N], n;
#define ls p << 1
#define rs ls | 1
int tag[N<<2], mx[N<<2], add[N<<2];
inline void Tag(int p, int t, int a) {
	if (t) tag[p] = 1, mx[p] = add[p] = 0;
	else mx[p] += a, add[p] += a;
}
void spread(int p) {
	Tag(ls, tag[p], add[p]);
	Tag(rs, tag[p], add[p]);
	add[p] = tag[p] = 0;
}

void change(int p, int l, int r, int x, int t) {
	if (l == r) return Mx(mx[p], t);
	int mid = (l + r) >> 1; spread(p);
	if (x <= mid) change(ls, l, mid, x, t);
	if (x > mid) change(rs, mid + 1, r, x, t);
	Mx(mx[p], t);
}

int query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return mx[p];
	int mid = (l + r) >> 1, res = 0; spread(p);
	if (L <= mid) Mx(res, query(ls, l, mid, L, R));
	if (R > mid) Mx(res, query(rs, mid + 1, r, L, R));
	return res;
}

int main() {
	read(n);
	for (int i = 1;i <= n; ++i) read(a[i]);
	for (int i = 1;i <= n; ++i) {
		int t = 0;
		Mx(t, query(1, 0, n, 0, a[i] - 1));
		if (a[i] != n) Mx(t, query(1, 0, n, a[i] + 1, n));
		++t, Mx(t, query(1, 0, n, a[i], a[i]));
		if (a[i] != a[i-1]) Tag(1, 0, 1);
		change(1, 0, n, a[i-1], t);
	}
	write(mx[1]);
	return 0;
}
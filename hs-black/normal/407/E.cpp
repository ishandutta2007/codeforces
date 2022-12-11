
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

const int N = 300500;
int t1, t2, L, R, n, k, d;
int s1[N], s2[N], a[N];
int add[N<<2], mn[N<<2];

#define ls p << 1
#define rs ls | 1
inline void spread(int p) {
	mn[ls] += add[p];
	mn[rs] += add[p];
	add[ls] += add[p], add[rs] += add[p];
	add[p] = 0; 
}

void change(int p, int l, int r, int L, int R, int k) {
	if (L <= l && r <= R) return add[p] += k, mn[p] += k, void();
	int mid = (l + r) >> 1; spread(p);
	if (L <= mid) change(ls, l, mid, L, R, k);
	if (R > mid) change(rs, mid + 1, r, L, R, k);
	mn[p] = min(mn[ls], mn[rs]);
}

void update(int l, int r) {
	if (r - l < R - L) return;
	if (r - l > R - L) return R = r, L = l, void();
	if (l < L) R = r, L = l;
}

int visit, now;
void query(int p, int l, int r) {
	if (l == r) return update(l, now);
	int mid = (l + r) >> 1; spread(p);
	if (mn[ls] <= k) query(ls, l, mid);
	else query(rs, mid + 1, r);
}

void query(int p, int l, int r, int L, int R) {
	if (visit || mn[p] > k) return;
	if (L <= l && r <= R) return visit = 1, query(p, l, r);
	int mid = (l + r) >> 1; spread(p);
	if (L <= mid) query(ls, l, mid, L, R);
	if (mid < R) query(rs, mid + 1, r, L, R);
}

#include <map>
map<int, int> mp;
void solve(int l, int r) {
	t1 = t2 = 0; mp.clear();
	s1[0] = s2[0] = l - 1; int mx = l; 
	for (int i = l;i <= r; i++) {
		while (t1 && a[s1[t1]] < a[i]) change(1, 1, n, s1[t1-1] + 1, s1[t1], -a[s1[t1]]), t1--;
		while (t2 && a[s2[t2]] > a[i]) change(1, 1, n, s2[t2-1] + 1, s2[t2], a[s2[t2]]), t2--;
		s1[++t1] = i, s2[++t2] = i;
		change(1, 1, n, s1[t1-1] + 1, i, a[i]);
		change(1, 1, n, s2[t2-1] + 1, i, -a[i]);
		if (i != 1) change(1, 1, n, 1, i - 1, -1);
		now = i; Mx(mx, mp[a[i]] + 1);
		visit = 0, query(1, 1, n, mx, i), mp[a[i]] = i;
	}
}

int main() {
	read(n), read(k), read(d); R = -1;
	for (int i = 1;i <= n; i++) read(a[i]);
	if (d == 0) {
		for (int l = 1, r = 1;l <= n; l = r) {
			while (r <= n && a[r] == a[l]) r++;
			update(l, r - 1);
		}
		write(L, ' ' ), write(R);
		return 0;
	}
	for (int l = 1, r = 1;l <= n; l = r) {
		int t = (a[l] % d + d) % d;
		while (r <= n && (a[r] % d + d) % d == t) 
			a[r] = (a[r] - t) / d, r++;
		solve(l, r - 1);
	}
	write(L, ' '), write(R);
	return 0;
}

/*

20 1 1
1 7 8 9 6 3 2 5 6 9 8 7 1 5 5 3 2 6 9 8

*/
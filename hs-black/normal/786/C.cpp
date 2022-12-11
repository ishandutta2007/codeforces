#pragma GCC optimize(3, "inline")
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

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }


const int N = 200500;
int c[N], pre[N], T[N], cnt, n;
int sum[N<<5], ls[N<<5], rs[N<<5];

int update(int nw, int l, int r, int x, int k) {
	int rt = ++cnt; sum[rt] = sum[nw] + k;
	if (l == r) return rt;
	ls[rt] = ls[nw], rs[rt] = rs[nw];
	int mid = (l + r) >> 1;
	if (x <= mid) ls[rt] = update(ls[nw], l, mid, x, k);
	else rs[rt] = update(rs[nw], mid + 1, r, x, k);
	return rt;
}

int query(int nw, int l, int r, int k) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if (sum[rs[nw]] > k) return query(rs[nw], mid + 1, r, k);
	return query(ls[nw], l, mid, k - sum[rs[nw]]);
}

int main() {
	read(n);
	for (int i = 1;i <= n; i++) {
		read(c[i]); T[i] = T[i-1];
		pre[c[i]] && (T[i] = update(T[i-1], 1, n, pre[c[i]], -1));
		pre[c[i]] = i, T[i] = update(T[i], 1, n, i, 1);
	}
	
	for (int i = 1;i <= n; i++) {
		int nw = n, cnt = 1;
		while (sum[T[nw]] > i) 
			nw = query(T[nw], 1, n, i), cnt++;
		printf ("%d ", cnt);
	}
	
	return 0;
}
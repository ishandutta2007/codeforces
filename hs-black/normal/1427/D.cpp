
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

const int N = 2005;
int L[N], R[N], p[N], tp;
int ans[N][10], st[N], q, n;

void shrink(void) {
	int t = 0;
	for (int i = 1;i <= n; i++) {
		if (p[i] == p[i-1] + 1) R[t]++;
		else ++t, L[t] = R[t] = p[i];
	}
	tp = t;
}
int sum(int l, int r) {
	int res = 0;
	for (int i = l;i <= r; i++) res += R[i] - L[i] + 1;
	return res;
}

void doit(int k) {
	int t = 0;
	for (int i = 1;i <= tp; i++) 
		for (int j = L[i];j <= R[i]; j++)
			st[++t] = j;
	int nw = n + 1, pp = 0;
	for (int i = 1;i <= k; i++) {
		int tq = ans[q][i];
		nw = nw - tq;
		for (int j = 1;j <= tq; j++) 
			p[nw + j - 1] = st[++pp];
	}
}

int main() {
	read(n); L[0] = R[0] = -1; p[0] = -1;
	for (int i = 1;i <= n; i++) read(p[i]), L[i] = R[i] = i;
	shrink(); if (tp == 1) { write(0); return 0; }
	for (int i = 1;i <= 100; i++) {
		int t = 1, p = 2;
		if (L[1] == 1) p = 3, t = 2;
		for ( ;p <= tp; p++) 
			if (R[p] == L[t] - 1) break;
		++q; int k = 0;
		if (p == tp) {
			if (t == 1) {
				ans[q][++k] = sum(1, tp - 1);
				ans[q][++k] = R[p] - L[p] + 1;
			}
			else {
				ans[q][++k] = sum(1, t - 1);
				ans[q][++k] = sum(t, p - 1);
				ans[q][++k] = sum(p, p);
			}
		}
		else if (t == 1) {
			ans[q][++k] = sum(1, p - 1);
			ans[q][++k] = sum(p, p);
			ans[q][++k] = sum(p + 1, tp);
		}
		else {
			ans[q][++k] = sum(1, t - 1);
			ans[q][++k] = sum(t, p - 1);
			ans[q][++k] = sum(p, p);
			ans[q][++k] = sum(p + 1, tp);
		}
		doit(k), shrink();
		if (tp == 1) break;
	}
	write(q);
	for (int i = 1;i <= q; i++) {
		int t = 0;
		while (ans[i][t+1]) t++;
		write(t, ' ');
		for (int j = 1;j <= t; j++) write(ans[i][j], ' ');
		puts("");
	}
	return 0;
}
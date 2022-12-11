#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
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
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}


const int N = 500500;
int gs[N], fs[N], n, m;
int f[N], g[N], ft[N], gt[N];
char opt[5];

int find(int *f, int x) { while (x ^ f[x]) x = f[x]; return x; }

inline void merge(int *f, int *siz, int *t, int x, int y, int k) {
	x = find(f, x), y = find(f, y);
	if (siz[x] < siz[y]) swap(x, y);
	siz[x] += siz[y], f[y] = x, t[y] = k;
}

int cls[N];
vector<pair<int, ll> > add[N];
#define MP make_pair

int main() {
	read(n), read(m);
	for (int i = 1;i <= n; i++) fs[f[i] = g[i] = i] = gs[i] = 1, add[i].push_back(MP(-1, 0));
	for (int i = 1;i <= m; i++) {
		scanf ("%s", opt); int x, y; read(x);
		switch (opt[0]) {
			case 'U' : read(y), merge(f, fs, ft, x, y, i); break;
			case 'M' : read(y), merge(g, gs, gt, x, y, i); break;
			case 'A' : { int k = find(f, x); add[k].push_back(MP(i, fs[k] + add[k].back().second)); break; }
			case 'Z' : { int k = find(g, x); cls[k] = i; break; }
			case 'Q' : {
				int fx = x, tag = cls[x];
				while (g[fx] != fx) {
					if (cls[g[fx]] > gt[fx]) tag = max(tag, cls[g[fx]]);
					fx = g[fx];
				}
				fx = x;  int l = lower_bound(add[x].begin(), add[x].end(), MP(tag, 0ll)) - add[x].begin();
				ll ans = add[x].back().second - add[x][l-1].second;
				while (f[fx] != fx) {
					int tf = f[fx];
					l = lower_bound(add[tf].begin(), add[tf].end(), MP(max(tag, ft[fx]), 0ll)) - add[tf].begin();
					ans += add[tf].back().second - add[tf][l-1].second; fx = f[fx];
				}
				printf ("%lld\n", ans);
			}
		}
	}
	return 0;
}
/*
2 7
A 1
Q 1
U 1 2
A 1
Z 1
Q 1
Q 2

*/
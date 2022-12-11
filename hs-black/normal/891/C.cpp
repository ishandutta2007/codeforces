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


const int N = 1000500;
int X[N], Y[N], top;

struct node {
	int x, y, w, num;
	bool operator < (const node &i) const {
		return w < i.w;
	}
}ed[N];

int ans[N], f[N], m, q, n;

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

int tx[N], ty[N], w[N];
int main() {
	read(n), read(m); int lim = 0;
	for (int i = 1;i <= n; i++) f[i] = i;
	for (int i = 1;i <= m; i++) 
		read(ed[i].x), read(ed[i].y), read(ed[i].w), ed[i].num = i, w[i] = ed[i].w;
	sort(ed + 1, ed + m + 1);
	for (int i = 1, nxt;i <= m; ) {
		nxt = i;
		while (ed[nxt].w == ed[i].w) {
			int nn = ed[nxt].num;
			tx[nn] = find(ed[nxt].x),
			ty[nn] = find(ed[nxt].y);
			nxt++;
		}
		for (; i < nxt; i++) {
			int x = find(ed[i].x), y = find(ed[i].y);
			if (x != y) f[y] = x;
		}
	}
	
	read(q);
	for (int i = 1;i <= n; i++) f[i] = i;
	while (q--) {
		int k; read(k);
		vector<node> v;
		for (int i = 1, x;i <= k; i++) 
			read(x), v.push_back((node){tx[x], ty[x], w[x]});
		sort(v.begin(), v.end());
		bool fl = 1;
		for (int i = 0, j; i < k && fl;) {
			j = i;
			while (j < k && v[j].w == v[i].w) {
				int x = find(v[j].x), y = find(v[j].y);
				if (x == y) { fl = 0; break; }
				f[x] = y; j++;
			}
			while (i < j) f[v[i].x] = v[i].x, f[v[i].y] = v[i].y, i++;
		}
		puts(fl ? "YES" : "NO");
	}
	
	return 0;
}
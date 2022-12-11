#include<iostream>
#include<cstring>
#include<cstdio>
#define lc son[x][0]
#define rc son[x][1]
#define I inline
#define ll long long
using namespace std;
const int N = 300005;
int read(void) {
	int x = 0; bool f = 0;
	char c = getchar(); 
	for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return f ? -x : x;
}

int k[N], f[N];
int siz[N], n, m;
int tag[N], son[N][2];

I bool nroot(int x) {
	return son[f[x]][0] == x || son[f[x]][1] == x;
}

I void update(int x) {
	siz[x] = siz[lc] + siz[rc] + 1;
}

I void spread(int x) {
	if (!tag[x]) return;
	swap(lc, rc);
	tag[lc] ^= 1, tag[rc] ^= 1;
	tag[x] = 0; 
}

I void rotate(int x) {
	int y = f[x], z = f[y];
	int k = son[y][1] == x, w = son[x][k^1];
	if (nroot(y)) son[z][son[z][1]==y] = x;
	son[x][k^1] = y, son[y][k] = w;
	if (w) f[w] = y; f[y] = x, f[x] = z;
	update(y); 
}

int st[N];

I void splay(int x) {
	int y = x, z = 0; st[++z] = y;
	while (nroot(y))  st[++z] = y = f[y];
	while (z) spread(st[z--]);
	while (nroot(x)) {
		y = f[x], z = f[y];
		if (nroot(y)) {
			if ((son[y][0]==x)^(son[z][0]==y))
				rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
	update(x);
}

I void access(int x) {
	for (int y = 0; x; x = f[y = x]) 
		splay(x), son[x][1] = y;
}

I void makeroot(int x) {
	access(x); splay(x);
	tag[x] ^= 1;
}

I void split(int x,int y) {
	makeroot(x);
	access(y); splay(y);
}

I void link(int x,int y) {
	makeroot(x); f[x] = y;
}

I void cut(int x,int y) {
	split(x, y); f[x] = son[y][0] = 0;
}

I int find(void) {
	spread(n + 1);
	int x = son[n + 1][0];
	spread(x);
	while (son[x][1]) {
		x = son[x][1];
		spread(x);
	}
	return x;
}
int main() {
	n = read(),	m = read();
	for (int i = 1;i <= n+1; i++) siz[i] = 1;
	for (int i = 1;i <= n; i++) {
		k[i] = read(); link(i, min(i+k[i], n+1));
	}
	for (int i = 1;i <= m; i++) {
		int opt = read(), x = read();
		if (opt == 1) {
			split(x, n+1); printf ("%d %d\n", find(), siz[n+1]-1);
		}
		else {
			cut(x, min(x + k[x], n + 1)); 
			link(x, min(n + 1, (k[x] = read()) + x));
		}
	}
	return 0;
}
#include<iostream>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<algorithm>
using namespace std;
template <typename T> 
void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	x *= f;
}
const int N = 100500;
const int M = 1005000;
/*
int h[N], ne[N<<1], to[N<<1];
int w[N<<1], tot;
inline void add(int x,int y,int z) {
	ne[++tot] = h[x], h[x] = tot;
	w[tot] = z, to[tot] = y;
}*/

struct node{
	int x, y;
	int w;
	bool operator < (const node &i) const {
		return w > i.w;
	}
}e[M];

long long n, m;


int f[N], a[N];
long long ans = 0;
int siz[N];
int find(int x) {
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}


int main() {
	read(n), read(m);
	for (int i = 1;i <= n; i++) f[i] = i, siz[i] = 1;
	for (int i = 1;i <= n; i++) read(a[i]);
	for (int i = 1;i <= m; i++) {
		int x, y;
		read(x), read(y);
		e[i] = (node){x, y, min(a[x], a[y])};
	}
	sort(e + 1,e + m + 1);
	for (int i = 1;i <= m; i++) {
		int fx = find(e[i].x), fy = find(e[i].y);
		if (fx == fy) continue;
		f[fx] = fy;
		ans += (long long)siz[fx] * siz[fy] * e[i].w;
		siz[fy] += siz[fx];
	}
	cout << setprecision(6) << (long double) ans * 2  / (long double)(n * (n-1)) << endl;
	return 0;
}
/*
4 5
40 20 30 40
1 2
2 3
1 3
2 4
3 4

*/
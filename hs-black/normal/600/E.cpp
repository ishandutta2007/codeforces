#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N = 100500;
ll col[N], son[N];
ll ans[N], t[N];
int h[N], ne[N<<1], to[N<<1];
ll siz[N], tot, n;
inline void add(int x,int y) {
	ne[++tot] = h[x];
	h[x] = tot, to[tot] = y;
}
void getw(int x,int fa) {
	siz[x] = 1;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		getw(y, x);
		siz[x] += siz[y];
		if (siz[son[x]] < siz[y]) son[x] = y;
	}
}

ll Top, sum;

void Dfs(int x,int fa) {
	t[col[x]]--;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i];
		if (y == fa) continue;
		Dfs(y, x);
	}
}
template <typename T>
void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (;!isdigit(c);c=getchar())if (c=='-')f=-1;
	for (;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if (f==-1)x=-x;
}

void ddfs(int x,int fa) {
	t[col[x]]++;
	if (t[col[x]] > Top) {
		Top = t[col[x]];
		sum = col[x];
	}
	else if (t[col[x]] == Top) 
		sum += col[x];
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i];
		if (y == fa) continue;
		ddfs(y, x);
	}
}

void dfs(int x,int fa) {
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; 
		if (y == fa || y == son[x]) continue;
		dfs(y, x); Dfs(y, x);
		sum = Top = 0;
	}
	if (son[x]) dfs(son[x], x);
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; 
		if (y == fa || y == son[x]) continue;
		ddfs(y, x);
	}
	t[col[x]]++;
	if (t[col[x]] > Top) {
		Top = t[col[x]];
		sum = col[x];
	}
	else if (t[col[x]] == Top) 
		sum += col[x];
	ans[x] = sum;
}

int main() {
	read(n);
	for (int i = 1;i <= n; i++) read(col[i]);
	for (int i = 1;i < n; i++) {
		int x, y; read(x), read(y);
		add(x, y); add(y, x);
	}
	getw(1, 0);	dfs(1, 0);
	for (int i = 1;i <= n; i++) printf ("%lld ", ans[i]);
	return 0;
}
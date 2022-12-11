
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

const int N = 105000;
int h[N], ne[N<<1], to[N<<1], tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

struct node {
	int fr, sit, mat, pr;
	node(int f = 0, int s = 0, int m = 0, int p = 0) : fr(f), sit(s), mat(m), pr(p) {}
};

ll dp[N][2], son[N], n;
vector<node> v[N][2];
void dfs(int x, int fa) {
	dp[x][1] = n; v[x][0].resize(son[x]), v[x][1].resize(son[x]);
	int nw = 0, t;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue; dfs(y, x);
		nw++, t = dp[x][1] + dp[y][0] + 1;
		dp[x][1] += dp[y][1], v[x][1][nw] = node(y, 1, 0, 1);
		if (t < dp[x][1]) dp[x][1] = t, v[x][1][nw] = node(y, 0, 1, 1);
		t = dp[x][0] + dp[y][0] + 1;
		if (t < dp[x][1]) dp[x][1] = t, v[x][1][nw] = node(y, 0, 1, 0);
		t = dp[x][0] + dp[y][1] + 1;
		if (t < dp[x][1]) dp[x][1] = t, v[x][1][nw] = node(y, 1, 1, 0);
		dp[x][0] += dp[y][1], v[x][0][nw] = node(y, 1, 0, 0), Mn(dp[x][0], n), Mn(dp[x][1], n);
	}
}

int val[N];
void solve(int x, int sit) {
	for (int i = son[x] - 1;i >= 1; i--) {
		node t = v[x][sit][i]; if (t.mat) swap(val[x], val[t.fr]);
		solve(t.fr, t.sit), sit = t.pr;
	}
}

int main() {
	read(n); son[1]++;
	for (int i = 1, x, y;i < n; i++) 
		read(x), read(y), add(x, y), add(y, x), son[x]++, son[y]++; 
	for (int i = 1;i <= n; i++) val[i] = i;
	dfs(1, 0), write(dp[1][1] * 2), solve(1, 1);
	for (int i = 1;i <= n; i++) write(val[i], ' ');
	return 0;
}
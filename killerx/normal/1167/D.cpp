#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int  x = 0, f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
inline void write(int x) {
	if (!x) {putchar('0'); return;}
	if (x < 0) {putchar('-'); x = -x;}
	int stk[20], tp = 0;
	for (; x; x /= 10) stk[tp ++] = x % 10;
	for (; tp; putchar(stk[-- tp] + '0')) ;
}
const int N = 200005;
int n;
char s[N];
int nxt[N];
vector <int> g[N];
pair <int, int> p[N];
int cnt;
stack <int> stk;
int build(int l, int r) {
	int u = cnt ++;
	p[u] = make_pair(l, r);
	for (int i = l + 1; i < r; i = nxt[i] + 1) {
		g[u].push_back(build(i, nxt[i]));
	}
	return u;
}
int dep[N];
void dfs1(int u) {
	for (int i = 0; i < g[u].size(); ++ i) {
		int v = g[u][i];
		dfs1(v);
		dep[u] = max(dep[u], dep[v]);
	}
	if (u) ++ dep[u];
}
bool ans[N];
void dfs2(int u, int d) {
	if (d > dep[0] / 2) return;
	ans[p[u].first] = ans[p[u].second] = 1;
	for (int i = 0; i < g[u].size(); ++ i) {
		int v = g[u][i];
		if (dep[v] > dep[0] / 2) {
			dfs2(v, d + 1);
		}
	}
}
int main() {
	n = read() + 2;
	s[0] = '('; s[n - 1] = ')';
	scanf("%s", s + 1);
	for (int i = 0; i < n; ++ i) {
		if (s[i] == '(') stk.push(i);
		else {
			nxt[stk.top()] = i;
			nxt[i] = stk.top();
			stk.pop();
		}
	}
	build(0, n - 1);
	dfs1(0);
	dfs2(0, 0);
	for (int i = 1; i + 1 < n; ++ i) write(ans[i]);
	return 0;
}
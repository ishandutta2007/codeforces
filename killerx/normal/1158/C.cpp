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
const int N = 1 << 19;
int n, nxt[N];
int ans[N];
struct G {
	vector <int> g[N + N];
	int deg[N + N];
	int siz;
	void ini() {
		siz = 1;
		for (; siz <= n; siz = siz + siz);
		for (int i = 1; i < siz + siz; ++ i) {
			g[i].clear();
			deg[i] = 0;
		}
		for (int i = 1; i < siz; ++ i) {
			g[i].push_back(i + i);
			deg[i + i] ++;
			g[i].push_back(i + i + 1);
			deg[i + i + 1] ++;
		}
	}
	void add(int l, int r, int v) {
		for (l += siz, r += siz; l < r; l >>= 1, r >>= 1) {
			if (l & 1) {
				g[v + siz].push_back(l);
				deg[l] ++;
				++ l;
			}
			if (r & 1) {
				-- r;
				g[v + siz].push_back(r);
				deg[r] ++;
			}
		}
	}
	queue <int> que;
	bool topo() {
		int tme = n;
		for (int i = 0; i < siz + siz; ++ i) {
			if (deg[i] == 0) {
				que.push(i);
			}
		}
		for (; !que.empty(); ) {
			int u = que.front(); que.pop();
			if (u >= siz && u < siz + n)
				ans[u - siz] = tme --;
			for (int i = 0; i < g[u].size(); ++ i) {
				int v = g[u][i];
				-- deg[v];
				if (!deg[v]) {
					que.push(v);
				}
			}
		}
		return !tme;
	}
} g;
int main() {
	int T = read();
	for (; T --; ) {
		n = read();
		g.ini();
		for (int i = 0; i < n; ++ i) {
			nxt[i] = read() - 1;
			if (nxt[i] == -2) continue;
			if (nxt[i] < n) g.add(i, i + 1, nxt[i]);
			g.add(i + 1, nxt[i], i);
		}
		bool ok = g.topo();
		if (!ok) {
			puts("-1");
			continue;
		}
		for (int i = 0; i < n; ++ i) {
			write(ans[i]);
			putchar(i + 1 == n ? '\n' : ' ');
		}
	}
	return 0;
}
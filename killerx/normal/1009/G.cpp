#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct MF {
	static const int maxn = (1 << 6) + 6 + 5;
	int n, S, T;
	struct E {
		int to, lim, rev;
		E(int a, int b, int c): to(a), lim(b), rev(c) {}
	};
	vector <E> g[maxn];
	void init(int _n, int _S, int _T) {
		n = _n; S = _S; T = _T;
		rep(i, n) g[i].clear();
	}
	void add_edge(int u, int v, int w) {
		g[u].pb(E(v, w, g[v].size()));
		g[v].pb(E(u, 0, g[u].size() - 1));
	}
	int dis[maxn], que[maxn], ql, qr;
	bool bfs() {
		rep(i, n) dis[i] = -1;
		dis[S] = 0;
		ql = qr = 0; que[qr ++] = S;
		while (ql < qr) {
			int u = que[ql ++];
			rep(i, g[u].size()) {
				int v = g[u][i].to;
				int w = g[u][i].lim;
				if (w && !~dis[v]) {
					dis[v] = dis[u] + 1;
					que[qr ++] = v;
				}
			}
		}
		return ~dis[T];
	}
	int cur[maxn];
	int dfs(int u, int f) {
		if (u == T) return f;
		int flow = 0;
		for (int &i = cur[u]; i < int(g[u].size()); ++ i) {
			int v = g[u][i].to;
			int w = g[u][i].lim;
			if (w && dis[v] == dis[u] + 1) {
				int d = dfs(v, min(f, w));
				if (d) {
					g[u][i].lim -= d;
					g[v][g[u][i].rev].lim += d;
					flow += d; f -= d;
					if (!f) break;
				}
			}
		}
		return flow;
	}
	int solve() {
		int flow = 0;
		while (bfs()) {
			rep(i, n) cur[i] = 0;
			for (int f; (f = dfs(S, 0x3f3f3f3f)); flow += f);
		}
		return flow;
	}
} mf;

int n;
char s[1 << 17];
int mask[1 << 17];
int cnt_mask[1 << 17][1 << 6];
int cnt_ch[1 << 17][6];

bool ok(int st, int cnt[6]) {
	int S = (1 << 6) + 6, T = S + 1;
	mf.init(T + 1, S, T);
	rep(i, 1 << 6) mf.add_edge(S, i, cnt_mask[st][i]);
	rep(i, 1 << 6) rep(j, 6) if (i >> j & 1)
		mf.add_edge(i, j + (1 << 6), cnt_mask[st][i]);
	rep(i, 6) mf.add_edge(i + (1 << 6), T, cnt[i]);
	return mf.solve() == n - st;
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	rep(i, n) mask[i] = (1 << 6) - 1;
	int m; scanf("%d", &m);
	while (m --) {
		int p; char ch[15];
		scanf("%d %s", &p, ch);
		-- p;
		int msk = 0;
		for (int i = 0; ch[i]; ++ i)
			msk |= 1 << (ch[i] - 'a');
		mask[p] = msk;
	}
	for (int i = n - 1; ~i; -- i) {
		rep(msk, 1 << 6) cnt_mask[i][msk] = cnt_mask[i + 1][msk];
		cnt_mask[i][mask[i]] ++;
		rep(ch, 6) cnt_ch[i][ch] = cnt_ch[i + 1][ch];
		cnt_ch[i][s[i] - 'a'] ++;
	}
	int cnt[6]; rep(ch, 6) cnt[ch] = cnt_ch[0][ch];
	string ans;
	rep(i, n) rep(ch, 6) if (cnt[ch] && (mask[i] >> ch & 1)) {
		cnt[ch] --;
		if (ok(i + 1, cnt)) { ans += char(ch + 'a'); break; }
		cnt[ch] ++;
	}
	if (ans.size() != n) puts("Impossible");
	else puts(ans.c_str());
	return 0;
}
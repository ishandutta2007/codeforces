#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct MCF {
	int head[N], nex[N], to[N], lim[N], cost[N], tot;

	void init() {
		memset(head, -1, sizeof(head));
		tot = 0;
	}

	void add(int u, int v, int w, int c) {
		to[tot] = v; lim[tot] = w; cost[tot] = c;
		nex[tot] = head[u]; head[u] = tot ++;
	}

	void Add(int u, int v, int w, int c) {
		// cerr << u << " " << v << " " << w << endl;
		add(u, v, w, c); add(v, u, 0, -c);
	}

	int dis[N];
	int que[N], lb, rb;
	int inque[N];
	int prv[N], pre[N];

	bool spfa(int S, int T) {
		memset(dis, inf, sizeof(dis));
		dis[S] = 0; lb = rb = 0; que[rb ++] = S;
		inque[S] = 1;
		while (lb != rb) {
			int u = que[lb ++]; inque[u] = 0;
			if (lb == N) lb = 0;
			for (int e = head[u]; ~e; e = nex[e]) {
				int v = to[e], w = lim[e], c = cost[e];
				if (w && dis[v] > dis[u] + c) {
					dis[v] = dis[u] + c;
					prv[v] = u; pre[v] = e;
					if (!inque[v]) {
						inque[v] = 1;
						que[rb ++] = v;
						if (rb == N) rb = 0;
					}
				}
			}
		}
		return dis[T] < inf;
	}

	void solve(int S, int T, int &flow, int &cost) {
		flow = cost = 0;
		while (spfa(S, T)) {
			int f = inf;
			for (int u = T; u != S; u = prv[u])
				f = min(f, lim[pre[u]]);
			flow += f; cost += f * dis[T];
			for (int u = T; u != S; u = prv[u]) {
				lim[pre[u]] -= f;
				lim[pre[u] ^ 1] += f;
			}
		}
	}
} mcf;

string t;
int n;
string s[105];
int a[105];

int main() {
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	cin >> t >> n;
	for (int i = 0; i < n; ++ i)
		cin >> s[i] >> a[i];
	int cnt[26];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < t.size(); ++ i)
		cnt[t[i] - 'a'] ++;
	int S = 0, T = 1 + 26 + 26 * n + n;
	mcf.init();
	for (int i = 0; i < 26; ++ i)
		mcf.Add(S, i + 1, cnt[i], 0);
	for (int i = 0; i < n; ++ i) {
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < s[i].size(); ++ j)
			cnt[s[i][j] - 'a'] ++;
		for (int j = 0; j < 26; ++ j) {
			mcf.Add(j + 1, 1 + 26 + 26 * i + j, inf, 0);
			mcf.Add(1 + 26 + 26 * i + j, 1 + 26 + 26 * n + i, cnt[j], 0);
		}
		mcf.Add(1 + 26 + 26 * n + i, T, a[i], i + 1);
	}
	int flow, cost;
	mcf.solve(S, T, flow, cost);
	cout << (flow == t.size() ? cost : -1) << endl;
	return 0;
}
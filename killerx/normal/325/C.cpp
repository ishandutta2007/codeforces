#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define reg register
#define inl inline

#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (reg int i = 0, i##_end = (int) (n); i < i##_end; ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n, m;
struct Edge {
	int st;
	vector <pii> cnt;
};
vector <Edge> e;
vi g[100005], gg[100005], tms[100005];

#define MAXL 314000000

int deg[100005];
int mn[100005];
priority_queue <pii, vector <pii>, greater <pii> > pq;

void dij() {
	pq.push(mp(0, 0));
	memset(mn, 0x3f, sizeof(mn));
	mn[0] = 0;
	while (!pq.empty()) {
		int u = pq.top().second;
		int c = pq.top().first;
		pq.pop();
		if (c != mn[u]) continue;
		rep(i, g[u].size()) {
			int ei = g[u][i];
			if (deg[ei] -= tms[u][i]) continue;
			int cur = 0;
			rep(j, e[ei].cnt.size()) {
				if (e[ei].cnt[j].first < 0) cur += e[ei].cnt[j].second;
				else cur += min(1LL * mn[e[ei].cnt[j].first] * e[ei].cnt[j].second, (ll) MAXL);
				if (cur >= MAXL) cur = MAXL;
			}
			if (mn[e[ei].st] > cur) {
				mn[e[ei].st] = cur;
				pq.push(mp(cur, e[ei].st));
			}
		}
	}
}

int dp[100005];
int vis[100005];

int DP(int u) {
	// eprintf("call %d\n", u);
	if (mn[u] == inf) return -1;
	if (!u) return 0;
	if (vis[u] == 1) return -2;
	if (vis[u]) return dp[u];
	vis[u] = 1;
	rep(i, gg[u].size()) {
		int ei = gg[u][i];
		int cur = 0;
		rep(j, e[ei].cnt.size()) {
			if (e[ei].cnt[j].first < 0) cur += e[ei].cnt[j].second;
			else {
				int curr = DP(e[ei].cnt[j].first);
				if (curr == -2) cur = -2;
				if (curr == -1) {cur = -1; break;}
				if (cur != -2) cur += min(1LL * curr * e[ei].cnt[j].second, (ll) MAXL);
				if (cur >= MAXL) cur = MAXL;
			}
		}
		// eprintf("%d %d %lld\n", u, ei, cur);
		if (cur == -1) continue;
		if (dp[u] == -2) continue;
		if (dp[u] < cur || cur == -2) dp[u] = cur;
	}
	vis[u] = 2;
	return dp[u];
}

int main() {
	m = read(), n = read();
	rep(i, m) {
		int st = read();
		int k = read();
		vi v;
		rep(j, k) {
			int a = read();
			v.pb(a);
		}
		sort(v.begin(), v.end());
		vector <pii> cntt;
		rep(j, k) {
			if (j && v[j] == v[j - 1]) cntt.back().second ++;
			else cntt.pb(mp(v[j], 1));
		}
		if (cntt.size() == 1) cntt.pb(mp(0, 0));
		e.pb((Edge) {st, cntt});
		rep(j, cntt.size()) if (cntt[j].first >= 0) g[cntt[j].first].pb(i), tms[cntt[j].first].pb(cntt[j].second);
		gg[st].pb(i);
		deg[i] = k - cntt[0].second;
	}
	dij();
	for (int i = 1; i <= n; ++ i) {
		if (mn[i] == inf) {
			puts("-1 -1");
			continue;
		}
		printf("%d %d\n", mn[i], DP(i));
	}
	return 0;
}
// luogu-judger-enable-o2
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

const int N = 4e5 + 10;
const int mo = 1e9 + 7;

struct Edge {
	int v, nxt; ll w;
} e[N];
int n, m, hd[N], ec;
void clr() {
	fill(hd + 1, hd + n + 1, -1); ec = 0;
}
void add(int u, int v, ll w) {
	e[ec] = (Edge) {v, hd[u], w}; hd[u] = ec ++;
}

namespace base {

ll b[61];
int sz, cnt[61];

void clr() {
	sz = 0;
	fill(b, b + 61, 0);
	fill(cnt, cnt + 61, 0);
}

void ins(ll x) {
	for(int i = 60; i >= 0; i --) {
		if(x & (1ll << i)) {
			if(b[i]) x ^= b[i];
			else {
				b[i] = x; sz ++;
				for(int j = i - 1; j >= 0; j --) if(b[i] >> j & 1) b[i] ^= b[j];
				for(int j = i + 1; j <= 60; j ++) if(b[j] >> i & 1) b[j] ^= b[i];
				break ;
			}
		}
	}
}

void solve() {
	for(int i = 60; i >= 0; i --) if(b[i])
		for(int j = i; j >= 0; j --) if(b[i] >> j & 1) cnt[j] ++;
}

}

ll d[N], cnt[61], bo;
bool vis[N];
void dfs(int u, int pre = -404) {
	vis[u] = 1; bo ++;
	for(int i = 60; i >= 0; i --)
		if(d[u] & (1ll << i)) cnt[i] ++;
	for(int i = hd[u]; ~ i; i = e[i].nxt) if(i != pre) {
		int v = e[i].v; ll w = e[i].w;
		if(!vis[v]) {
			d[v] = d[u] ^ w;
			dfs(v, i ^ 1);
		} else {
			base :: ins(w ^ d[u] ^ d[v]);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m); clr();
	int u, v; ll w;
	for(int i = 1; i <= m; i ++) {
		scanf("%d%d%I64d", &u, &v, &w);
		add(u, v, w); add(v, u, w);
	}
	ll ans = 0;
	for(int u = 1; u <= n; u ++) if(!vis[u]) {
		base :: clr(); bo = 0; fill(cnt, cnt + 61, 0);
		dfs(u); base :: solve();
		for(int i = 0; i <= 60; i ++) {
			ll res = 0;
			if(!base :: cnt[i])	{
				int c0 = base :: sz - base :: cnt[i];
				res = (1ll << c0) % mo * (cnt[i] * (bo - cnt[i]) % mo) % mo;
			} else {
				res = (1ll << (base :: sz - 1)) % mo * (bo * (bo - 1) / 2 % mo) % mo;
			}
			if(res) (ans += (1ll << i) % mo * res % mo) %= mo;
		}
	}
	printf("%d\n", (int) ans);
	return 0;
}
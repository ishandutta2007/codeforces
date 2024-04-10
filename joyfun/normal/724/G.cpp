#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int N = 100005;
const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, ll> pil;
#define mp(a,b) make_pair(a,b)
const int MOD = 1000000007;

vector<pil> g[N];
int n, m;

int vis[N], cnt[105][2];
ll s[N];

ll b[105];

bool add(ll x) {
	for (int i = 62; i >= 0; i--) {
		if (x>>i&1) {
			if (!b[i]) {
				b[i] = x;
				return true;
			} else x ^= b[i];
		}
	}
	return false;
}

void dfs(int u) {
	vis[u] = 1;
	for (int i = 0; i <= 62; i++) cnt[i][s[u]>>i&1]++;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].first;
		ll w = g[u][i].second;
		if (vis[v]) {
			add(s[u]^s[v]^w);
		} else {
			s[v] = s[u]^w;
			dfs(v);
		}
	}
}

void pp(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
	scanf("%d%d", &n, &m);
	int u, v;
	ll w;
	while (m--) {
		scanf("%d%d%lld", &u, &v, &w);
		g[u].push_back(mp(v, w));
		g[v].push_back(mp(u, w));
	}
	int ans = 0;
	for (int s = 1; s <= n; s++) {
		if (vis[s]) continue;
		memset(cnt, 0, sizeof(cnt));
		memset(b, 0, sizeof(b));
		dfs(s);
		int bn = 0;
		for (int i = 0; i <= 62; i++) if (b[i]) b[bn++] = b[i];
		for (int i = 62; i >= 0; i--) {
			int f = 0;
			for (int j = 0; j < bn; j++) {
				if (b[j]>>i&1) {
					f = 1;
					break;
				}
			}
			if (f) pp(ans, (1LL<<i) % MOD * (1LL * (cnt[i][0] + cnt[i][1]) * (cnt[i][0] + cnt[i][1] - 1) / 2 % MOD) % MOD * ((1LL<<(bn - 1)) % MOD) % MOD);
			else pp(ans, (1LL<<i) % MOD * cnt[i][0] % MOD * cnt[i][1] % MOD * ((1LL<<bn) % MOD) % MOD);
		}
	}
	printf("%d\n", ans);
	return 0;
}
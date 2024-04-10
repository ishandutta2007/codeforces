#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

/*
char pool[1 << 28 | 1 << 27], *pool_pos = pool;
void clear_pool() {pool_pos = pool;}
void *operator new(size_t siz) {return pool_pos += siz, pool_pos - siz;}
void operator delete(void *p) {}
*/

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int maxn = 5e5 + 5;
const ll linf = 1e18 + 7;

struct BIT {
	ll sum[maxn];
	void upd(int x, ll v) {
		for (++ x; x < maxn; x += x & -x) sum[x] += v;
	}
	ll qry(int x) {
		ll ans = 0;
		for (++ x; x; x -= x & -x) ans += sum[x];
		return ans;
	}
	ll qry(int l, int r) {
		return qry(r) - qry(l - 1);
	}
} f;

int n, a[maxn], p[maxn], m, b[maxn];
vector <int> v[maxn];
ll dp[maxn];

#define find(v, x) (int)(lower_bound((v).begin(), (v).end(), x) - (v).begin())

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) scanf("%d", &p[i]);
	scanf("%d", &m);
	rep(i, m) scanf("%d", &b[i]);
	rep(i, n) v[a[i]].pb(i);
	rep(i, n) f.upd(i, p[i]);
	int nw = 0;
	rep(i, m) {
		rep(j, v[b[i]].size()) {
			int id = v[b[i]][j];
			dp[id] = linf;
			if (!i) dp[id] = f.qry(0, id - 1);
			else {
				int ps = find(v[b[i - 1]], id) - 1;
				if (ps >= 0) dp[id] = dp[v[b[i - 1]][ps]] + f.qry(v[b[i - 1]][ps] + 1, id - 1);
			}
		}
		while (nw <= b[i]) {
			rep(j, v[nw].size()) {
				int id = v[nw][j];
				if (p[id] >= 0) f.upd(id, -p[id]);
			}
			++ nw;
		}
		rep(j, v[b[i]].size()) {
			int id = v[b[i]][j];
			if (j) dp[id] = min(dp[id], dp[v[b[i]][j - 1]] + f.qry(v[b[i]][j - 1] + 1, id));
		}
	}
	ll ans = linf;
	rep(i, n) if (a[i] == b[m - 1])
		ans = min(ans, dp[i] + f.qry(i + 1, n - 1));
	if (ans >= linf / 2) puts("NO");
	else printf("YES\n%lld\n", ans);
	return 0;
}
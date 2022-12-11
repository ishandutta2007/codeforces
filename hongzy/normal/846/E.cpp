#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
typedef long long ll;
typedef pair<int, ll> pil;
const int N = 1e5 + 10;
const ll INF = 1e18 + 10;
int n;
ll a[N], b[N];
vector<pil> G[N];
void dfs(int u) {
	for(int i = 0; i < (int) G[u].size(); i ++) {
		pil p = G[u][i]; dfs(p.fs);
		if(b[p.fs] == - INF) {
			b[u] = -INF;
			return ;
		}
		if(b[p.fs] < a[p.fs]) {
			ll c = a[p.fs] - b[p.fs];
			if(c > INF / p.sc || b[u] - c * p.sc < - INF) {
				b[u] = - INF;
				return ;
			}
			b[u] -= c * p.sc;
		} else {
			b[u] += b[p.fs] - a[p.fs];
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%I64d", b + i);
	for(int i = 1; i <= n; i ++) scanf("%I64d", a + i);
	for(int f, i = 2; i <= n; i ++) {
		ll x; scanf("%d%I64d", &f, &x);
		G[f].push_back(mp(i, x));
	}
	dfs(1);
	puts(a[1] <= b[1] ? "YES" : "NO");
	return 0;
}
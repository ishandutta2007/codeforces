#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 300010;

int p[N], ans[N], sz[N];
vector<int> ch[N];

void dfs1(int i) {
	for (int j : ch[i]) dfs1(j);
	sz[i] = 1;
	for (int j : ch[i]) sz[i] += sz[j];
}

void dfs2(int i) {
	for (int j : ch[i]) dfs2(j);
	int pos = -1;
	for (int j : ch[i]) if (2 * sz[j] > sz[i]) pos = j;
	if (pos == -1) {
		ans[i] = i;
		return;
	}
	int cnt = ans[pos], prev;
	while (2 * sz[cnt] <= sz[i]) {
		prev = cnt;
		cnt = p[cnt];
		//cerr << i << ' ' << cnt << '\n';
	}
	ans[i] = cnt;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n, q;
	scanf("%d %d", &n, &q);
	p[0] = -1;
	forn(i, 1, n) scanf("%d", p + i);
	forn(i, 1, n) p[i]--;
	forn(i, 1, n) ch[p[i]].eb(i);
	dfs1(0);
	dfs2(0);
	forn(i, 0, q) {
		int v;
		scanf("%d", &v);
		--v;
		cout << ans[v] + 1 << '\n';
	}
	return 0;
}
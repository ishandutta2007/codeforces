#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 100005;
int n, m;
vector<pii> g[N];
int col[N], st[N], top, sb = 1;
int F;

bool dfs(int u, int c) {
	if (col[u] != -1) return col[u] == c;
	st[top++] = u;
	col[u] = c;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].fi;
		int w = g[u][i].se;
		if (!dfs(v, F^w^col[u])) return false;
	}
	return true;
}

vi cal(int f) {
	F = f;
	vi ans;
	memset(col, -1, sizeof(col));
	for (int i = 1; i <= n; i++) {
		if (col[i] != -1) continue;
		vi an;
		int cao = 0;
		for (int j = 0; j < 2; j++) {
			vi tmp;
			top = 0;
			if (!dfs(i, j)) {
				vi sb;
				return sb;
			}
			for (int k = 0; k < top; k++)
				if (col[st[k]] == 1) tmp.pb(st[k]);
			if (cao == 0 || sz(an) > sz(tmp)) an = tmp, cao = 1;
			for (int k = 0; k < top; k++) col[st[k]] = -1;
		}
		top = 0;
		dfs(i, 0);
		for (int j = 0; j < sz(an); j++) ans.pb(an[j]);
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	int u, v; char c;
	char sb = 'a';
	while (m--) {
		scanf("%d %d %c", &u, &v, &c);
		if (sb == 'a') sb = c;
		else if (sb != c) sb = 'b';
		g[u].pb(mp(v, c == 'B'));
		g[v].pb(mp(u, c == 'B'));
	}
	if (sb != 'b') {
		printf("0\n");
		return 0;
	}
	vi ans;
	for (int i = 0; i < 2; i++) {
		vi tmp = cal(i);
		if (sz(tmp) == 0) continue;
		if (sz(ans) == 0 || sz(ans) > sz(tmp)) ans = tmp;
	}
	if (sz(ans) == 0) printf("-1\n");
	else {
		printf("%d\n", sz(ans));
		for (int i = 0; i < sz(ans); i++) printf("%d ", ans[i]);
	}
	return 0;
}
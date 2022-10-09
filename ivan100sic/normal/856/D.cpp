#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

struct lepotan {
	int u, v, w;
};

const int INF = 2'000'000'001;
int n, m;
vector<int> e[200005];
vector<lepotan> sidro[200005];
int dl[200005], dr[200005], t;
int anc[200005][18];

template<class T, int size>
struct fenwick {
	T a[size];

	/* precondition: pos > 0 */
	void add(int pos, const T& val) {
		while (pos < size) {
			a[pos] += val;
			pos += pos & -pos;
		}
	}

	T sum(int pos) {
		T ret = T();
		while (pos > 0) {
			ret += a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

fenwick<long long, 400005> drvo;

bool iznad(int a, int b) {
	return dl[a] <= dl[b] && dr[b] <= dr[a];
}

int lca(int a, int b) {
	if (iznad(a, b)) {
		return a;
	}
	if (iznad(b, a)) {
		return b;
	}
	for (int i=17; i>=0; i--) {
		int aa = anc[a][i];
		if (!iznad(aa, b)) {
			a = aa;
		}
	}
	return anc[a][0];
}

void dfs(int x) {
	for (int i=1; i<18; i++) {
		anc[x][i] = anc[anc[x][i-1]][i-1];
	}

	dl[x] = ++t;
	for (int y : e[x]) {
		anc[y][0] = x;
		dfs(y);
	}
	dr[x] = ++t;
}

long long dp[200005], smd[200005];

void solve(int x) {
	for (int y : e[x]) {
		solve(y);
		smd[x] += dp[y];
	}

	dp[x] = smd[x];

	for (auto e : sidro[x]) {
		long long amt = e.w;
		if (e.u != x) {
			amt += drvo.sum(dl[e.u]);
		}
		if (e.v != x) {
			amt += drvo.sum(dl[e.v]);
		}
		dp[x] = max(dp[x], amt + smd[x]);
	}

	// cerr << "dp: " << x << ' ' << dp[x] << ' ' << smd[x] << '\n';

	drvo.add(dl[x], + smd[x] - dp[x]);
	drvo.add(dr[x], - smd[x] + dp[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=2; i<=n; i++) {
		int x;
		cin >> x;
		e[x].push_back(i);
	}

	anc[1][0] = 1;
	dfs(1);

	for (int i=1; i<=m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		sidro[lca(u, v)].push_back({u, v, w});
		// cerr << "lca " << u << ' ' << v << ' ' << lca(u, v) << '\n';
	}

	solve(1);

	cout << dp[1];
}
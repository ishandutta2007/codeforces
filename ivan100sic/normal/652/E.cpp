// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
int u[300005], v[300005], w[300005], b[300005];
basic_string<int> e[300005];
bool inst[300005];
int idx[300005], low[300005], dt;

void dfs(int x, int ei) {
	inst[x] = 1;
	idx[x] = low[x] = dt++;
	for (int i : e[x]) {
		if (ei == i) continue;
		int y = u[i] ^ v[i] ^ x;
		if (idx[y] == -1) {
			dfs(y, i);
			low[x] = min(low[x], low[y]);
		} else if (inst[y]) {
			low[x] = min(low[x], idx[y]);
		}
	}
	inst[x] = 0;
	if (ei != -1) b[ei] = idx[x] == low[x];
}

int vis[300005];

void chk(int x) {
	vis[x] = 1;
	for (int i : e[x]) {
		if (b[i]) continue;
		int y = u[i] ^ v[i] ^ x;
		if (!vis[y])
			chk(y);
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	memset(idx, 255, sizeof idx);
	memset(low, 255, sizeof low);

	cin >> n >> m;

	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		e[u[i]] += i;
		e[v[i]] += i;
	}

	int aa, bb;
	cin >> aa >> bb;
	if (aa != bb) {
		u[m] = aa;
		v[m] = bb;
		e[aa] += m;
		e[bb] += m;
		w[m] = 0;
		m++;
	}

	dfs(aa, -1);
	chk(aa);

	for (int i=0; i<m; i++) {
		if (w[i] && vis[u[i]] && vis[v[i]]) {
			return cout << "YES\n", 0;
		}
	}

	cout << "NO\n";
}
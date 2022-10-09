#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int m = 1000000007;
int n, k;
basic_string<int> e[100005];
bool vis[100005];

void dfs(int x, int& z) {
	z += 1;
	vis[x] = 1;
	for (int y : e[x])
		if (!vis[y])
			dfs(y, z);
}

int pw(int x, int y) {
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	int t = pw(x, y >> 1);
	t = t * 1ll * t % m;
	if (y & 1)
		t = t * 1ll * x % m;
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (w == 0) {
			e[u] += v;
			e[v] += u;
		}
	}
	ll sol = 0;
	for (int i=1; i<=n; i++) {
		if (!vis[i]) {
			int z = 0;
			dfs(i, z);
			sol += pw(z, k);
		}
	}
	sol = (pw(n, k) - sol) % m;
	if (sol < 0)
		sol += m;
	cout << sol << '\n';
}
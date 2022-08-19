#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define maxN 323456

vector<pair<int,int>> adj[maxN];
int n, m, u, v, alive[maxN];

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= 3 * n; i++)
		adj[i].clear();
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (u > v)
			swap(u, v);
		adj[v].push_back(make_pair(u, i));
	}
	for (int i = 1; i <= 3 * n; i++) alive[i] = 0;
	vector<int> mat;
	for (int u = 1; u <= 3 * n; u++) {
		alive[u] = 1;
		for (auto v : adj[u]) if (alive[v.first]) {
				mat.push_back(v.second);
				alive[u] = 0;
				alive[v.first] = 0;
				break;
			}
	}
	if (mat.size() >= n) {
		printf("Matching\n");
		for (int i = 0; i < n; i++) {
			printf("%d ", mat[i]);
		}
		printf("\n");
	} else {
		printf("IndSet\n");
		vector<int> ind;
		for (int i = 1; i <= 3 * n; i++)
			if (alive[i]) ind.push_back(i);
		for (int i = 0; i < n; i++) {
			printf("%d ", ind[i]);
		}
		printf("\n");
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
		solve();
}
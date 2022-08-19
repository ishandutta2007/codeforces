#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN (1 << 18) + 10

int n, a[maxN], f[maxN], go[maxN], og[maxN];
vector<int> pos[maxN];

int findpar(int x) {
	if (f[x] == x) return x;
	else return f[x] = findpar(f[x]);
}
bool solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		pos[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d" , &a[i]);
		pos[a[i]].push_back(i);
	}
	if (n % 2 == 1 && pos[a[(n + 1) / 2]].size() == 1) return false;
	int podd = 0;
	for (int i = 1; i <= n; i++) {
		if (pos[i].size() % 2 == 1) podd++;
	}
	if (podd >=2) return false;
	int t = 0;
	vector<pair<int, int>> pairs;
	for (int i = 1; i <= n; i++) {
		int m = pos[i].size();
		if (m % 2 == 1 && pos[i][m - 1] == (n + 1) / 2)  {
			swap(pos[i][m - 2], pos[i][m - 1]);
		}
		for (int j = 0; j + 1 < m; j += 2) {
			++t;
			int u = pos[i][j], v = pos[i][j + 1];
			pairs.push_back({u, v});
			go[u] = t; go[v] = n + 1 - t;
		}
		if (m % 2 == 1) {
			int u = pos[i][m - 1];
			go[u] = (n + 1) / 2;
		}
	}
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= n; i++) {
		f[findpar(i)] = findpar(go[i]);
	}
	for (auto p : pairs) {
		int u = p.first, v = p.second;
		if (findpar(u) != findpar(v)) {
			swap(go[u], go[v]);
		}
		f[findpar(u)] = findpar(v);
	}
	int m = pairs.size();
	for (int i = 1; i < m; i++) {
		int u1 = pairs[i - 1].first, v1 = pairs[i - 1].second;
		int u2 = pairs[i].first, v2 = pairs[i].second;
		assert(findpar(u1) == findpar(v1));
		assert(findpar(u2) == findpar(v2));
		if (findpar(u1) != findpar(u2)) {
			swap(go[u1], go[u2]);
			swap(go[v1], go[v2]);
			swap(go[u2], go[v2]);
			f[findpar(u1)] = findpar(u2);
		}
	}
	puts("YES");
	for (int i = 1; i <= n; i++) og[go[i]] = i;
	for (int i = 1; i <= n; i++) printf("%d ",og[i]);
	puts("");
	return true;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		if (!solve()) {
			puts("NO");
		}
	}
}
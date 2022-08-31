#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define maxN 323456

int n, p[maxN], pos[maxN];
vector<vector<int>> ans;

void swappos(int u, int v) {
	swap(pos[p[u]], pos[p[v]]);
	swap(p[u], p[v]);
	if (u > v) swap(u, v);
	if (v - u >= n / 2) {
		ans.push_back(vector<int> {u, v});
	} else if (v <= n / 2) {
		ans.push_back(vector<int> {u, n});
		ans.push_back(vector<int> {v, n});
		ans.push_back(vector<int> {u, n});
	} else if (u > n / 2) {
		ans.push_back(vector<int> {u, 1});
		ans.push_back(vector<int> {v, 1});
		ans.push_back(vector<int> {u, 1});
	} else {
		ans.push_back(vector<int> {u, n});
		ans.push_back(vector<int> {n, 1});
		ans.push_back(vector<int> {1, v});
		ans.push_back(vector<int> {n, 1});
		ans.push_back(vector<int> {u, n});
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		pos[p[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (p[i] == i) continue;
		swappos(i, pos[i]);
	}
	printf("%d\n", ans.size());
	for (auto p : ans) printf("%d %d\n", p[0], p[1]);
}
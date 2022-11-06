#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<llong, llong> pll;

int n, m, s;
int ts[300001];
vector<int> edge[300001];
vector<int> redge[300001];
bool ans[300001];
pi us[300001];
map<pi, int> index;

bool visited1[300001];
int ans1;
void dfs1(int x) {
	visited1[x] = true; ++ans1;
	for (int i : edge[x]) {
		if (visited1[i]) continue;
		dfs1(i);
	}
}

bool visited2[300001];
int ans2;
void dfs2(int x) {
	visited2[x] = true; ++ans2;
	for (int i : edge[x]) {
		if (visited2[i]) continue;
		dfs2(i);
	}
	for (int i : redge[x]) {
		if (visited2[i]) continue;
		ans[index[pi(min(i, x), max(i, x))]] = (x < i);
		dfs2(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> s;
	for (int i = 0; i < m; ++i) {
		int u, v, t;
		cin >> t >> u >> v;
		us[i] = pi(u, v);
		ts[i] = t;
		if (t == 1) edge[u].push_back(v);
		else {
			redge[u].push_back(v);
			redge[v].push_back(u);
		}
		if (u > v) swap(u, v);
		index[pi(u, v)] = i;
	}

	dfs2(s);
	printf("%d\n", ans2);
	for (int i = 0; i < m; ++i) {
		if (ts[i] == 1) continue;
		if (ans[index[pi(min(us[i].first, us[i].second), max(us[i].first, us[i].second))]]
			!= (us[i].first < us[i].second)) {
			printf("-");
		}
		else printf("+");
	}
	dfs1(s);
	printf("\n%d\n", ans1);
	for (int i = 0; i < m; ++i) {
		if (ts[i] == 1) continue;
		if (visited1[us[i].first] && !visited1[us[i].second]) printf("-");
		else printf("+");
	}
	printf("\n");
	return 0;
}
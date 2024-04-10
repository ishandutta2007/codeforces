#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int _ = 100010;

int a[_], b[_];
pair<int, int> v[_];
vector<int> G[_];
bool vis[_];

void dfs(int u) {
	vis[u] = true;
	for (int v : G[u]) if (!vis[v]) dfs(v);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int i = 1; i <= N; ++i) { cin >> v[i].first; v[i].second = i; }
		sort(v + 1, v + N + 1);
		for (int i = 1; i != N; ++i) G[v[i].second].push_back(v[i + 1].second);
		for (int i = 1; i <= N; ++i) { cin >> v[i].first; v[i].second = i; }
		sort(v + 1, v + N + 1);
		for (int i = 1; i != N; ++i) G[v[i].second].push_back(v[i + 1].second);

		fill(vis + 1, vis + N + 1, 0);
		dfs(v[N].second);
		for (int i = 1; i <= N; ++i) cout << vis[i];
		cout << '\n';

		for (int i = 1; i <= N; ++i) G[i].clear();
	}

	return 0;
}
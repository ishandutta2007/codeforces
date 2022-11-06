#include <bits/stdc++.h>

using namespace std;

const int INF = 1e7;
const int maxans = 1731311;

const int maxn = 605;

int V, E, N, K;
int d[maxn][maxn];
vector<int> start;
int match[maxn];
char used[maxn];
int mid;

bool dfs(int v) {
	if (used[v]) return false;;
	used[v] = true;
	int realv = start[v];
	for (int to = 1; to <= V; ++to) {
		if (d[realv][to] > mid) continue;
		if (match[to] == -1 || dfs(match[to])) {
			match[to] = v;
			return true;
		}
	}
	return false;
}

int kun() {
	for (int i = 1; i <= V; ++i) {
		match[i] = -1;
	}
	/*
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j <= V; ++j) {
			if (match[j] == -1 && d[start[i]][j] <= mid) {
				match[j] = i;
			}
		}
	}
	*/
	memset(used, false, N);
	for (int i = 0; i < N; ++i) {
		if (dfs(i)) {
			memset(used, false, N);
		}
	}
	int ans = 0;
	for (int i = 1; i <= V; ++i) {
		if (match[i] != -1) {
			++ans;
		}
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
//	freopen("input.txt", "r", stdin);

	cin >> V >> E >> N >> K;
	start.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> start[i];
	}
	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j) {
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}
	for (int i = 0; i < E; ++i) {
		int a, b, t;
		cin >> a >> b >> t;
		d[a][b] = d[b][a] = min(d[a][b], t);
	}

	for (int k = 1; k <= V; ++k) {
		for (int i = 1; i <= V; ++i) {
			for (int j = 1; j <= V; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int left = -1, right = maxans + 2;
	while (right - left > 1) {
		mid = (left + right) / 2;
		if (kun() >= K) {
			right = mid;
		} else {
			left = mid;
		}
	}
	if (right > maxans) {
		cout << -1 << '\n';
	} else {
		cout << right << '\n';
	}


}
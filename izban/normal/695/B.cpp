#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

const int MAXN = 1 << 10;
const int INF = (int)(2e9 + 100);

int n, m;
int s, t;
vector<pair<int, int> > edges;
vector<int> cost;
vector<int> e[MAXN];
int deleted;
int in[MAXN], out[MAXN], tmr;
int vis[MAXN];
int minCostBridge;

bool dfs(int v, int pr) {
	in[v] = tmr++;
	out[v] = in[v];

	bool hasT0 = 0;
	hasT0 |= v == t;
	vis[v] = 1;
	for (int i = 0; i < (int)e[v].size(); i++) {
		int edge = e[v][i];
		if (edge == deleted || edge == pr) continue;
		int to = edges[edge].first ^ edges[edge].second ^ v;

		bool hasT = 0;
		if (vis[to] == 0) {
			hasT = dfs(to, edge);
			out[v] = min(out[v], out[to]);
		}
		else {
			out[v] = min(out[v], in[to]);
		}

		if (out[to] > in[v] && hasT) {
			if (minCostBridge == -1 || cost[minCostBridge] > cost[edge]) {
				minCostBridge = edge;
			}
		}
		hasT0 |= hasT;
	}
	vis[v] = 2;
	return hasT0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("task.in", "r", stdin);
	freopen("task.out", "w", stdout);
#endif

	bool frst = 0;
	while (cin >> n >> m) {
		if (frst) cout << endl;
		frst = 1;
		cin >> s >> t;
		--s; --t;

		edges.clear();
		cost.clear();
		for (int i = 0; i < n; i++) {
			e[i].clear();
		}
		for (int i = 0; i < m; i++) {
			pair<int, int> o;
			int x;
			cin >> o.first >> o.second >> x;
			o.first--;
			o.second--;
			e[o.first].push_back(edges.size());
			e[o.second].push_back(edges.size());
			edges.push_back(o);
			cost.push_back(x);
		}

		vector<int> pr(n, -1);
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int i = 0; i < (int)e[v].size(); i++) {
				int to = edges[e[v][i]].first ^ edges[e[v][i]].second ^ v;
				if (pr[to] == -1) {
					pr[to] = e[v][i];
					q.push(to);
				}
			}
		}

		if (pr[t] == -1) {
			cout << 0 << endl;
			cout << 0 << endl;
			continue;
		}

		vector<int> candidates;
		int cur = t;
		while (cur != s) {
			candidates.push_back(pr[cur]);
			cur = edges[pr[cur]].first ^ edges[pr[cur]].second ^ cur;
		}
		//for (int i = 0; i < (int)candidates.size(); i++) cout << candidates[i] << " \n"[i + 1 == (int)candidates.size()];
		int ans = INF;
		vector<int> eans;

		
		deleted = -1;
		for (int i = 0; i < (int)candidates.size(); i++) {
			deleted = candidates[i];
			for (int j = 0; j < n; j++) vis[j] = 0;
			for (int j = 0; j < n; j++) out[j] = in[j] = -1;
			tmr = 0;
			minCostBridge = -1;

			//cerr << "1" << endl;
			dfs(s, -1);
			//cerr << "2" << endl;

			int cres = cost[deleted];
			vector<int> cans;
			cans.push_back(deleted);
			if (vis[t] != 0) {				
				if (minCostBridge == -1) {
					cres = INF;
					cans.clear();
				}
				else {
					cres += cost[minCostBridge];
					cans.push_back(minCostBridge);
				}
			}
			if (ans > cres) {
				ans = cres;
				eans = cans;
			}
		}
		if (ans == INF) {
			cout << -1 << endl;
		}
		else {
			sort(eans.begin(), eans.end());
			cout << ans << endl << eans.size() << endl;
			for (int i = 0; i < (int)eans.size(); i++) cout << eans[i] + 1 << " \n"[i + 1 == (int)eans.size()];
		}
	}

	return 0;
}
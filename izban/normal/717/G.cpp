#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int INF = (int)(1e9);

struct Edge {
	int from, to, cap, flow, cost;
};

struct Graph {
	int n;
	vector<Edge> edges;
	vector<vector<int> > e;

	Graph(int n) {
		this->n = n;
		e.resize(n);
	}

	void addEdge(int from, int to, int cap, int cost) {
		e[from].push_back(edges.size());
		edges.push_back(Edge({ from, to, cap, 0, cost }));
		e[to].push_back(edges.size());
		edges.push_back(Edge({ to, from, 0, 0, -cost }));
	}

	vector<int> d, fl;
	vector<int> pr;
	vector<char> inq;

	bool dijkstra() {
		d.assign(n, INF);
		fl.assign(n, 0);
		pr.assign(n, -1);
		inq.assign(n, 0);

		queue<int> q;
		d[0] = 0;
		fl[0] = INF;
		inq[0] = 1;
		q.push(0);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			inq[v] = 0;

			for (int i = 0; i < (int)e[v].size(); i++) {
				Edge cur = edges[e[v][i]];
				if (d[cur.to] > d[v] + cur.cost && cur.flow < cur.cap) {
					d[cur.to] = d[v] + cur.cost;
					pr[cur.to] = e[v][i];
					fl[cur.to] = min(fl[v], cur.cap - cur.flow);
					if (!inq[cur.to]) {
						inq[cur.to] = 1;
						q.push(cur.to);
					}
				}
			}
		}
		return fl[n - 1] != 0;
	}

	pair<int, int> mincost() {
		pair<int, int> ans;
		while (dijkstra()) {
			int flow = fl[n - 1];
			ans.first += fl[n - 1];
			ans.second += d[n - 1] * fl[n - 1];
			int v = n - 1;
			while (v != 0) {
				edges[pr[v]].flow += flow;
				edges[pr[v] ^ 1].flow -= flow;
				v = edges[pr[v]].from;
			}
		}
		return ans;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	string s;
	int m;
	cin >> n >> s >> m;
	vector<string> a(m);
	vector<int> p(m);
	for (int i = 0; i < m; i++) cin >> a[i] >> p[i];
	int x;
	cin >> x;

	/*Graph gr(n + 3);
	for (int i = 0; i < n; i++) {
		gr.addEdge(1 + i, 1 + i + 1, INF - x, 0);
		gr.addEdge(0, 1 + i + 1, x, 0);
		gr.addEdge(1 + i, 1 + n, x, 0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (i + a[j].length() <= n) {
			if (s.substr(i, a[j].length()) == a[j]) {
				gr.addEdge(1 + i, 1 + i + a[j].length(), 1, -p[j]);
			}
		}
	}*/
	Graph gr(n + 3);
	gr.addEdge(0, 1 + 0, x, 0);
	gr.addEdge(1 + n, 1 + n + 1, x, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (i + a[j].length() <= n) {
			if (s.substr(i, a[j].length()) == a[j]) {
				gr.addEdge(1 + i, 1 + i + a[j].length(), 1, -p[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		gr.addEdge(1 + i, 1 + i + 1, INF, 0);
	}
	auto o = gr.mincost();
	cout << -o.second << endl;

	return 0;
}
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

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std; 

const int maxn = 21000;

struct Graph {
    struct Edge {
        int from, to, cap, flow;
       
        Edge() {}
        Edge(int from, int to, int cap) : from(from), to(to), cap(cap), flow(0) {}
    };
 
    int n;
    int S, T;
    vector<vector<int> > e;
    vector<Edge> edges;
    vector<int> d, c;
   
    bool bfs() {
        d.assign(n, 1e9);
        c.assign(n, 0);
        queue<int> q;
        q.push(S);
        d[S] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < e[v].size(); i++) {
                Edge cur = edges[e[v][i]];
                if (d[cur.to] > d[v] + 1 && -cur.flow + cur.cap > 0) {
                    d[cur.to] = d[v] + 1;
                    q.push(cur.to);
                }
            }
        }
        return d[T] < 1e9;
    }
 
    int dfs(int v, int flow) {
        if (flow == 0) return 0;
        if (v == T) return flow;
        for (int &i = c[v]; i < e[v].size(); i++) {
            Edge cur = edges[e[v][i]];
            if (d[cur.to] != d[v] + 1) continue;
            int pushed = dfs(cur.to, min(flow, cur.cap - cur.flow));
            if (pushed) {
                edges[e[v][i]].flow += pushed;
                edges[e[v][i] ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
 
    Graph() {}
    Graph(int N) {
        n = N;
        e.resize(n);
		S = 0;
		T = n - 1;
    }
 
    void addEdge(int from, int to, int cap) {
        e[from].push_back(edges.size());
        edges.push_back(Edge(from, to, cap));
        e[to].push_back(edges.size());
        edges.push_back(Edge(to, from, 0));
    }
 
    ll getFlow() {
        for (int i = 0; i < edges.size(); i++) edges[i].flow = 0;
        ll ans = 0;
        while (bfs()) {
            while (int pushed = dfs(S, 1e9)) {
                ans += pushed;
            }
        }
        return ans;
    }

	int m;

	vector<int> cur;
	pair<int, int> dfs1(int v) {
		if (v == T) {
			return make_pair(cur[1] - 1, cur[2] - 1);
		}
		cur.push_back(v);
		for (int i = 0; i < (int)e[v].size(); i++) {
			Edge _cur = edges[e[v][i]];
			if (_cur.flow <= 0) continue;
			pair<int, int> o = dfs1(_cur.to);
			if (o != make_pair(-1, -1)) {
				cur.pop_back();
				edges[e[v][i]].flow--;
				edges[e[v][i] ^ 1].flow++;
				return o;
			}
		}
		cur.pop_back();
		return make_pair(-1, -1);
	}

	vector<pair<int, int> > decompose(int M) {
		m = M;
		vector<pair<int, int> > res;
		for (int i = 0; i < m; i++) {
			pair<int, int> o = dfs1(0);
			res.push_back(o);
		}
		return res;
	}
};
vector<vector<int> > e;
vector<char> vis;
vector<int> cur;

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	cur.push_back(v + 1);
	for (int i = 0; i < (int)e[v].size(); i++) dfs(e[v][i]);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		vector<int> pr(maxn, 1);
		for (int i = 2; i < maxn; i++) {
			if (!pr[i]) continue;
			for (int j = i + i; j < maxn; j += i) pr[j] = 0;
		}

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		bool ok = 1;
		int cnt = 0;
		for (int i = 0; i < n; i++) cnt += a[i] % 2;
		if (cnt * 2 != n) {
			cout << "Impossible" << endl;
			continue;
		}
		Graph gr(n + 2);
		int ccnt[2] = {0};
		vector<int> nom(n);
		for (int i = 0; i < n; i++) {
			nom[i] = 1 + (n / 2) * (a[i] % 2) + (ccnt[a[i] % 2]++);
		}

		for (int i = 1; i <= n / 2; i++) gr.addEdge(0, i, 2);
		for (int i = n / 2 + 1; i <= n; i++) gr.addEdge(i, n + 1, 2);
		for (int i = 0; i < n; i++) if (a[i] % 2 == 0) {
			for (int j = 0; j < n; j++) if (a[j] % 2 == 1) {
				if (pr[a[i] + a[j]]) {
					gr.addEdge(nom[i], nom[j], 1);
				}
			}
		}
		int k = gr.getFlow();
		if (k != n) {
			cout << "Impossible" << endl;
			continue;
		}
		vector<pair<int, int> > v = gr.decompose(n);
		vector<int> o(n);
		for (int i = 0; i < n; i++) o[nom[i] - 1] = i;
		for (int i = 0; i < n; i++) {
			v[i].first = o[v[i].first];
			v[i].second = o[v[i].second];
		}
		e.assign(n, vector<int>());
		vis.assign(n, 0);
		for (int i = 0; i < (int)v.size(); i++) {
			e[v[i].first].push_back(v[i].second);
			e[v[i].second].push_back(v[i].first);
		}
		vector<vector<int> > ans;
		for (int i = 0; i < n; i++) {
			cur.clear();
			dfs(i);
			if (!cur.empty()) ans.push_back(cur);
		}
		cout << ans.size() << endl;
		for (int i = 0; i < (int)ans.size(); i++) {
			cout << ans[i].size() << " ";
			for (int j = 0; j < (int)ans[i].size(); j++) cout << ans[i][j] << " \n"[j + 1 == (int)ans[i].size()];
		}
	}

	return 0;
}
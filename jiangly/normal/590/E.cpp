#include <bits/stdc++.h>
using namespace std;
constexpr int L = 10000002;
struct Node {
	int next[2], link, nearest;
	Node() : nearest(-1) {}
} t[L];
int cnt_nodes = 1;
void build(vector<bitset<750>> &g) {
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int p = que.front();
		que.pop();
		if (p != 1 && t[t[p].link].nearest != -1) {
			if (t[p].nearest != -1)
				g[t[t[p].link].nearest][t[p].nearest] = 1;
			else
				t[p].nearest = t[t[p].link].nearest;
		}
		for (int i = 0; i < 2; ++i) {
			if (t[p].next[i] == 0) {
				t[p].next[i] = t[t[p].link].next[i];
			} else {
				t[t[p].next[i]].link = t[t[p].link].next[i];
				que.push(t[p].next[i]);
			}
		}
	}
}
class Flow {
public:
    int n;
    vector<pair<int, int>> e;
    vector<vector<int>> g;
    vector<int> cur, h;
    bool bfs(int s, int t) {
        h.assign(n, -1);
        queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i : g[u]) {
                int v, c;
                tie(v, c) = e[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t)
                        return true;
                    que.push(v);
                }
            }
        }
        return false;
    }
    int dfs(int u, int t, int f) {
        if (u == t)
            return f;
        int r = f;
        for (int &i = cur[u]; i < g[u].size(); ++i) {
            int j = g[u][i];
            int v, c;
            tie(v, c) = e[j];
            if (c > 0 && h[v] == h[u] + 1) {
                int a = dfs(v, t, min(r, c));
                e[j].second -= a;
                e[j ^ 1].second += a;
                r -= a;
                if (r == 0)
                    return f;
            }
        }
        return f - r;
    }
    Flow(int n) : n(n) {g.resize(n);}
    void addEdge(int u, int v, int c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    int maxFlow(int s, int t) {
        int ans = 0;
        while (bfs(s, t)) {
        	cur.assign(n, 0);
            ans += dfs(s, t, 1E9);
        }
        return ans;
    }
};
int main() {
	for (int i = 0; i < 2; ++i)
		t[0].next[i] = 1;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<string> str(n);
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
		int p = 1;
		for (char c : str[i]) {
			if (t[p].next[c - 'a'] == 0)
				t[p].next[c - 'a'] = ++cnt_nodes;
			p = t[p].next[c - 'a'];
		}
		t[p].nearest = i;
	}
	vector<bitset<750>> g(n);
	build(g);
	for (int i = 0; i < n; ++i) {
		int p = 1;
		for (char c : str[i]) {
			p = t[p].next[c - 'a'];
			if (t[p].nearest != -1)
				g[t[p].nearest][i] = 1;
		}
	}
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			if (g[i][k] == 1)
				g[i] |= g[k];
	Flow flow(2 * n + 2);
	const int s = 2 * n, t = s + 1;
	for (int i = 0; i < n; ++i) {
		flow.addEdge(s, i, 1);
		flow.addEdge(i + n, t, 1);
		for (int j = 0; j < n; ++j)
			if (i != j && g[i][j] == 1)
				flow.addEdge(i, j + n, 1);
	}
	cout << n - flow.maxFlow(s, t) << "\n";
	vector<bool> visited(2 * n);
	function<void(int)> dfs1 = [&](int u) {
		if (visited[u])
			return;
		visited[u] = true;
		for (int i : flow.g[u]) {
			if (flow.e[i].first >= 2 * n)
				continue;
			if (flow.e[i].second == 1)
				dfs1(flow.e[i].first);
		}
	};
	for (int i : flow.g[s])
		if (flow.e[i].second == 1)
			dfs1(flow.e[i].first);
	vector<int> antichain;
	for (int i = 0; i < n; ++i)
		if (visited[i] && !visited[i + n])
			antichain.push_back(i);
	for (int i : antichain)
		cout << i + 1 << " \n"[i == antichain.back()];
	return 0;
}
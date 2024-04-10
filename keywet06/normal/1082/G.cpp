#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

struct Dinic {
    struct Edge {
        int flow, to, next;
    };
    vector<Edge> edges;
    vector<int> adia, at, dist;
    int S, D;

    void add_Edge(int from, int to, int cap) {
        edges.push_back({cap, to, adia[from]});
        adia[from] = edges.size() - 1;
        edges.push_back({0, from, adia[to]});
        adia[to] = edges.size() - 1;
    }

    bool bfs() {
        queue<int> q;
        fill(dist.begin(), dist.end(), 1e9);
        dist[S] = 0;
        q.push(S);
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int i = adia[x]; i != -1; i = edges[i].next) {
                if (dist[edges[i].to] > dist[x] + 1 && edges[i].flow) {
                    dist[edges[i].to] = 1 + dist[x];
                    q.push(edges[i].to);
                }
            }
        }
        return dist[D] < 1e9;
    }
    int dfs(int nod, int fmax) {
        if (nod == D) return fmax;
        while (at[nod] != -1) {
            Edge& e = edges[at[nod]];
            int f;
            if (dist[e.to] == dist[nod] + 1 && e.flow &&
                (f = dfs(e.to, min(fmax, e.flow)))) {
                e.flow -= f;
                edges[at[nod] ^ 1].flow += f;
                return f;
            }
            at[nod] = edges[at[nod]].next;
        }
        return 0;
    }

    int64 GetFlow() {
        int64 f = 0;
        while (bfs()) {
            at = adia;
            while (int x = dfs(S, 1e9)) f += x;
        }
        return f;
    }
    Dinic(int n = 0, int s = 0, int d = 0) {
        S = s, D = d;
        at = dist = adia = vector<int>(n + 1, -1);
    }
} flow;

int cost_node[100001];
int cost_edge[10001];
int64 ans;
vector<pair<int, int>> edges;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, c;
    cin >> n >> m;

    flow = Dinic(n + m + 2, 1, n + m + 2);

    for (int i = 1; i <= n; i++) {
        cin >> cost_node[i];
        flow.add_Edge(m + i + 1, n + m + 2, cost_node[i]);
    }

    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        flow.add_Edge(1, i + 1, c);
        flow.add_Edge(i + 1, a + m + 1, 1e9);
        flow.add_Edge(i + 1, b + m + 1, 1e9);
        ans += c;
    }

    cout << ans - flow.GetFlow() << '\n';

    return 0;
}
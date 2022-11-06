#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e4 + 5;
const int maxw = 1e9;
const int INF = 1e16;

struct Edge {
    int to;
    int ind;
};

int n, m, L;
int st, fin;
vector<Edge> graph[maxn];
pair<int, int> edges[maxn];
char del[maxn];
int w[maxn];

char used[maxn];
int dist[maxn];
pair<int, int> parent[maxn];
vector<int> path;

void dijkstra() {
    set< pair<int, int> > q;
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        used[i] = false;
    }
    dist[st] = 0;
    q.insert({0, st});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto e: graph[v]) {
            int to = e.to, ind = e.ind;
            if (dist[to] > dist[v] + w[ind]) {
                if (dist[to] < INF) q.erase({dist[to], to});
                dist[to] = dist[v] + w[ind];
                q.insert({dist[to], to});
                parent[to] = {v, ind};
            }
        }
    }
}

void restore_path() {
    path.clear();
    int cur = fin;
    while (cur != st) {
        int next = parent[cur].first;
        int edge = parent[cur].second;
        if (del[edge]) path.push_back(edge);
        cur = next;
    }
}

void fail() {
    cout << "NO\n";
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> L >> st >> fin;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, i});
        graph[b].push_back({a, i});
        edges[i] = {a, b};
        w[i] = c;
        if (c == 0) del[i] = true;
    }

    for (int i = 0; i < m; i++) {
        if (del[i]) w[i] = 1;
    }
    dijkstra();
    if (dist[fin] > L) fail();
    for (int i = 0; i < m; i++) {
        if (del[i]) w[i] = maxw;
    }
    dijkstra();
    if (dist[fin] < L) fail();

    for (int i = 0; i < m; i++) {
        if (del[i]) w[i] = 1;
    }
    dijkstra();
    restore_path();
    for (int i = 0; i < m; i++) {
        if (del[i]) w[i] = maxw;
    }

    int k = path.size();
    int left = -1, right = k;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        for (int i = 0; i < k; i++) {
            if (i <= mid) w[path[i]] = maxw;
            else w[path[i]] = 1;
        }
        dijkstra();
        if (dist[fin] > L) {
            right = mid;
        } else {
            left = mid;
        }
    }

    int border = right;
    for (int i = 0; i < k; i++) {
        if (i < border) w[path[i]] = maxw;
        else w[path[i]] = 1;
    }
    if (border < k) {
        int left = 1, right = maxw + 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            w[path[border]] = mid;
            dijkstra();
            if (dist[fin] > L) {
                right = mid;
            } else {
                left = mid;
            }
        }
        w[path[border]] = left;
    }

    cout << "YES\n";
    for (int i = 0; i < m; i++) {
        cout << edges[i].first << ' ' << edges[i].second << ' ' << w[i] << '\n';
    }
}
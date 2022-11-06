#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to;
    int len;
};

int N, M;
vector< vector<Edge> > graph;

void bfs1(int st, int maxlen, vector<int> &d) {
    d.assign(N, INF);
    deque<int> q;
    d[st] = 0;
    q.push_back(st);
    while (!q.empty()) {
        int v = q.front(); q.pop_front();
        for (auto &e: graph[v]) {
            if (d[e.to] == INF && e.len <= maxlen) {
                d[e.to] = d[v] + 1;
                q.push_back(e.to);
            }
        }
    }
}

void bfs(vector<int> &d) {
    d.assign(N, INF);
    d[0] = 0;
    int max_c = 0;
    vector<int> prev = {0};
    while (!prev.empty()) {
        map<int, pair<int, int> > next;
        for (auto v: prev) {
            for (auto &e: graph[v]) {
                if (d[e.to] == INF) {
                    if (next.find(e.to) == next.end() || make_pair(e.len, d[v]) < next[e.to]) {
                        next[e.to] = make_pair(e.len, d[v]);
                    }
                }
            }
        }
        vector< pair<int, int> > sorted;
        for (auto &i: next) sorted.push_back(i.second);
        sort(sorted.begin(), sorted.end());
        prev.clear();
        for (auto &i: next) {
            d[i.first] = max_c + 1 + lower_bound(sorted.begin(), sorted.end(), i.second) - sorted.begin();
            prev.push_back(i.first);
        }
        max_c += next.size();
    }
}

void recovery(int current, int fin, int maxlen, vector<int> &d, vector<int> &length, vector<int> &path) {
    while (current != fin) {
        int minimal = 9;
        int minimal_d = INF;
        for (auto &e: graph[current]) {
            if(e.len > maxlen) continue;
            if (d[e.to] < minimal_d) {
                minimal_d = d[e.to];
                minimal = e.len;
            } else if (d[e.to] == minimal_d) {
                minimal = min(minimal, e.len);
            }
        }
        for (auto &e: graph[current]) {
            if(e.len > maxlen) continue;
            if (d[e.to] == minimal_d && e.len == minimal) {
                current = e.to;
                path.push_back(e.to);
                length.push_back(e.len);
                break;
            }
        }
    }
}

void recovery2(int current, int fin, vector<int> &d, vector<int> &d2, vector<int> &length, vector<int> &path) {
    while (current != fin) {
        int minimal = 9;
        int minimal_d = d[current];
        for (auto &e: graph[current]) {
            if (d2[e.to] + 1 != d2[current]) continue;
            if (e.len < minimal) {
                minimal_d = d[e.to];
                minimal = e.len;
            } else if (e.len == minimal) {
                minimal_d = min(minimal_d, d[e.to]);
            }
        }
        for (auto &e: graph[current]) {
            if (d2[e.to] + 1 != d2[current]) continue;
            if (d[e.to] == minimal_d && e.len == minimal) {
                current = e.to;
                path.push_back(e.to);
                length.push_back(e.len);
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> N >> M;
    graph.assign(N, vector<Edge>());
    for (int i = 0; i < M; i++) {
        int a, b, len;
        cin >> a >> b >> len;
        graph[a].push_back(Edge {b, len});
        graph[b].push_back(Edge {a, len});
    }

    vector<int> d;
    vector<int> d2;
    vector<int> dzero;

    bfs1(N - 1, 0, dzero);
    bfs1(0, 9, d2);
    bfs(d);

    int min_zero = INF, min_d = INF, middle = N - 1;
    for (int i = 0; i < N; i++) {
        if (dzero[i] != INF && d[i] != INF) {
            if (d[i] < min_d || d[i] == min_d && dzero[i] < min_zero) {
                min_d = d[i];
                min_zero = dzero[i];
                middle = i;
            }
        }
    }

    vector<int> l1, p1, l2, p2;
    recovery2(middle, 0, d, d2, l1, p1);
    recovery(middle, N - 1, 0, dzero, l2, p2);
    reverse(p1.begin(), p1.end()); reverse(l2.begin(), l2.end());

    vector<int> length, path;
    for (auto i: l2) length.push_back(i);
    for (auto i: l1) length.push_back(i);
    for (auto i: p1) path.push_back(i);
    path.push_back(middle);
    for (auto i: p2) path.push_back(i);

    reverse(length.begin(), length.end());
    while (length.size() > 1 && length.back() == 0) {
        length.pop_back();
    }
    reverse(length.begin(), length.end());

    for (auto i: length) cout << i; cout << '\n';
    cout << path.size() << '\n';
    for (auto i: path) cout << i << ' '; cout << '\n';
}
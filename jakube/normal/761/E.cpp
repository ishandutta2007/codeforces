#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

struct Position {
    int x, y;
    int index;
};

struct Result {
    int min_x, min_y, max_x, max_y;
    vector<Position> positions;
};

vector<bool> visited;
Result f(int v) {
    visited[v] = true;

    vector<int> next;
    copy_if(adj[v].begin(), adj[v].end(), back_inserter(next), [](int i){ return !visited[i]; });

    vector<Result> results;
    transform(next.begin(), next.end(), back_inserter(results), [](int i){ return f(i); });

    if (results.size() == 0) {
        Result r;
        r.max_x = 1;
        r.min_x = 0;
        r.min_y = -1;
        r.max_y = 1;
        r.positions = {{0, 0, v}};
        return r;
    } else {
        Result r = results.front();
        for (auto &pos : r.positions) {
            pos.x++;
        }
        r.max_x++;
        Position npos = {0, 0, v};
        if (results.size() == 1) {
            r.positions.push_back(npos);
        } else if (results.size() == 2) {
            Result r2 = results[1];

            for (auto &pos : r.positions) {
                pos.x += r2.max_y - r2.min_y + 1;
            }
            for (auto pos : r2.positions) {
                pos.x++;
                r.positions.push_back({ -pos.y + r2.max_y + 1, pos.x, pos.index });
            }
            npos.x += r2.max_y + 1;
            r.positions.push_back(npos);

        } else if (results.size() >= 3) {
            Result r2 = results[1];
            Result r3 = results[2];

            int d1 = max(r2.max_y, -r3.min_y) + 1;
            int d2 = max(-r2.min_y, r3.max_y) + 1;
            int d = d1 + d2 + 2;
            for (auto &pos : r.positions) {
                pos.x += d2;
            }
            npos = { 0, 0, v };

            for (auto pos : r2.positions) {
                pos.x++;
                r.positions.push_back({ -pos.y, pos.x, pos.index });
            }
            for (auto pos : r3.positions) {
                pos.x++;
                r.positions.push_back({ pos.y, -pos.x, pos.index });
            }

            r.positions.push_back(npos);

            for (auto pos : r.positions) {
                r.min_x = min(r.min_x, pos.x);
            }

            for (auto &p : r.positions) {
                p.x -= r.min_x;
            }
        }
        if (results.size() >= 4) {
            Result r4 = results[3];
            for (auto pos : r4.positions) {
                pos.x++;
                r.positions.push_back({ -pos.x, -pos.y, pos.index });
            }
        }

        for (auto pos : r.positions) {
            r.min_x = min(r.min_x, pos.x);
            r.max_x = min(r.max_x, pos.x);
            r.min_y = min(r.min_y, pos.y);
            r.max_y = min(r.max_y, pos.y);
        }
        r.max_x++;
        r.max_y++;
        r.min_y--;

        return r;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (any_of(adj.begin(), adj.end(), [](auto a){ return a.size() > 4; })) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    visited.assign(n, false);
    auto result = f(0);

    sort(result.positions.begin(), result.positions.end(), [](auto i, auto j){ return i.index < j.index; });
    for (auto p : result.positions) {
        cout << p.x << ' ' << p.y << endl;
    }

    return 0;
}
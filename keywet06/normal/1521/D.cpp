#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

struct edge {
    int v, u;
};

vector<pair<edge, edge>> operations;

int dp[N], answer = 0;

bool isDeleted[N];

vector<pair<int, int>> g[N];

void dfs(int v, int p = -1) {
    int sz = (int)g[v].size() - (p != -1);
    for (auto to : g[v]) {
        if (to.first == p) continue;
        dfs(to.first, v);
        if (dp[to.first]) {
            --sz;
            ++answer;
            isDeleted[to.second] = true;
        }
    }
    if (sz >= 2) {
        dp[v] = true;
        for (auto to : g[v]) {
            if (to.first == p) continue;
            if (sz <= 2) break;
            if (!dp[to.first]) {
                --sz;
                ++answer;
                isDeleted[to.second] = true;
            }
        }
    }
}

vector<pair<int, int>> bamboos;

bool used[N];

vector<int> leaves;

void dfs2(int v, int root) {
    used[v] = true;
    int numberOfChildren = 0;
    for (auto to : g[v]) {
        if (used[to.first] || isDeleted[to.second]) continue;
        ++numberOfChildren;
        dfs2(to.first, root);
    }
    if (v == root && numberOfChildren == 1) {
        leaves.push_back(v);
    } else if (!numberOfChildren) {
        leaves.push_back(v);
    }
}

void clear(int n) {
    answer = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = 0;
        g[i].clear();
        used[i] = isDeleted[i] = false;
    }
    bamboos.clear();
    operations.clear();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            g[a].push_back({b, i});
            g[b].push_back({a, i});
        }

        dfs(0);
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                dfs2(i, i);
                assert((int)leaves.size() <= 2);
                if ((int)leaves.size() == 2) {
                    bamboos.push_back({leaves[0], leaves[1]});
                }
                if ((int)leaves.size() == 1) {
                    bamboos.push_back({leaves.back(), leaves.back()});
                }
                leaves.clear();
            }
        }

        vector<edge> deletedEdges, addedEdges;
        for (int v = 0; v < n; ++v) {
            for (auto to : g[v]) {
                if (isDeleted[to.second]) {
                    if (v < to.first) {
                        deletedEdges.push_back({v, to.first});
                    }
                }
            }
        }
        for (int i = 1; i < (int)bamboos.size(); ++i) {
            addedEdges.push_back({bamboos[i - 1].second, bamboos[i].first});
        }

        assert(answer == (int)deletedEdges.size());
        assert((int)deletedEdges.size() == (int)addedEdges.size());

        for (int i = 0; i < answer; ++i) {
            operations.push_back({deletedEdges[i], addedEdges[i]});
        }

        assert(answer == (int)operations.size());

        cout << answer << endl;
        for (pair<edge, edge> to : operations) {
            cout << to.first.v + 1 << ' ' << to.first.u + 1 << ' ';
            cout << to.second.v + 1 << ' ' << to.second.u + 1 << endl;
        }

        clear(n);
    }
}
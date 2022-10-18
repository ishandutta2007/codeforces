#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    public:
        SegmentTree(int count) {
            n = count;
            data.assign(2 * n, 0);
        }

        bool possible(int idx) {
            idx += n;
            int ret = data[idx];

            while (idx > 1) {
                idx /= 2;
                ret += data[idx];
            }
            return ret == 0;
        }

        void disallow(int left, int right) { // interval [left, right)
            left += n;
            right += n;

            while (left < right) {
                if (left & 1) data[left++] = 1;
                if (right & 1) data[--right] = 1;
                left >>= 1;
                right >>= 1;
            }
        }

    private:
        int n;
        std::vector<int> data;
};

vector<vector<int>> adj;
vector<int> color;
vector<int> cycle;
vector<int> farthest;
int cur;
int cycle_sz = 0;

bool find_cycle(int v) {
    if (color[v] == 1) {
        cycle.erase(cycle.begin(), find(cycle.begin(), cycle.end(), v));
        cycle_sz = cycle.size();
        return true;
    }
    if (color[v] == 2) {
        return false;
    }

    color[v] = 1;
    cycle.push_back(v);

    for (int u : adj[v]) {
        if (find_cycle(u))
            return true;
    }

    cycle.pop_back();
    color[v] = 2;
    return false;
}

bool find_any_cycle() {
    int n = adj.size();
    color.assign(n, 0);
    bool found = false;
    for (int v = 0; v < n && !found; v++) {
        if (color[v] == 0)
            found = find_cycle(v);
    }
    return found;
}

int index(int i) {
    return i <= cur ? i + cycle_sz : i;
}

void dfs(int v) {
    color[v] = 1;
    auto& f = farthest[v];
    for (int u : adj[v]) {
        if (color[u] == 0)
            dfs(u);
        int g = farthest[u];
        if (g >= 0 && (f == -1 || index(f) < index(g)))
            f = g;
    }
    color[v] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    adj.resize(n);
    int first = -1;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (!i)
            first = u;
        u--, v--;
        adj[u].push_back(v);
    }
    for (auto& r : adj) {
        sort(r.begin(), r.end());
        r.erase(unique(r.begin(), r.end()), r.end());
    }

    find_any_cycle();
    color.assign(n, 0);
    farthest.assign(n, -1);
    for (int i = 0; i < cycle_sz; i++) {
        color[cycle[i]] = 2;
        farthest[cycle[i]] = i;
    }
    SegmentTree st(2*cycle_sz);

    for (int i = 0; i < cycle_sz; i++) {
        cur = i;
        int v = cycle[i];
        int f = i + 1;
        for (int u : adj[v]) {
            if (color[u] == 0)
                dfs(u);
            int g = farthest[u];
            if (g >= 0 && index(g) > f)
                f = index(g);
        }
        st.disallow(cur + 1, f);
    }

    int candidate = 0;
    for (int i = 0; i < cycle_sz; i++) {
        if (st.possible(i) && st.possible(i + cycle_sz)) {
            candidate = cycle[i];
        }
    }

    auto adj2 = adj;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        for (int j : adj2[i]) {
            if (i != candidate && j != candidate)
                adj[i].push_back(j);
        }
    }

    if (find_any_cycle()) {
        cout << -1 << endl;
    } else {
        cout << candidate + 1 << endl;
    }
}
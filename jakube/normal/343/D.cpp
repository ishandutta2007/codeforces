#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<pair<int, int>> interval;

int dfs(int u, int p, int idx) {
    interval[u].first = idx;
    parent[u] = p;

    for (int v : adj[u]) {
        if (v != p) {
            idx = dfs(v, u, idx + 1);
        }
    }
    
    interval[u].second = idx;
    return idx;
}

class SegmentTree {
public:
    vector<int> data, todo;
    vector<int> length;
    int n;
    int height;

    SegmentTree(int n) : n(n) {
        data.assign(2*n, 1);
        for (int i = n-1; i > 0; i--)
            data[i] = data[i<<1] + data[i<<1|1];
        length = data;
        todo.assign(n, -1);

        height = 0;
        while ((2*n - 1) >> height > 1)
            height++;
    }

    void apply(int idx, int val) {
        data[idx] = length[idx] * val;
        if (idx < n) todo[idx] = val;
    }

    void calculate(int idx) {
        if (todo[idx] == -1) data[idx] = data[idx<<1] + data[idx<<1|1];
        else data[idx] = todo[idx] * length[idx];
    }

    void build(int idx) {
        while (idx > 1) {
            idx >>= 1;
            calculate(idx);
        }
    }

    void push(int idx) {
        for (int s = height; s > 0; s--) {
            int i = idx >> s;
            if (todo[i] != -1) {
                apply(i<<1, todo[i]);
                apply(i<<1|1, todo[i]);
                todo[i] = -1;
            }
        }
    }

    int sum(int l, int r) {
        l += n;
        r += n;
        push(l);
        push(r-1);
        int result = 0;

        while (l < r) {
            if (l & 1) result += data[l++];
            if (r & 1) result += data[--r];
            l >>= 1;
            r >>= 1;
        }

        return result;
    }

    void assign(int l, int r, int val) {
        l += n;
        r += n;
        int l0 = l;
        int r0 = r;
        push(l0);
        push(r0-1);

        while (l < r) {
            if (l & 1) apply(l++, val);
            if (r & 1) apply(--r, val);
            l >>= 1;
            r >>= 1;
        }

        build(l0);
        build(r0-1);
    }
};

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
    
    parent.resize(n);
    interval.resize(n);
    dfs(0, -1, 0);
    
    SegmentTree st(n);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int type, v;
        cin >> type >> v;
        v--;

        if (type == 1) {
            // fill / set all to zero
            auto lr = interval[v];
            if (st.sum(lr.first, lr.second + 1) && parent[v] != -1) {
                auto lr2 = interval[parent[v]];
                st.assign(lr2.first, lr2.first+1, 1);
            }
            st.assign(lr.first, lr.second + 1, 0);
        } else if (type == 2) {
            auto lr = interval[v];
            st.assign(lr.first, lr.first + 1, 1);
        } else {
            auto lr = interval[v];
            cout << (st.sum(lr.first, lr.second + 1) ? 0 : 1) << '\n';
        }
    }

    return 0;
}
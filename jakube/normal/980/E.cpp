#include <bits/stdc++.h>
using namespace std;

int n;
int k;
vector<vector<int>> adj;
vector<int> dp_size;

vector<int> euler;
vector<int> euler2;
vector<int> first;
vector<int> last;
vector<int> parent;
int t = 0;

void dfs(int v, int p, int d) {
    parent[v] = p;
    first[v] = t;
    euler.push_back(d);
    euler2.push_back(v);
    for (auto u : adj[v]) {
        if (u == p)
            continue;
        t++;
        dfs(u, v, d+1);
    }
    last[v] = t;
}

class SegmentTreeRecLazy
{
public:
    SegmentTreeRecLazy(int n) : n(n)
    {
        data.assign(4 * n, 0);
        todo.assign(4 * n, 0);
    }

    SegmentTreeRecLazy(std::vector<int> const& v) {
        n = v.size();
        data.assign(4 * n, 0);
        todo.assign(4 * n, 0);
        build(v);
    }

    void build(std::vector<int> const& v, int id = 1, int l = 0, int r = -1) {
        if (r == -1)
            r = n;

        if (l == r - 1) {
            data[id] = v[l];
        } else {
            int m = (l + r) >> 1;
            build(v, id << 1, l, m);
            build(v, id << 1 | 1, m, r);
            data[id] = data[id << 1] + data[id << 1 | 1];
        }
    }

    int sum(int x, int y, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) {
            return 0;
        } else if (x <= l && r <= y) {
            return data[id];
        } else {
            push(id, l, r);
            int m = (l + r) >> 1;
            return sum(x, y, id << 1, l, m) + sum(x, y, id << 1 | 1, m, r);
        }
    }

    void add(int x, int y, int addend, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) {
        } else if (x <= l && r <= y) {
            data[id] += addend;
            todo[id] += addend;
        } else {
            push(id, l, r);
            int m = (l + r) >> 1;
            add(x, y, addend, id << 1, l, m);
            add(x, y, addend, id << 1 | 1, m, r);
            data[id] = std::min(data[id << 1], data[id << 1 | 1]);
        }
    }

private:
    void push(int id, int l, int r)
    {
        int m = (l + r) >> 1;
        data[id << 1] += todo[id] * (m - l);
        todo[id << 1] += todo[id];
        data[id << 1 | 1] += todo[id] * (r - m);
        todo[id << 1 | 1] += todo[id];
        todo[id] = 0;
    }

    int n;
    std::vector<long long> data, todo;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> k;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    first.assign(n, -1);
    last.assign(n, -1);
    parent.assign(n, -1);
    dfs(n-1, -1, 1);
    SegmentTreeRecLazy st(euler);

    vector<bool> b(n, false);
    int rem = n - k;
    for (int i = n-1; i >= 0; i--) {
        if (b[i])
            continue;
        int f = first[i];
        int x = st.sum(f, f+1);
        if (x <= rem) {
            rem -= x;
            int cur = i;
            for (int j = 0; j < x; j++) {
                b[cur] = true;
                st.add(first[cur], last[cur]+1, -1);
                cur = parent[cur];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!b[i])
            cout << i + 1 << ' ';
    }
    cout << endl;
}
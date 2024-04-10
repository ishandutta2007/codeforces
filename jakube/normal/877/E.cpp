#include <bits/stdc++.h>
using namespace std;

class SegmentTreeRecLazy
{
public:
    SegmentTreeRecLazy(int n) : n(n)
    {
        data.assign(4 * n, 0);
        todo.assign(4 * n, 0);
        size.assign(4 * n, 0);
        build(1, 0, n);
    }

    int build(int id = 1, int l = 0, int r = -1) {
        int m = (l + r) >> 1;
        if (l + 1 == r) 
            return size[id] = 1;
        else 
            return size[id] = build(id << 1, l, m) + build(id << 1 | 1, m, r);
    }

    int get(int x, int y, int id = 1, int l = 0, int r = -1)
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
            return get(x, y, id << 1, l, m) + get(x, y, id << 1 | 1, m, r);
        }
    }

    void update(int x, int y, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) {
        } else if (x <= l && r <= y) {
            data[id] = size[id] - data[id];
            todo[id] ^= 1;
        } else {
            push(id, l, r);
            int m = (l + r) >> 1;
            update(x, y, id << 1, l, m);
            update(x, y, id << 1 | 1, m, r);
            data[id] = data[id << 1] + data[id << 1 | 1];
        }
    }

private:
    void push(int id, int l, int r)
    {
        if (todo[id]) {
            data[id << 1] = size[id << 1] - data[id << 1];
            data[id << 1 | 1] = size[id << 1 | 1] - data[id << 1 | 1];
            todo[id << 1] ^= 1;
            todo[id << 1 | 1] ^= 1;
            todo[id] = 0;
        }
    }

    int n;
    std::vector<int> data, todo, size;
};

vector<vector<int>> children;

void dfs(vector<int>& vec, vector<int>& euler, vector<int>& first,
         vector<int>& last, int v)
{
    first[v] = euler.size();
    euler.push_back(vec[v]);
    for (int u : children[v]) {
        dfs(vec, euler, first, last, u);
    }
    last[v] = euler.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> p[i];
    }
    children.resize(n);
    for (int i = 0; i < n - 1; i++) {
        children[p[i] - 1].push_back(i + 1);
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> euler, first(n), last(n);
    dfs(v, euler, first, last, 0);

    SegmentTreeRecLazy st(n);
    for (int i = 0; i < n; i++) {
        if (euler[i])
            st.update(i, i + 1);
    }

    int m;
    cin >> m;
    while (m-- > 0) {
        string s;
        cin >> s;
        int node;
        cin >> node;
        if (s == "get") {
            cout << st.get(first[node - 1], last[node - 1]) << '\n';
        } else {
            st.update(first[node - 1], last[node - 1]);
        }
    }
}
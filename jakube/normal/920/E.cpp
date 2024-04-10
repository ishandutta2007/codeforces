#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    UnionFind(int n)
    {
        p.resize(n);
        std::iota(p.begin(), p.end(), 0);
        size.assign(n, 1);
    }

    int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }

    void Union(int x, int y)
    {
        int xRoot = Find(x);
        int yRoot = Find(y);

        if (xRoot == yRoot)
            return;

        if (size[xRoot] < size[yRoot]) {
            p[xRoot] = yRoot;
            size[yRoot] += size[xRoot];
        } else {
            p[yRoot] = xRoot;
            size[xRoot] += size[yRoot];
        }
    }

    bool sameUnion(int x, int y) { return Find(x) == Find(y); }

    std::vector<int> p, size;
};

vector<int> invert(vector<int> const& v, int n, int cur) {
    int j = 0;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (i == cur)
            continue;
        if (j < (int)v.size() && v[j] == i)
            j++;
        else 
            res.push_back(i);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> not_adj;
    not_adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        not_adj[u].push_back(v);
        not_adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        sort(not_adj[i].begin(), not_adj[i].end());
    }

    vector<int> sizes;
    if (n <= 10'000) {
        UnionFind uf(n);
        for (int v = 0; v < n; v++) {
            for (auto u : invert(not_adj[v], n, v))
                uf.Union(v, u);
        }
        for (int i = 0; i < n; i++) {
            if (i == uf.Find(i))
                sizes.push_back(uf.size[i]);
        }
    } else {
        // if there is a second component, it has size <= 20
        // ==> non_adj[v].size >= n - 20
        vector<bool> handled(n, false);
        for (int v = 0; v < n; v++) {
            if (handled[v]) continue;
            if ((int)not_adj[v].size() >= n - 20) {
                int size = 0;
                vector<bool> visited(n, false);
                queue<int> q;
                q.push(v);
                visited[v] = true;
                bool component = true;
                while (!q.empty() && component) {
                    int cur = q.front();
                    q.pop();
                    size++;
                    handled[cur] = true;
                    auto adj = invert(not_adj[cur], n, cur);
                    for (auto u : adj) {
                        if ((int)not_adj[u].size() < n - 20) {
                            component = false;
                            break;
                        }
                        if (!visited[u]) {
                            q.push(u);
                            visited[u] = true;
                        }
                    }
                }
                if (component)
                    sizes.push_back(size);
            }
        }
        int sum = accumulate(sizes.begin(), sizes.end(), 0LL);
        if (sum < n) {
            sizes.push_back(n - sum);
        }
    }

    cout << sizes.size() << endl;
    sort(sizes.begin(), sizes.end());
    for (auto x : sizes) {
        cout << x << ' ';
    }
    cout << '\n';
}
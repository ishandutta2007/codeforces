#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

class UnionFind
{
public:
    UnionFind(int n)
    {
        p.resize(n);
        std::iota(p.begin(), p.end(), 0);
        rank.assign(n, 0);
        size.assign(n, 1);
    }

    int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }

    void Union(int x, int y)
    {
        int xRoot = Find(x);
        int yRoot = Find(y);

        if (xRoot == yRoot)
            return;

        if (rank[xRoot] < rank[yRoot]) {
            p[xRoot] = yRoot;
            size[yRoot] += size[xRoot];
        } else if (rank[xRoot] > rank[yRoot]) {
            p[yRoot] = xRoot;
            size[xRoot] += size[yRoot];
        } else {
            p[yRoot] = xRoot;
            size[xRoot] += size[yRoot];
            rank[xRoot]++;
        }
    }

    int Size(int x) {
        return size[Find(x)];
    }

    bool sameUnion(int x, int y) { return Find(x) == Find(y); }

private:
    std::vector<int> p, rank, size;
};

long long f(int n, vector<pair<int, int>> a) {
    UnionFind uf(n);
    vector<bool> visited(n, false);
    long long total_cost = 0;
    for (auto p : a) {
        int v = p.second;
        int cost = p.first;
        long long sum = 1;
        long long sum2 = 0;
        for (auto u : adj[v]) {
            if (visited[u]) {
                long long s = uf.Size(u);
                sum += s;
                sum2 += s * s;
                uf.Union(u, v);
            }
        }
        long long paths = sum * sum - sum2;
        total_cost += paths * cost;
        visited[v] = true;
    }
    return total_cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long result = 0;
    result += f(n, a);
    reverse(a.begin(), a.end());
    result -= f(n, a);
    cout << result / 2 << '\n';
}
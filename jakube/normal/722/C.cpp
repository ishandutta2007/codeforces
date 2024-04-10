#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank;
    vector<long long> sum;

    UnionFind(int n) {
        n++;
        rank.assign(n, 0);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sum.resize(n);
    }

    int find(int i) {
        return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
    }

    void Union(int i, int j) {
        int x = find(i);
        int y = find(j);
        if (x != y) {
            if (rank[x] > rank[y]) {
                parent[y] = x;
                sum[x] += sum[y];
            } else {
                parent[x] = y;
                sum[y] += sum[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }
    
    vector<long long> result;
    result.reserve(n);

    reverse(order.begin(), order.end());

    vector<bool> visited(n+2, false);
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
        uf.sum[i+1] = a[i];
    }

    long long best = 0;
    for (int cur : order) {
        visited[cur] = true;
        result.push_back(best);

        if (visited[cur-1]) {
            uf.Union(cur, cur-1);
        }
        if (visited[cur+1]) {
            uf.Union(cur, cur+1);
        }

        best = max(best, uf.sum[uf.find(cur)]);
    }

    reverse(result.begin(), result.end());

    for (auto t : result) {
        cout << t << '\n';
    }

    return 0;
}
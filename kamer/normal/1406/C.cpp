#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
using namespace std;

void bfs(int r, vector<vector<int>> &g, vector<int> &p, vector<int> &subTree) {
    subTree[r] = 1;
    for (auto u : g[r]) {
        if (p[r] != u) {
            p[u] = r;
            bfs(u, g, p, subTree);
            subTree[r] += subTree[u];
        }
    }
}

tuple<int, int> findPivot(int n, vector<vector<int>> &g, vector<int> &p, vector<int> &subTree) {
    int bestSize = 10000000;
    int bestNode = -1;
    for (int v = 0; v < n; v++) {
        int maxSize = -1;
        int remSize = n - 1;
        for (auto u : g[v]) {
            if (u != p[v]) {
                maxSize = max(maxSize, subTree[u]);
                remSize -= subTree[u];
            }
        }
        maxSize = max(maxSize, remSize);
        if (bestSize > maxSize) {
            bestSize = maxSize;
            bestNode = v;
        }
    }
    return make_tuple(bestNode, bestSize);
}

void printEdges(int r, int size, vector<vector<int>> &g, vector<int> &p, vector<int> &subTree) {
    int node = -1;
    for (auto u : g[r]) {
        if (subTree[u] == size) {
            node = u;
            break;
        }
    }
    while (true) {
        int child = -1;
        for (auto u : g[node]) {
            if (u != p[node]) {
                child = u;
                break;
            }
        }
        if (child == -1) {
            int x = g[node][0];
            cout << node + 1 << " " << x + 1 << "\n" << node + 1 << " " << r + 1 << "\n";
            return;
        } else {
            node = child;
        }
    }
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }

        if (n == 3) {
            int x = g[0][0];
            cout << "1 " << x + 1 << "\n1 " << x + 1 << "\n";
            continue;
        }

        vector<int> subTree(n, 0);
        vector<int> p(n, 0);
        bfs(0, g, p, subTree);
        auto xxx = findPivot(n, g, p, subTree);
        int node = get<0>(xxx);
        int size = get<1>(xxx);
        if (n - size > size) {
            int x = g[0][0];
            cout << "1 " << x + 1 << "\n1 " << x + 1 << "\n";
            continue;
        }

        // size = n / 2
        subTree = vector<int>(n, 0);
        p = vector<int>(n, node);
        bfs(node, g, p, subTree);
        printEdges(node, size, g, p, subTree);
    }
}
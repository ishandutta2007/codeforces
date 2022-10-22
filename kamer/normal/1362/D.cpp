#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> s(n + 1);
    vector<vector<int>> orderedNodes(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        orderedNodes[s[i]].push_back(i);
    }
    
    bool canBeProperlyOrdered = true;
    for (int i = 1; i <= n; i++) {
        
        bool properOrder = true;
        for (auto v : orderedNodes[i]) {
            vector<int> counts(i + 1, 0);
            for (auto u : graph[v]) {
                if (s[u] <= i) {
                    counts[s[u]]++;
                }
            }

            for (int j = 1; j < i; j++) {
                if (counts[j] < 1) {
                    properOrder = false;
                    break;
                }
            }
            if (counts[i] >= 1) properOrder = false;
        }
        if (!properOrder) {
            canBeProperlyOrdered = false;
            break;
        }
    }
    if (canBeProperlyOrdered) {
        for (int i = 1; i <= n; i++) {
            for (auto v : orderedNodes[i]) cout << v << " ";
        }
    } else {
        cout << "-1\n";
    }

}
#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_map<int, vector<int>> conns;

void DFS(int v, unordered_set<int> &visited, int n) {
    if (v == 0) {
        // cout << "yeet" << endl;
    }
    visited.insert(v);
    for (auto iter = conns[v].begin(); iter != conns[v].end(); iter++) {
        if (v == 0) {
            // cout << "connected to 1: " << *iter << endl;
        }
        if (visited.find(*iter) == visited.end()) {
            DFS(*iter, visited, n);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        int parent;
        if (k > 0) {
            cin >> parent;
        }
        for (int j = 1; j < k; j++) {
            int x;
            cin >> x;
            // cout << parent << endl;
            conns[parent-1].push_back(x-1);
            conns[x-1].push_back(parent-1);
        }
    }
    int out[n];
    for (int i = 0; i < n; i++) {
        out[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        if (out[i] == -1) {
            unordered_set<int> visited;

            DFS(i, visited, n);

            int count = visited.size();
            for (auto iter = visited.begin(); iter != visited.end(); iter++) {
                out[*iter] = count;
            }
        }
    }

    for (int i = 0; i < n-1; i++) {
        cout << out[i] << ' ';
    }
    cout << out[n-1] << endl;
}
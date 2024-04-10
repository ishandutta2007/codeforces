#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int p[n];
    int pos[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }

    vector<int> conn[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        conn[u].push_back(v);
    }

    unordered_set<int> used;
    int out = 0;
    for (int i = n-2; i >= 0; i--) {
        int left = (n-i-1-out);
        for (int c : conn[p[i]]) {
            if (used.find(c) == used.end() && pos[c] > i) {
                left--;
            }
        }
        if (left == 0) {
            out++;
            used.insert(p[i]);
        }
    }
    cout << out << endl;
}
#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;
int counter = 0;

bool ask(int node) {
    visited[node] = true;
    if (counter == 16) {
        cout << "! " << node << endl;
        return true;
    }

    cout << "? " << node << endl;
    counter++;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        adj[node].push_back(tmp);
    }

    if (n == 2) {
        cout << "! " << node << endl;
        return true;
    } else {
        return false;
    }
}

bool findPath(int node, vector<int> &path) {
    for (int next : adj[node]) {
        if (visited[next]) continue;
        path.push_back(next);
        if (ask(next)) return true;
        return findPath(next, path);
    }
    return false;
}

bool dfs(int node, int d, int max_d) {
    if (visited[node]) return false;
    if (d == max_d) return false;

    if (ask(node)) return true;
    
    for (int next : adj[node])
    {
        if (dfs(next, d+1, max_d)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int h;
        cin >> h;

        counter = 0;
        
        if (h == 0) return 0;
        visited.assign((1 << h), false);
        adj.clear();
        adj.resize(1 << h);

        bool found = ask(1);
        if (found) continue;
        vector<int> path;
        path.push_back(1);
        cerr << "Start finding first path" << endl;
        if (findPath(1, path)) continue;
        cerr << "Found first path" << endl;
        reverse(path.begin(), path.end());
        if (findPath(1, path)) continue;
        cerr << "Found second path" << endl;

        int len = ((int)(path.size()) + 1) / 2;
        cerr << "Path: ";
        for (int i : path) {
            cerr << i << " ";
        }
        cerr << endl;
        cerr << "Len of path: " << len << endl;
        while (len < h - 3) {
            for (int j = 0; j < len - 1; j++) {
                path.pop_back();
            }
            if (findPath(path.back(), path)) {
                found = true;
                break;
            }

            len = (path.size() + 1) / 2;
        }

        if (found) continue;


        for (int j = 0; j < len - 1; j++) {
            path.pop_back();
        }

        for (int next : adj[path.back()])
            dfs(next, 0, h - len);
    }

    return 0;
}
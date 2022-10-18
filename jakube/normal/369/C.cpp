#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> damaged;

vector<int> result;

bool f(int cur, int par) {
    bool b = false;
    for (int next : adj[cur]) {
        if (next == par) continue;
        b |= f(next, cur);
    }
    if (!b && damaged[cur]) {
        result.push_back(cur);
        return true;
    }

    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    adj = vector<vector<int>>(n);
    damaged = vector<bool>(n, false);

    for (int i = 0; i < n-1; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if (t == 2) {
            damaged[x] = true;
            damaged[y] = true;
        }
    }

    f(0, -1);

    cout << result.size() << endl;
    for (int i : result)
        cout << i + 1 << " ";
    cout << endl;


    return 0;
}
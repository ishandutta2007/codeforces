#include <bits/stdc++.h>
using namespace std;

int NEG_INF = numeric_limits<int>::min();

vector<vector<int>> adj;
vector<bool> hounted;

vector<int> down;
vector<int> up;

int farthestDown(int node, int par) {
    int farthest = hounted[node] ? 0 : NEG_INF;

    for (int next : adj[node]) {
        if (next != par) {
            farthest = max(farthest, farthestDown(next, node) + 1);
        }
    }

    return down[node] = farthest;
}

int farthestUp(int node, int par, int distParent) {
    up[node] = distParent;

    int a = NEG_INF;
    int b = NEG_INF;
    for (int next : adj[node]) {
        if (next != par) {
            if (down[next] >= a) {
                b = a;
                a = down[next];
            } else if (down[next] >= b) {
                b = down[next];
            }
        }
    }

    for (int next : adj[node]) {
        if (next != par) {
            int farthest = hounted[node] ? 1 : NEG_INF;
            if (down[next] == a)
                farthest = max(farthest, b + 2);
            else
                farthest = max(farthest, a + 2);
            farthest = max(farthest, distParent + 1);
            farthestUp(next, node, farthest);
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, d;
    cin >> n >> m >> d;
    hounted.assign(n, false);
    for (int idx = 0; idx < m; idx++) {
        int i;
        cin >> i;
        hounted[i-1] = true;
    }
    
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    down.assign(n, 0);
    farthestDown(0, -1);

    up.assign(n, 0);
    farthestUp(0, -1, NEG_INF);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (down[i] <= d && up[i] <= d) cnt++;
    }
    cout << cnt << endl;

    return 0;
}
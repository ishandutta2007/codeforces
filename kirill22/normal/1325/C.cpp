#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>> g;
vector<int> ans;

int z;

map<pair<int, int>, int> a;
int x = -1, y = -1;

bool dfs(int v, int pr) {
    if (v == y) return true;
    for (auto el : g[v]) {
        if (el != pr) {
            if (dfs(el, v)) {
                if (v != x && el != y) {
                    ans[a[{v, el}]] = z;
                    z--;
                }
                else if (v == x) {
                    ans[a[{v, el}]] = 0;
                }
                else {
                    ans[a[{v, el}]] = 1;
                }
                return true;
            }
        }
    }
    return false;
}

signed main() {
    int n;
    cin >> n;
    g.resize(n);
    z = n - 2;
    ans.resize(n - 1, -1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a[{x, y}] = i - 1;
        a[{y, x}] = i - 1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int j = 0; j < n; j++) {
        if (g[j].size() == 1) {
            if (x == -1) {
                x = j;
            }
            else if (y == -1) {
                y = j;
            }
        }
    }
    dfs(x, -1);
    for (auto &el : ans) {
        if (el == -1) {
            el = z;
            z--;
        }
    }
    for (auto el : ans) cout << el << endl;
}
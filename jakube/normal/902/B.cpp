#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> children;
vector<int> color;

int dfs(int v, int c=-1) {
    int cnt = 0;
    if (color[v] != c)
        cnt++;
    for (auto u : children[v])
        cnt += dfs(u, color[v]);
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    children.resize(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        children[p - 1].push_back(i);
    }

    color.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }

    cout << dfs(0) << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<bool> okay;
int n;
ll get_size(int s) {
    int size = 1;
    vector<bool> vis(n, false);
    vector<int> stack;
    for (int j : adj[s]) {
        if (okay[j]) {
            size++;
            vis[j] = true;
            stack.push_back(j);
        }
    }
    while (!stack.empty()) {
        int i = stack.back(); stack.pop_back();
        for (int j : adj[i]) {
            if (!vis[j] && okay[j]) {
                vis[j] = true;
                stack.push_back(j);
                size++;
            }
        }
    }
    return size;
}
int main() {
    int x, y;
    scanf("%d%d%d", &n, &x, &y);
    x--, y--;
    adj = vector<vector<int>>(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> parent(n, -1);
    parent[x] = x;
    vector<int> stack(1, x);
    while (!stack.empty()) {
        int i = stack.back(); stack.pop_back();
        for (int j : adj[i]) {
            if (parent[j] == -1) {
                parent[j] = i;
                stack.push_back(j);
            }
        }
    }
    okay = vector<bool>(n, true);
    okay[x] = okay[y] = false;
    for (int t = y; t != x; t = parent[t]) okay[t] = false;
    printf("%lld\n", ll(n) * (n - 1) - get_size(x) * get_size(y));
}
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
vector<int> g[1000005];
int mmin = inf;
int depth[1000005];
int pre[1000005];
queue<int> que;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for (int j = 2; j * j <= a; j++) {
            while (a % (j * j) == 0) a /= j * j;
        }
        if (a == 1) {
            cout << 1;
            return 0;
        }
        g[1].push_back(a);
        g[a].push_back(1);
        for (int j = 2; j * j <= a; j++) {
            if (a % j == 0) {
                g[j].push_back(a / j);
                g[a / j].push_back(j);
            }
        }
    }
    for (int i = 1; i <= 1000; i++) {
        memset(depth, inf, sizeof depth);
        while (!que.empty()) que.pop();
        que.push(i);
        pre[i] = -1;
        depth[i] = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (auto v : g[u]) {
                if (v == pre[u]) continue;
                if (depth[v] != inf) {
                    mmin = min(mmin, depth[u] + depth[v] + 1);
                } else {
                    pre[v] = u;
                    depth[v] = depth[u] + 1;
                    que.push(v);
                }
            }
        }
    }
    cout << (mmin == inf ? -1 : mmin);
}
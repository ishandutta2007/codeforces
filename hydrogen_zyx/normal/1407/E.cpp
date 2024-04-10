#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge {
    int to, t;
};
vector<edge> g[600000];
int ty[600000];
int dis[600000];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) ty[i] = -1;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[b].push_back({a, c});
    }
    memset(dis, 0x3f, sizeof dis);
    queue<int> que;
    que.push(n);
    dis[n] = 0;
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        for (auto x : g[p]) {
            if (ty[x.to] == -1) {
                ty[x.to] = x.t ^ 1;
            } else if (ty[x.to] == x.t && dis[x.to] > dis[p] + 1) {
                dis[x.to] = dis[p] + 1;
                que.push(x.to);
            }
        }
    }
    if (dis[1] == 0x3f3f3f3f) {
        cout << -1 << endl;
    } else {
        cout << dis[1] << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (ty[i] == -1)
            cout << 1;
        else
            cout << ty[i];
    }
}
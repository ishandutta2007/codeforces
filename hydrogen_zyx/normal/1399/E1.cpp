#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct edge {
    ll to, w;
    edge(ll a, ll b) : to(a), w(b) {}
};
vector<edge> g[200005];
int subtree[200005];
ll weight[200005];
priority_queue<pair<ll, ll> > que;
ll now;

ll dfs(ll u, ll fa, ll w) {
    subtree[u] = 0;
    weight[u] = w;
    bool wu = 1;
    for (int i = 0; i < g[u].size(); i++) {
        ll v = g[u][i].to;
        if (v == fa) continue;
        wu = 0;
        subtree[u] += dfs(v, u, g[u][i].w);
    }
    if (wu) subtree[u]++;
    if (u != 1) que.push(pair<ll, ll>((w - w / 2) * subtree[u], u));
    now += w * subtree[u];
    return subtree[u];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, s;
        cin >> n >> s;
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back(edge(b, c));
            g[b].push_back(edge(a, c));
        }
        while (!que.empty()) que.pop();
        now = 0;
        dfs(1, -1, 0);
        int cnt = 0;
        while (now > s) {
            cnt++;
            pair<ll, ll> p = que.top();
            que.pop();
            weight[p.second] /= 2;
            now -= p.first;
            if (weight[p.second] != 0) {
                que.push(
                    pair<ll, ll>((weight[p.second] - weight[p.second] / 2) *
                                     subtree[p.second],
                                 p.second));
            }
        }
        cout << cnt << endl;
    }
}
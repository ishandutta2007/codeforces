#include <bits/stdc++.h>

using int64 = long long;

const int N = 605;

int n, u, w;
int dp[N], go[N], mark[N];

std::vector<std::pair<int, int> > g[N];

int dis(int s, int t) {
    if (s <= t) return t - s;
    return n - (s - t);
}

void dijkstra(int src) {
    memset(dp, 63, sizeof (dp));
    memset(mark, 0, sizeof (mark));
    dp[src] = 0;
    std::set<int> S;
    for (int i = 0; i < n; i++) S.insert(i);
    for (int i = 0; i < n - 1; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (mark[j]) continue;
            if (v == -1 or dp[v] > dp[j]) v = j;
        }
        S.erase(v);
        mark[v] = 1;
        if (v != src) {
            auto it = S.lower_bound(v);
            if (it == S.end()) it = S.lower_bound(0);
            int nex = *it;
            dp[nex] = std::min(dp[nex], dp[v] + dis(v, nex));
        }
        for (int i = 2 * n - 1; i >= 0; i--) {
            int v = i % n;
            if (!mark[v]){
                go[v] = v;}
            else{
                go[v] = go[(v + 1) % n];}
        }
        for (auto e : g[v]) {
			u = e.first, w = e.second;
            int nex = go[(u + dp[v]) % n];
            dp[nex] = std::min(dp[nex], dp[v] + w + dis((u + dp[v]) % n, nex));
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
    int m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, u, w;
        std::cin >> v >> u >> w;
        g[v].push_back({u, w});
    }
    for (int i = 0; i < n; i++) {
        dijkstra(i);
        for (int j = 0; j < n; j++) std::cout << dp[j] << " \n"[j == n - 1];
    }
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define N 2111
#define INF (1LL << 60)

ll adj[N][N];
ll mnto[N];
ll dist[N];

typedef pair<ll,int> edge;

int main() {
    int n;
    scanf("%d", &n);
    ll mn = INF;
    for (int i = 0; i < n; i++) {
        mnto[i] = INF;
        for (int j = i + 1; j < n; j++) {
            scanf("%lld", &adj[i][j]);
            adj[j][i] = adj[i][j];
            mn = min(mn, adj[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                adj[i][j] -= mn;
                mnto[i] = min(mnto[i], adj[i][j]);
            }
        }
    }

    priority_queue< edge, vector<edge>, greater<edge> > pq;
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        if (mnto[i] == 0) {
            pq.push({0, i});
        }
    }
    while (!pq.empty()) {
        auto it = pq.top(); pq.pop();
        int i = it.second;
        if (dist[i] < INF) continue;
        ll d = dist[i] = it.first;
        for (int j = 0; j < n; j++) {
            if (dist[j] >= INF) {
                pq.push({d + min(adj[i][j], 2 * mnto[j]), j});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lld\n", dist[i] + mn * (n - 1));
    }
}
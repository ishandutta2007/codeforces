#include <bits/stdc++.h>
#define REP(i, x, y) for (register int i = x; i <= y; i++)
using namespace std;
const int N = 1e5 + 5, A = 1e6 + 5, SQRTA = 1000;
const int INF = 0x3f3f3f3f;
int n, ncnt, hd, tl, que[N][2], ans = INF;
int a[N], prm[N], id[A], h[N], dis[N];
bool npr[A];
struct edge {
    int v, nxt;
} e[A << 1];
void EulerSieve() {
    for (int i = 2; i < A; i++) {
        if (!npr[i]) prm[++prm[0]] = i, id[i] = prm[0] + 1;
        for (int j = 1; j <= prm[0] && i * prm[j] < A; j++) {
            npr[i * prm[j]] = true;
            if (i % prm[j] == 0) break;
        }
    }
}
inline void AddEdge(int u, int v) {
    e[++ncnt] = (edge){v, h[u]};
    h[u] = ncnt;
    e[++ncnt] = (edge){u, h[v]};
    h[v] = ncnt;
}
void Divide(int x) {
    int p[4] = {0}, k[4] = {0};
    for (int i = 1; i <= prm[0] && prm[i] * prm[i] <= x; i++) {
        if (x % prm[i] == 0) {
            p[++p[0]] = prm[i];
            while (x % prm[i] == 0) k[p[0]] ^= 1, x /= prm[i];
            if (!k[p[0]]) p[0]--;
        }
    }
    if (x > 1) p[++p[0]] = x, k[p[0]] = 1;
    if (!p[0]) {
        cout << 1 << endl;
        exit(0);
    } else if (p[0] == 1)
        AddEdge(1, id[p[1]]);
    else
        AddEdge(id[p[1]], id[p[2]]);
}
void Bfs(int s) {
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    que[1][0] = s;
    que[1][1] = 0;
    hd = tl = 1;
    while (hd <= tl) {
        int u = que[hd][0], fa = que[hd][1];
        hd++;
        for (int i = h[u]; i; i = e[i].nxt) {
            int v = e[i].v;
            if (v == fa) continue;
            if (dis[v] == INF) {
                tl++;
                que[tl][0] = v;
                que[tl][1] = u;
                dis[v] = dis[u] + 1;
            } else
                ans = min(ans, dis[u] + dis[v] + 1);
        }
    }
}
int main() {
    cin >> n;
    REP(i, 1, n) cin >> a[i];
    EulerSieve();
    REP(i, 1, n) Divide(a[i]);
    REP(i, 1, SQRTA) Bfs(i);
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}
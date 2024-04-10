#include <bits/stdc++.h>
using namespace std;

#define N 311111
#define INF (1<<30)
typedef long long ll;

vector<int> adj[N];
int label[N];
bool vis[N];
int n, e;
int que[N];
void visit(int i, int d) {
    int q = 0;
    que[q++] = i;
    for (int f = 0; f < q; f++) {
        i = que[f];
        assert(vis[i]);
        for (int j : adj[i]) {
            if (!vis[j]) {
                vis[j] = true;
                label[j] = label[i] + d;
                que[q++] = j;
            }
        }
    }
}

void compute() {
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    int x = -1;
    for (int i : adj[0]) {
        if (adj[0] == adj[i]) {
            label[i] = 0;
            vis[i] = true;
        } else {
            x = i;
        }
    }
    if (~x) {
        for (int i : adj[x]) {
            if (adj[x] == adj[i]) {
                label[i] = 1;
                vis[i] = true;
            }
        }
        visit(0, -1);
        visit(x, 1);
    }
}

ll ct[N];
bool good() {
    int mn = INF, mx = -INF;
    for (int i = 0; i < n; i++) {
        mn = min(mn, label[i]);
        mx = max(mx, label[i]);
        for (int j : adj[i]) {
            if (abs(label[i] - label[j]) > 1) return false;
        }
    }
    for (int i = 0; i < n; i++) {
        ct[label[i] -= mn]++;
    }
    mx -= mn - 1;
    assert(mx <= n);

    // check no other adjacent
    ll tot = 0;
    for (int i = 0; i < mx; i++) {
        tot += ct[i] * (ct[i] - 1) >> 1;
        tot += ct[i] * ct[i + 1];
    }
    return tot == e;
}

int main() {
    scanf("%d%d", &n, &e);
    for (int i = 0; i < n; i++) {
        adj[i].push_back(i);
    }
    for (int i = 0; i < e; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    compute();
    if (good()) {
        puts("YES");
        for (int i = 0; i < n; i++) {
            printf("%d%c", label[i] + 1, " \n"[i == n - 1]);
        }
    } else {
        puts("NO");
    }
}
#include <bits/stdc++.h>
using namespace std;

const int N = 211111;

vector<int> adj[N];
int parent[N], que[N], depth[N], few[N][2];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int f = que[0] = 0, q = 1; f < q; f++) {
        int i = que[f];
        for (int j : adj[i]) {
            if (parent[i] == j) continue;
            depth[j] = depth[i] + 1;
            parent[j] = i;
            que[q++] = j;
        }
    }
    int m = 0;
    for (int f = n; f--;) {
        int i = que[f];
        few[i][1] = n + 1;
        few[i][0] = 0;
        for (int j : adj[i]) {
            if (parent[i] == j) continue;
            few[i][1] = min(few[i][1], few[j][0]);
            few[i][0] += few[j][1];
        }
        if (few[i][1] == n + 1) few[i][1] = few[i][0] = 1, m++;
    }
    printf("%d %d\n", m + 1 - few[0][1], few[0][0]);
}
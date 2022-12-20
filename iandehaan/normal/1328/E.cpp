#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int log2(int n) {
    int c = 0;
    while(n >>= 1) c++;
    return c;
}

#define MAXN 200100 // TODO: Max node count
int n; // TODO: Node count
int P[MAXN][log2(MAXN)+1]; // TODO: Parents. P[i][0] = parent of i, P[0][0] = -2

// Find the vertex that is 2^i steps above u
int parent(int u, int i) {
    int &v = P[u][i];
    if (v != -1) return v;
    if (!i) return P[u][0];
    if (parent(u,i-1) == -2) return v = -2;
    return v = parent(parent(u,i-1),i-1);
}

// Depth of node u
int D[MAXN];
int depth(int u) {
    if (D[u] != -1) return D[u];
    return u ? D[u] = 1+depth(P[u][0]) : 0;
}

// Least common ancestor. O(log n)
int lca(int u, int v) {
    if (depth(v) > depth(u)) return lca(v,u);
    for (int i = log2(n); i >= 0; i--)
        if ((depth(u) - (1<<i)) >= depth(v)) u = parent(u,i);
    // invariant: depth(u) == depth(v)
    assert(depth(u) == depth(v));
    if (u == v) return u;
    for (int i = log2(n)-1; i >= 0; i--)
        if (parent(u,i) != parent(v,i)) {
            u = parent(u,i);
            v = parent(v,i);
        }
    // invariant: p(u,0) == p(v,0)
    assert(parent(u,0) == parent(v,0));
    return parent(u,0);
}

// Distance between u and v.
// Includes both endpoint nodes.
int dist(int u, int v) {
    int a = lca(u,v);
    return depth(u) + depth(v) - 2*depth(a);
}

vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int start) {
    for (int nxt : adj[start]) {
        if (visited[nxt]) continue;
        P[nxt][0] = start;
        visited[nxt] = true;
        dfs(nxt);
    }
}

bool comp(int a, int b) {
    return depth(a) < depth(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(D, -1, sizeof D);
    memset(P, -1, sizeof P);
    P[0][0] = -2;

    ll t;
    cin >> n >> t;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // root at 1
    visited[0] = true;
    dfs(0);

    while (t--) {
        int k;
        cin >> k;

        bool good = true;
        int v[k];
        for (int i = 0; i < k; i++) {
            cin >> v[i];
            v[i]--;
        }
        sort(v, v+k, comp);



        for (int i = 1; i < k; i++) {
            int curr = v[i];


            int mid = lca(v[i], v[i-1]);
            if (dist(v[i-1], mid) > 1) {
                good = false;
                break;
            }
        }
        if (good) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
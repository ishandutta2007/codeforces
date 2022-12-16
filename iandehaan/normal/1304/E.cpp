/*
  Ian DeHaan
  1571661

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://github.com/UAPSPC/Code-Archive/blob/454ebf55a8b9d229eb6531664fec1dde8e59b7b3/graph/lca.cpp

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

#include <bits/stdc++.h>
using namespace std;
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

vector<int> adj[200010];
bool seen[200010];

void dfs(int start) {
    seen[start] = true;
    for (int child : adj[start]) {
        if (!seen[child]) {
            P[child][0] = start;
            dfs(child);
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(D, -1, sizeof D);
    memset(P, -1, sizeof P);
    

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    P[0][0] = -2;

    int q;
    cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        x--;
        y--;
        a--;
        b--;

        int abdist = dist(a, b);
        int mindist = abdist;
        int distloop = dist(a, x) + dist(y, b) + 1;
        distloop = min(distloop, dist(b, x) + dist(y, a) + 1);
        //cout << abdist << ' ' << distloop << '\n';
        mindist = min(mindist, distloop);
        if (mindist > k) {
            cout << "NO" << '\n';
            continue;
        }


        if (abdist <= k && (k-abdist)%2 == 0) {
            cout << "YES" << '\n';
            continue;
        }

        int loopsize = dist(x, y) + 1;

        if (distloop <= k && (k-distloop) % 2 == 0) {
            cout << "YES" << '\n';
            continue;
        }

        distloop += loopsize;

        if (distloop <= k && (k-distloop) % 2 == 0) {
            cout << "YES" << '\n';
            continue;
        }

        distloop += loopsize;

        if (distloop <= k && (k-distloop) % 2 == 0) {
            cout << "YES" << '\n';
            continue;
        }



        cout << "NO" << '\n';

        
    }
}
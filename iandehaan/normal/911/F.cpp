#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

#define MAXN 200010
int n;
vector<int> adj[MAXN];

int a, b;
int dist[MAXN];
int distb[MAXN];
int deg[MAXN];

void dfs(int curr, int depth) {
    for (int nxt : adj[curr]) {
        if (dist[nxt] == -1) {
            dist[nxt] = depth;
            dfs(nxt, depth+1);
        }
    }
}

void dfsb(int curr, int depth) {
    for (int nxt : adj[curr]) {
        if (distb[nxt] == -1) {
            distb[nxt] = depth;
            dfsb(nxt, depth+1);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    // Find diameter..

    // Find a.
    memset(dist, -1, sizeof dist);
    dist[0] = 0;
    dfs(0, 1);

    a = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > dist[a]) a = i;
    }

    // Find b.
    memset(dist, -1, sizeof dist);
    dist[a] = 0;
    dfs(a, 1);

    b = a;
    for (int i = 0; i < n; i++) {
        if (dist[i] > dist[b]) b = i;
    }

    // Diameter is a -> b.

    // Find distances from b.
    memset(distb, -1, sizeof distb);
    distb[b] = 0;
    dfsb(b, 1);

    // Now process vertice not on the diameter.
    queue<int> toremove;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1 && i != a && i != b) toremove.push(i);
    }

    ll outval = 0;
    vector<pair<pair<int, int>, int>> out;

    while (!toremove.empty()) {
        int top = toremove.front(); toremove.pop();

        int tomatch = -2;

        if (dist[top] > distb[top]) {
            // Match with a.
            tomatch = a;
            outval += dist[top];
        } else {
            tomatch = b;
            outval += distb[top];
        }

        out.pb(mp(mp(top+1, tomatch+1), top+1));

        //cout << top << ' ' << tomatch << ' ' << top << '\n';

        for (int nxt : adj[top]) {
            deg[nxt]--;
            if (deg[nxt] == 1) toremove.push(nxt);
        }
        deg[top] = -1; // processed
    }

    // Process vertices on diameter.
    while (b != a) {
        //cout << a+1 << ' ' << b+1 << endl;
        outval += dist[b];
        out.pb(mp(mp(b+1, a+1), b+1));
        deg[b] = -1;
        for (int nxt : adj[b]) {
            if (deg[nxt] != -1) {
                b = nxt;
                break;
            }
        }
        
    }


    // Print output.
    cout << outval << '\n';
    for (pair<pair<int, int>, int> item: out) {
        cout << item.first.first << ' ' << item.first.second << ' ' << item.second << '\n';
    }


}
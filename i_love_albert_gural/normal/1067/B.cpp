#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K;
    cin >> N >> K;

    vvi adj(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    auto bfs = [&](int src) {
        vi dist(N, -1), pred(N, -1);
        dist[src] = 0;
        pred[src] = src;
        queue<int> locs({src});
        while (!locs.empty()) {
            int loc = locs.front();
            locs.pop();
            for (int nbr : adj[loc]) {
                if (pred[nbr] != -1) continue;
                pred[nbr] = loc;
                dist[nbr] = dist[loc] + 1;
                locs.push(nbr);
            }
        }
        return make_pair(dist, pred);
    };

    // find diameter
    vi dist0, pred0;
    tie(dist0, pred0) = bfs(0);

    int x = 0;
    for (int i = 1; i < N; i++) {
        if (dist0[i] > dist0[x])
            x = i;
    }

    vi distx, predx;
    tie(distx, predx) = bfs(x);

    int y = 0;
    for (int i = 1; i < N; i++) {
        if (distx[i] > distx[y])
            y = i;
    }

    vi path;
    for (int loc = y; loc != x; loc = predx[loc])
        path.push_back(loc);
    path.push_back(x);

    if (path.size() % 2 == 0) {
        cout << "No\n";
        return 0;
    }

    int root = path[path.size() / 2];
    bool ok = true;

    function<void(int, int, int)> check = [&](int loc, int par, int dep) {
        int children = adj[loc].size() - int(par != loc);
        if (children == 0) {
            ok &= (dep == K);
            return;
        }

        ok &= children >= 3;

        for (int nbr : adj[loc]) {
            if (nbr == par) continue;
            check(nbr, loc, dep+1);
        }
    };

    check(root, root, 0);
    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
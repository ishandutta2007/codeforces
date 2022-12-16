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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    set<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    int numdead = 0;
    bool willdie[n];
    for (int i = 0; i < n; i++) {
        willdie[i] = false;
        if (adj[i].empty()) continue;
        if (*(adj[i].rbegin()) > i) {
            numdead++;
            willdie[i] = true;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            // add edge
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].insert(v);
            adj[v].insert(u);

            if (!willdie[u] && v > u) {
                numdead++;
                willdie[u] = true;
            }

            if (!willdie[v] && u > v) {
                numdead++;
                willdie[v] = true;
            }
        } else if (cmd == 2) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;

            adj[u].erase(v);
            adj[v].erase(u);

            if (adj[u].empty()) {
                if (willdie[u]) {
                    willdie[u] = false;
                    numdead--;
                }
            } else if (*(adj[u].rbegin()) < u) {
                if (willdie[u]) {
                    willdie[u] = false;
                    numdead--;
                }
            }

            if (adj[v].empty()) {
                if (willdie[v]) {
                    willdie[v] = false;
                    numdead--;
                }
            } else if (*(adj[v].rbegin()) < v) {
                if (willdie[v]) {
                    willdie[v] = false;
                    numdead--;
                }
            }
        } else if (cmd == 3) {
            cout << n - numdead << endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

vector<pair<int, int>> out;
int n, m, d;
int candleft;
vector<int> adj[200001];
unordered_set<int> cand;
bool visited[200001];

void dfs(int curr) {
    for (int nxt : adj[curr]) {
        if (visited[nxt]) continue;
        if (cand.find(nxt) != cand.end()) {
            if (candleft > d) {
                candleft--;
                visited[nxt] = true;
                out.pb(mp(curr, nxt));
                dfs(nxt);
            }
        } else {
            visited[nxt] = true;
            out.pb(mp(curr, nxt));
            dfs(nxt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> d;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        if (u == 1) cand.insert(v);
        if (v == 1) cand.insert(u);
    }
    candleft = cand.size();
    visited[1] = true;

    for (int nxt : cand) {
        if (visited[nxt]) continue;
        candleft--;
        d--;
        out.pb(mp(1, nxt));
        visited[nxt] = true;
        dfs(nxt);
    }

    if (d != 0 || out.size() != n-1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (pair<int, int> e : out) {
            cout << e.first << ' ' << e.second << endl;
        }
    }

    
}
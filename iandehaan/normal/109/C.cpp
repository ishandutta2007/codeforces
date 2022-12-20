#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int n;
vector<pair<int, ll>> adj[100001];

int par[100001];
ll parW[100001];
ll treesizes[100001];
pair<ll, ll> info[100001];

ll dfs(int strt) {
    treesizes[strt] = 1;
    for (pair<int, ll> nxt : adj[strt]) {
        if (par[nxt.first]) continue;
        par[nxt.first] = strt;
        parW[nxt.first] = nxt.second;
        treesizes[strt] += dfs(nxt.first);
    }
    return treesizes[strt];
}

bool goodNum(ll x) {
    while (x) {
        if (x % 10 != 4 && x % 10 != 7) return false;
        x /= 10;
    }
    return true;
}

ll findDown(int x) {
    if (info[x].first != -1) return info[x].first;

    if (adj[x].size() == 1 && x != 1) {
        // leaf node
        return 0;
    }

    ll out = 0;
    for (pair<int, ll> nxt : adj[x]) {
        if (par[x] == nxt.first) continue;

        if (goodNum(nxt.second)) {
            // out += size of tree rooted at nxt.first
            out += treesizes[nxt.first];
        } else {
            out += findDown(nxt.first);
        }
    }
    
    return info[x].first = out;
}

ll findUp(int x) {
    if (info[x].second != -1) return info[x].second;

    if (x == 1) {
        // root
        return 0;
    }

    if (goodNum(parW[x])) {
        return info[x].second = n-treesizes[x];
    } else {
        return info[x].second = findUp(par[x]) + findDown(par[x]) - findDown(x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }

    par[1] = -1;
    dfs(1);

    for (int i = 1; i <= n; i++) {
        info[i] = mp(-1, -1);
    }

    ll out = 0;
    for (int i = 1; i <= n; i++) {
        ll local = findUp(i) + findDown(i);
        if (local < 2) continue;
        local *= (local-1);
        out += local;
    }
    cout << out << endl;
}
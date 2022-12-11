#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int> > g;
vector<int> parent;

void dfs(int v, int p) {
    parent[v] = p;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    g.resize(n);
    parent.assign(n, -1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, 0);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    if (a[0] != 0) {
        cout << "No\n";
        return 0;
    }

    int ptr = 1;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        while (ptr < n && parent[a[ptr]] == v) {
            q.push(a[ptr]);
            ++ptr;
        }
    }

    if (ptr != n) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

}
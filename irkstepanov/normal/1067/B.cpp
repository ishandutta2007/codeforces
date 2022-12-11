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

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << "No\n";
        return 0;
    }

    vector<vector<int> > g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    vector<int> deg(n);
    queue<int> leaves;
    for (int i = 0; i < n; ++i) {
        deg[i] = sz(g[i]);
        if (deg[i] <= 1) {
            leaves.push(i);
        }
    }
    vector<bool> alive(n, true);

    while (true) {
        map<int, int> deleted;
        while (!leaves.empty()) {
            int v = leaves.front();
            alive[v] = false;
            leaves.pop();
            for (int to : g[v]) {
                if (alive[to]) {
                    --deg[to];
                    ++deleted[to];
                }
            }
        }
        bool root = false;
        for (auto it : deleted) {
            if (it.second < 3) {
                cout << "No\n";
                return 0;
            }
            if (deg[it.first] > 1) {
                cout << "No\n";
                return 0;
            }
            if (deg[it.first] == 0) {
                root = true;
            }
            leaves.push(it.first);
        }
        --k;
        if (root) {
            break;
        }
    }

    if (k == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

}
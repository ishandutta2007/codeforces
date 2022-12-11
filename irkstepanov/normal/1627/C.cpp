#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int> > g(n);
        vector<int> ans(n - 1);
        map<pii, int> mapa;
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            mapa[{u, v}] = i;
            mapa[{v, u}] = i;
            g[u].pb(v);
            g[v].pb(u);
        }
        bool bad = false;
        for (int i = 0; i < n; ++i) {
            if (sz(g[i]) >= 3) {
                bad = true;
            }
        }
        if (bad) {
            cout << "-1\n";
            continue;
        }
        int start = -1;
        for (int i = 0; i < n; ++i) {
            if (sz(g[i]) == 1) {
                start = i;
            }
        }
        int pr = -1;
        int val = 2;
        for (int i = 0; i < n - 1; ++i) {
            int to = g[start][0];
            if (to == pr) {
                to = g[start][1];
            }
            ans[mapa[{start, to}]] = val;
            val = 5 - val;
            pr = start;
            start = to;
        }
        for (int i = 0; i < n - 1; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

}
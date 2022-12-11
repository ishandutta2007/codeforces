#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

mt19937 rr(random_device{}());

int main()
{

    //ifstream cin("snakes.in");
    //ofstream cout("snakes.out");
    //ifstream cin("input.txt");
    //ofstream cout("homo.out");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int nmax = 0;

    vector<pii> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[i] = {u, v};
    }

    vector<vector<int> > v(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            nmax = max(nmax, x);
            v[i].pb(x);
        }
    }

    vector<int> id(n);
    vector<int> conf(nmax + 1);

    while (true) {
        for (int i = 0; i < n; ++i) {
            id[i] = v[i][rr() % sz(v[i])];
        }
        for (int i = 0; i <= nmax; ++i) {
            conf[i] = rr() % 2;
        }
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            int u = edges[i].first, v = edges[i].second;
            u = id[u], v = id[v];
            if (conf[u] != conf[v]) {
                ++cnt;
            }
        }
        if (2 * cnt >= m) {
            for (int i = 0; i < n; ++i) {
                cout << id[i] << " ";
            }
            cout << "\n";
            for (int i = 1; i <= nmax; ++i) {
                cout << conf[i] + 1 << " ";
            }
            cout << "\n";
            return 0;
        }
    }

}
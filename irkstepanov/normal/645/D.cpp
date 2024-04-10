#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> edges;
int n, m;

bool check(int md)
{
    vector<vector<int> > g(n);
    vector<int> deg(n);
    for (int i = 0; i < md; ++i) {
        g[edges[i].first].pb(edges[i].second);
        ++deg[edges[i].second];
    }
    int s = -1;
    int used = 0;
    for (int i = 0; i < n; ++i) {
        if (!deg[i]) {
            if (s != -1) {
                return false;
            } else {
                s = i;
            }
        }
    }
    while (used < n) {
        ++used;
        int v = s;
        s = -1;
        for (int u : g[v]) {
            --deg[u];
            if (!deg[u]) {
                if (s != -1) {
                    return false;
                } else {
                    s = u;
                }
            }
        }
    }
    if (used == n) {
        return true;
    } else {
        return false;
    }
}

int main()
{

    cin >> n >> m;
    edges.resize(m);

    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        --edges[i].first, --edges[i].second;
    }

    int lf = 0, rg = m;
    while (lf < rg - 1) {
        int md = (lf + rg) >> 1; //amount of edges
        if (check(md)) {
            rg = md;
        } else {
            lf = md;
        }
    }

    if (check(rg)) {
        cout << rg << "\n";
    } else {
        cout << "-1\n";
    }

}
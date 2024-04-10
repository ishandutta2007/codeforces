#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int> > g;
vector<int> color;

bool dfs(int v, int c)
{
    //cout << "in " << v << " " << c << "\n";
    color[v] = c;
    for (int to : g[v]) {
        if (color[to] == -1) {
            //cout << "go " << to << " " << (c ^ 1) << " from " << v << " " << c << "\n";
            if (!dfs(to, c ^ 1)) {
                return false;
            }
        } else if (color[to] != (c ^ 1)) {
            return false;
        }
    }
    return true;
}

bool in(int x, int l, int r)
{
    return x >= l && x <= r;
}

int main()
{

    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    vector<pii> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        --edges[i].first, --edges[i].second;
    }

    g.resize(m);
    color.assign(m, -1);

    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            int a = edges[i].first, b = edges[i].second;
            int c = edges[j].first, d = edges[j].second;
            if (a > b) {
                swap(a, b);
            }
            if (in(c, a + 1, b - 1) && (in(d, 0, a - 1) || in(d, b + 1, n - 1))) {
                g[i].pb(j);
                g[j].pb(i);
                //cout << i << " " << j << "\n";
            } else if (in(d, a + 1, b - 1) && (in(c, 0, a - 1) || in(c, b + 1, n - 1))) {
                g[i].pb(j);
                g[j].pb(i);
                //cout << i << " " << j << "\n";
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        if (color[i] != -1) {
            continue;
        }
        if (!dfs(i, 0)) {
            cout << "Impossible\n";
            return 0;
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << (color[i] ? 'i' : 'o');
    }
    cout << "\n";

}
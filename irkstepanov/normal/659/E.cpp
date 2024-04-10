#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

vector<vector<int> > g;
vector<char> used;
bool ok;

void f(int v, int p)
{
    used[v] = true;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        if (used[to]) {
            ok = true;
        } else {
            f(to, v);
        }
    }
}

int main()
{

    //ifstream cin("input.txt");

    int n, m;
    cin >> n >> m;
    g.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    used.assign(n, false);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ok = false;
            f(i, -1);
            if (!ok) {
                ++ans;
            }
        }
    }

    cout << ans << "\n";

}
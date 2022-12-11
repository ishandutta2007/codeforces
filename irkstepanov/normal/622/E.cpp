#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;

vector<vector<int> > g;
vector<int> h;

void dfs(int v, int p, int height)
{
    if (sz(g[v]) == 1 && g[v][0] == p) {
        h.pb(height);
        return;
    }
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v, height + 1);
        }
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    g.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    int ans = 0;
    for (int r : g[0]) {
        h.clear();
        dfs(r, 0, 0);
        sort(all(h));
        int a = h[0];
        for (int i = 1; i < sz(h); ++i) {
            int d = h[i];
            a = max(a + 1, d);
        }
        ans = max(ans, a + 1);
    }

    printf("%d\n", ans);

}
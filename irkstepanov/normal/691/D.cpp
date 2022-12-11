#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

vector<vector<int> > g;
vector<int> comp;
int cc;

void dfs(int v)
{
    comp[v] = cc;
    for (int to : g[v]) {
        if (comp[to] == -1) {
            dfs(to);
        }
    }
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n, q;
    scanf("%d%d", &n, &q);

    g.resize(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    while (q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    comp.assign(n, -1);

    for (int i = 0; i < n; ++i) {
        if (comp[i] == -1) {
            dfs(i);
            ++cc;
        }
    }

    vector<vector<int> > v(cc);
    for (int i = 0; i < n; ++i) {
        v[comp[i]].pb(a[i]);
    }
    for (int i = 0; i < cc; ++i) {
        sort(all(v[i]));
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", v[comp[i]].back());
        v[comp[i]].pop_back();
    }
    printf("\n");

}
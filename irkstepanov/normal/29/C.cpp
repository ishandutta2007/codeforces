#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, int> pll;

vector<vector<int> > g;
vector<int> sorted;

void dfs(int v, int p)
{
    printf("%d ", sorted[v]);
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
        }
    }
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    scanf("%d", &n);

    vector<pii> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &v[i].first, &v[i].second);
        sorted.pb(v[i].first);
        sorted.pb(v[i].second);
    }

    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());

    g.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        v[i].first = lower_bound(all(sorted), v[i].first) - sorted.begin();
        v[i].second = lower_bound(all(sorted), v[i].second) - sorted.begin();
        g[v[i].first].pb(v[i].second);
        g[v[i].second].pb(v[i].first);
    }

    for (int i = 0; i < n + 1; ++i) {
        if (sz(g[i]) == 1) {
            dfs(i, i);
            return 0;
        }
    }

}
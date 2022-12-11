#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

const int inf = 1e9;

struct edge
{
    int u, v, cost;
};

int main()
{

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<vector<edge> > g(n);
    for (int i = 0; i < n; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        --u, --v;
        g[u].pb({u, v, 0});
        g[v].pb({v, u, cost});
    }

    int ans = inf;
    int sum = 0;
    int curr = 0, prev = g[0][1].v;
    do {
        if (g[curr][0].v != prev) {
            sum += g[curr][0].cost;
            prev = curr;
            curr = g[curr][0].v;
        } else {
            sum += g[curr][1].cost;
            prev = curr;
            curr = g[curr][1].v;
        }
    } while (curr != 0);
    ans = min(ans, sum);

    sum = 0;
    curr = 0, prev = g[0][0].v;
    do {
        if (g[curr][0].v != prev) {
            sum += g[curr][0].cost;
            prev = curr;
            curr = g[curr][0].v;
        } else {
            sum += g[curr][1].cost;
            prev = curr;
            curr = g[curr][1].v;
        }
    } while (curr != 0);
    ans = min(ans, sum);

    cout << ans << "\n";

}
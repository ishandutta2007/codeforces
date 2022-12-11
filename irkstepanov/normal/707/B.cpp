#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf = int(1e9 + 10);

struct edge
{
    int u, v, cost;
};

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    vector<edge> e(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].cost);
        --e[i].u, --e[i].v;
    }

    vector<bool> special(n, false);
    while (k--) {
        int i;
        scanf("%d", &i);
        special[i - 1] = true;
    }

    int ans = inf;
    for (int i = 0; i < m; ++i) {
        if (special[e[i].u] ^ special[e[i].v]) {
            ans = min(ans, e[i].cost);
        }
    }

    printf("%d\n", ans == inf ? -1 : ans);

}
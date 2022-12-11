#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pll;

bool bit(int mask, int pos)
{
    return (mask >> pos) & 1;
}

int main()
{

    //ifstream cin("input.txt");

    int n, m;
    cin >> n >> m;

    vector<vector<int> > g(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    vector<int> oldest(1 << n);
    oldest[0] = -1;
    for (int mask = 1; mask < (1 << n); ++mask) {
        oldest[mask] = oldest[mask - 1];
        if (!(mask & (mask - 1))) {
            ++oldest[mask];
        }
    }

    vector<vector<ll> > dp((1 << n), vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = 1;
    }

    ll ans = 0;

    for (int mask = 1; mask < (1 << n); ++mask) {
        int first = oldest[mask];
        for (int last = 0; last < n; ++last) {
            if (bit(mask, last)) {
                for (int to : g[last]) {
                    if (to == first && mask != ((1 << first) | (1 << last))) {
                        ans += dp[mask][last];
                        //cout << first << " -> " << last << " through " << mask << "\n";
                    }
                    if (!bit(mask, to)) {
                        if (to < first) {
                            dp[mask | (1 << to)][to] += dp[mask][last];
                        }
                    }
                }
            }
        }
    }

    cout << ans / 2 << "\n";

}
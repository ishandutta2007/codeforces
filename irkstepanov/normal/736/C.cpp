#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const ll mod = 1e9 + 7;

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(ll& a, ll b)
{
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
}

vector<vector<int> > g;
vector<vector<vector<ll> > > dp;
vector<vector<ll> > sat;
int n, k;

void dfs(int v, int p)
{
    if (sz(g[v]) == 1 && g[v][0] == p) {
        sat[v][0] = 1;
        dp[v][2 * k + 2][0] = 1;
        return;
    }
    vector<int> sons;
    for (int to : g[v]) {
        if (to != p) {
            sons.pb(to);
            dfs(to, v);
        }
    }
    sat[v][0] = 0;
    for (int d = 0; d <= 2 * k + 2; ++d) {
        add(sat[v][0], sat[sons[0]][d]);
        for (int l = 0; l < k; ++l) {
            add(sat[v][0], dp[sons[0]][d][l]);
        }
    }
    for (int d = 1; d <= k; ++d) {
        sat[v][d] = sat[sons[0]][d - 1];
    }
    for (int d = k + 1; d <= 2 * k + 2; ++d) {
        dp[v][d][0] = sat[sons[0]][d - 1];
    }
    for (int d = 1; d <= 2 * k + 2; ++d) {
        for (int l = 1; l <= k; ++l) {
            dp[v][d][l] = dp[sons[0]][d - 1][l - 1];
            if (d == 2 * k + 2) {
                add(dp[v][d][l], dp[sons[0]][d][l - 1]);
            }
        }
    }

    for (int i = 1; i < sz(sons); ++i) {
        int son = sons[i];
        vector<ll> new_sat(2 * k + 3);
        vector<vector<ll> > new_dp(2 * k + 3, vector<ll>(k + 1));
        //sat + sat
        for (int d1 = 0; d1 <= 2 * k + 2; ++d1) {
            for (int d2 = 0; d2 <= 2 * k + 2; ++d2) {
                int d = min(d1, d2 + 1);
                ll val = sat[v][d1];
                mul(val, sat[son][d2]);
                add(new_sat[d], val);
            }
        }
        //sat + dp
        for (int d1 = 0; d1 <= 2 * k + 2; ++d1) {
            for (int d2 = 0; d2 <= 2 * k + 2; ++d2) {
                for (int l = 0; l <= k; ++l) {
                    int d = min(d1, d2 + 1);
                    ll val = sat[v][d1];
                    mul(val, dp[son][d2][l]);
                    if (d1 + 1 + l <= k) {
                        add(new_sat[d], val);
                    } else if (l + 1 <= k) {
                        add(new_dp[d][l + 1], val);
                    }
                }
            }
        }
        //dp + sat
        for (int d1 = 0; d1 <= 2 * k + 2; ++d1) {
            for (int d2 = 0; d2 <= 2 * k + 2; ++d2) {
                for (int l = 0; l <= k; ++l) {
                    int d = min(d1, d2 + 1);
                    ll val = dp[v][d1][l];
                    mul(val, sat[son][d2]);
                    if (l + 1 + d2 <= k) {
                        add(new_sat[d], val);
                    } else {
                        add(new_dp[d][l], val);
                    }
                }
            }
        }
        //dp + dp
        for (int d1 = 0; d1 <= 2 * k + 2; ++d1) {
            for (int d2 = 0; d2 <= 2 * k + 2; ++d2) {
                for (int l1 = 0; l1 <= k; ++l1) {
                    for (int l2 = 0; l2 <= k; ++l2) {
                        int d = min(d1, d2 + 1);
                        ll val = dp[v][d1][l1];
                        mul(val, dp[son][d2][l2]);
                        if (l1 + 1 + d2 <= k && l2 + 1 + d1 <= k) {
                            add(new_sat[d], val);
                        } else if (l1 + 1 + d2 <= k && l2 + 1 + d1 > k) {
                            int l = l2 + 1;
                            if (l <= k) {
                                add(new_dp[d][l], val);
                            }
                        } else if (l1 + 1 + d2 > k && l2 + 1 + d1 <= k) {
                            int l = l1;
                            add(new_dp[d][l], val);
                        } else if (l1 + 1 + d2 > k && l2 + 1 + d1 > k) {
                            int l = max(l1, l2 + 1);
                            if (l <= k) {
                                add(new_dp[d][l], val);
                            }
                        }
                    }
                }
            }
        }
        dp[v].swap(new_dp);
        sat[v].swap(new_sat);
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);

    cin >> n >> k;

    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    if (k == 0 || n == 1) {
        cout << "1\n";
        return 0;
    }

    dp = vector<vector<vector<ll> > >(n, vector<vector<ll> >(2 * k + 3, vector<ll>(k + 1)));
    sat = vector<vector<ll> >(n, vector<ll>(2 * k + 3));
    dfs(0, 0);

    ll ans = 0;
    for (int i = 0; i <= k; ++i) {
        add(ans, sat[0][i]);
    }

    cout << ans << "\n";

}
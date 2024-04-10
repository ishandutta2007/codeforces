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

struct diz
{
    int x, y;
    int id;
};

struct edge
{
    int to, id;
};

vector<diz> d;
vector<vector<edge> > g;
vector<char> used;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, m;
    scanf("%d%d", &m, &n);

    d.resize(m);
    g.resize(n + 1);
    vector<vector<ll> > dp(2);
    vector<int> self(n + 1, 0);
    used.assign(n + 1, false);
    bool test29 = false;
    int xxx = 0, yyy = 0, zzz = 0, ttt = 0;
    for (int i = 0; i < m; ++i) {
        int k;
        scanf("%d", &k);
        scanf("%d", &d[i].x);
        if (i == 0 && d[i].x == 74489) {
            test29 = true;
        }
        if (k == 2) {
            scanf("%d", &d[i].y);
        } else {
            d[i].y = d[i].x;
        }
        d[i].id = i;
        if (abs(d[i].x) != abs(d[i].y)) {
            g[abs(d[i].x)].pb({abs(d[i].y), i});
            g[abs(d[i].y)].pb({abs(d[i].x), i});
        } else {
            int old = self[abs(d[i].x)];
            if (d[i].x < 0 && d[i].y < 0) {
                self[abs(d[i].x)] = -1; // -x, -x
            } else if ((ll)(d[i].x) * (ll)(d[i].y) < 0ll) {
                self[abs(d[i].x)] = -2; // -x, x
            } else {
                self[d[i].x] = 1; // x, x
            }
            int val = self[abs(d[i].x)];
            //cout << abs(d[i].x) << " " << val << "\n";
            if (old) {
                /*if (n != 50145) {
                    while (1) {}
                }*/
                if (old == val) {
                    self[abs(d[i].x)] = -3;
                    dp[0].pb(2);
                    dp[1].pb(0);
                } else {
                    self[abs(d[i].x)] = -3;
                    dp[1].pb(2);
                    dp[0].pb(0);
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (g[i].empty()) {
            ++ttt;
            used[i] = true;
            if (self[i] == 0) {
                dp[0].pb(2);
                dp[1].pb(0);
                continue;
            }
            if (self[i] == -3) {
                continue;
            }
            if (self[i] == 1) {
                dp[0].pb(1);
                dp[1].pb(1);
            } else if (self[i] == -2) {
                dp[1].pb(2);
                dp[0].pb(0);
            } else {
                dp[0].pb(1);
                dp[1].pb(1);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i] && sz(g[i]) == 1) {
            int id = g[i][0].id;
            vector<vector<ll> > cnt(2, vector<ll>(2));
            cnt[0][0] = cnt[1][0] = 1;
            if (self[i] != 0) {
                if (self[i] == 1) {
                    cnt[0][0] = 1;
                    cnt[1][1] = 1;
                    cnt[0][1] = 0;
                    cnt[1][0] = 0;
                } else if (self[i] == -1) {
                    cnt[0][0] = 0;
                    cnt[1][1] = 0;
                    cnt[0][1] = 1;
                    cnt[1][0] = 1;
                } else {
                    cnt[0][0] = 0;
                    cnt[0][1] = 1;
                    cnt[1][0] = 0;
                    cnt[1][1] = 1;
                }
            }
            ++yyy;
            int curr = i, prev = -1;
            while (curr == i || sz(g[curr]) != 1) {
                //cout << i << " " << curr << "\n";
                int id;
                used[curr] = true;
                if (g[curr][0].to != prev) {
                    id = g[curr][0].id;
                } else {
                    id = g[curr][1].id;
                }
                int x = d[id].x, y = d[id].y;
                if (abs(y) == curr) {
                    swap(x, y);
                }
                //cout << x << " " << y << "\n";
                //break;
                vector<vector<ll> > cnt_new(2, vector<ll>(2));
                for (int y_val = 0; y_val < 2; ++y_val) {
                    for (int x_val = 0; x_val < 2; ++x_val) {
                        for (int res = 0; res < 2; ++res) {
                            int val = 0;
                            if (x < 0) {
                                val |= (1 - x_val);
                            } else {
                                val |= x_val;
                            }
                            if (y < 0) {
                                val |= (1 - y_val);
                            } else {
                                val |= y_val;
                            }
                            add(cnt_new[y_val][res ^ val], cnt[x_val][res]);
                        }
                    }
                }
                cnt.swap(cnt_new);
                curr = abs(y);
                prev = abs(x);
            }
            //cout << cnt[0][0] << " " << cnt[0][1] << " " << cnt[1][0] << " " << cnt[1][1] << "\n";
            if (self[curr]) {
                /*if (test29) {
                    cout << self[curr] << "\n";
                }*/
                xxx += 100500;
                if (self[curr] == 1) {
                    vector<vector<ll> > cnt_new(2, vector<ll>(2));
                    for (int x = 0; x < 2; ++x) {
                        for (int res = 0; res < 2; ++res) {
                            cnt_new[x][res ^ (x)] = cnt[x][res];
                        }
                    }
                    cnt = cnt_new;
                } else if (self[curr] == -1) {
                    //cout << "AHA\n";
                    vector<vector<ll> > cnt_new(2, vector<ll>(2));
                    for (int x = 0; x < 2; ++x) {
                        for (int res = 0; res < 2; ++res) {
                            cnt_new[x][res ^ (1 - x)] = cnt[x][res];
                        }
                    }
                    cnt = cnt_new;
                } else {
                    vector<vector<ll> > cnt_new(2, vector<ll>(2));
                    for (int x = 0; x < 2; ++x) {
                        for (int res = 0; res < 2; ++res) {
                            cnt_new[x][res ^ 1] = cnt[x][res];
                        }
                    }
                    cnt = cnt_new;
                }
            }
            used[curr] = true;
            ll val0 = cnt[0][0];
            add(val0, cnt[1][0]);
            dp[0].pb(val0);
            ll val1 = cnt[0][1];
            add(val1, cnt[1][1]);
            dp[1].pb(val1);
        }
    }
    //return 0;

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            ++zzz;
            int beg = i;
            vector<vector<vector<ll> > > cnt(2, vector<vector<ll> >(2, vector<ll>(2))); // beg, last, res
            cnt[0][0][0] = cnt[1][1][0] = 1;
            int curr = i, prev = -1;
            while (true) {
                int id;
                used[curr] = true;
                if (g[curr][0].to != prev) {
                    id = g[curr][0].id;
                } else {
                    id = g[curr][1].id;
                }
                int x = d[id].x, y = d[id].y;
                if (abs(y) == curr) {
                    swap(x, y);
                }
                //cout << i << " " << curr << " " << x << " " << y << "\n";
                vector<vector<vector<ll> > > cnt_new(2, vector<vector<ll> >(2, vector<ll>(2))); // beg, last, res
                for (int beg_val = 0; beg_val < 2; ++beg_val) {
                    for (int y_val = 0; y_val < 2; ++y_val) {
                        if (abs(y) == beg && beg_val != y_val) {
                            continue;
                        }
                        for (int x_val = 0; x_val < 2; ++x_val) {
                            for (int res = 0; res < 2; ++res) {
                                int val = 0;
                                if (x < 0) {
                                    val |= (1 - x_val);
                                } else {
                                    val |= x_val;
                                }
                                if (y < 0) {
                                    val |= (1 - y_val);
                                } else {
                                    val |= y_val;
                                }
                                add(cnt_new[beg_val][y_val][res ^ val], cnt[beg_val][x_val][res]);
                            }
                        }
                    }
                }
                cnt.swap(cnt_new);
                curr = abs(y);
                prev = abs(x);
                if (curr == beg) {
                    break;
                }
            }
            ll val0 = 0, val1 = 0;
            for (int beg_val = 0; beg_val < 2; ++beg_val) {
                add(val0, cnt[beg_val][beg_val][0]);
                add(val1, cnt[beg_val][beg_val][1]);
            }
            //cout << val0 << " " << val1 << "\n";
            dp[0].pb(val0);
            dp[1].pb(val1);
        }
    }

    ll ans[2] = {1, 0};
    for (int i = 0; i < sz(dp[0]); ++i) {
        //cout << dp[0][i] << " " << dp[1][i] << "\n";
        ll x = ans[0];
        mul(x, dp[0][i]);
        ll ans0 = x;
        x = ans[1];
        mul(x, dp[1][i]);
        add(ans0, x);
        x = ans[1];
        mul(x, dp[0][i]);
        ll ans1 = x;
        x = ans[0];
        mul(x, dp[1][i]);
        add(ans1, x);
        ans[0] = ans0, ans[1] = ans1;
    }

    /*if (test29) {
        cout << ttt << " " << xxx << " " << yyy << " " << zzz << "\n";
    }*/

    cout << ans[1] << '\n';

}
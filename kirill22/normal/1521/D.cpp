#include<bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char& s) {
    string res = "'";
    res += s;
    res += "'";
    return res;
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (i) res += ", ";
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double
#define ve vector
#define forn(i, n) for (int i = 0; i < n; i++)

ve<ve<int>> g, dp;
ve<pii> ans;

void dfs(int v, int pr) {
    for (auto x : g[v]) {
        if (x != pr) {
            dfs(x, v);
        }
    }
    dp[v][0] = 0;
    for (auto x : g[v]) {
        if (x != pr) {
            dp[v][0] += max({dp[x][0], dp[x][2], dp[x][4]});
        }
    }
    dp[v][1] = dp[v][0] + 1;
    ve<int> upd;
    for (auto x : g[v]) {
        if (x != pr) {
            dp[v][2] = max(dp[v][2], max(dp[x][1], dp[x][3]) + dp[v][0] - max({dp[x][0], dp[x][2], dp[x][4]}));
            dp[v][3] = max(dp[v][3], 1 + max(dp[x][1], dp[x][3]) + dp[v][0] - max({dp[x][0], dp[x][2], dp[x][4]}));
            upd.pb(max(dp[x][1], dp[x][3]) - max({dp[x][0], dp[x][2], dp[x][4]}));
        }
    }
    sort(rall(upd));
    if (sz(upd) >= 2) {
        dp[v][4] = upd[0] + upd[1] + dp[v][0];
    }
}

void go(int x, int v) ;
void go2(int x, int v) ;

void gfs(int v, int pr, int type) {
    if (type == 0 || type == 1) {
        for (auto x : g[v]) {
            if (x != pr) {
                go(x, v);
            }
        }
        return;
    }
    ve<pii> upd;
    for (auto x : g[v]) {
        if (x != pr) {
            upd.pb({max(dp[x][1], dp[x][3]) - max({dp[x][0], dp[x][2], dp[x][4]}), x});
        }
    }
    sort(rall(upd));
    if (type == 2 || type == 3) {
        int u = upd[0].se;
        ans.pb({v, u});
        go2(u, v);
        for (auto x : g[v]) {
            if (x != pr && x != u) {
                go(x, v);
            }
        }
        return;
    }
    int u = upd[0].se;
    ans.pb({v, u});
    int u2 = upd[1].se;
    ans.pb({v, u2});
    go2(u, v);
    go2(u2, v);
    for (auto x : g[v]) {
        if (x != pr && x != u && x != u2) {
            go(x, v);
        }
    }
    return;
}

void go(int x, int v) {
    int res = max({dp[x][0], dp[x][2], dp[x][4]});
    if (dp[x][0] == res) gfs(x, v, 0);
    else if (dp[x][2] == res) gfs(x, v, 2);
    else gfs(x, v, 4);
}

void go2(int x, int v) {
    if (dp[x][1] > dp[x][3]) gfs(x, v, 1);
    else gfs(x, v, 3);
}

void solve() {
    int n;
    cin >> n;
    ans.clear();
    g.clear();
    g.resize(n);
    dp.clear();
    dp.resize(n, ve<int> (5));
    forn (i, n - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0, -1);
    int res = max({dp[0][0], dp[0][2], dp[0][4]});
    cout << n - 1 - max({dp[0][0], dp[0][2], dp[0][4]}) << '\n';
    go(0, -1);
    //debug(ans);
    set<pii> usd;
    ve<ve<int>> G(n);
    for (auto [x, y] : ans) {
        usd.insert({x, y});
        usd.insert({y, x});
        G[x].pb(y);
        G[y].pb(x);
    }
    ve<int> used(n);
    function<int(int)> dfs = [&] (int v) {
        used[v] = 1;
        for (auto x : G[v]) {
            if (!used[x]) return dfs(x);
        }
        return v;
    };
    vector<pii> kek;
    forn (i, n) {
        if (!used[i] && sz(G[i]) == 0) {
            kek.pb({i, i});
            continue;
        }
        if (!used[i] && sz(G[i]) == 1) {
            kek.pb({i, dfs(i)});
        }
    }
    vector<pii> del;
    forn (i, n) {
        for (auto x : g[i]) {
            if (x > i && usd.find({i, x}) == usd.end()) del.pb({x, i});
        }
    }
    //assert(sz(del) == sz(kek) - 1);
    //debug(del), debug(kek);
    forn (i, sz(del)) {
        cout << del[i].fi + 1 << " " << del[i].se + 1 << " " << kek[i].se + 1 << " " << kek[i + 1].fi + 1 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test = 1;
    if (1) cin >> test;
    forn (WORLD_OF_TANKS, test) {
        solve();
    }
}
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

vector<int> find_kss(vector<vector<int>>& g) {
    int n = g.size();
    vector<vector<int>> g2(n);
    for (int i = 0; i < n; i++) {
        for (auto x : g[i]) {
            g2[x].push_back(i);
        }
    }
    vector<int> ts, comp(n, -1);
    vector<bool> used(n, false);
    function<void(int)> topsort = [&] (int v) {
        used[v] = true;
        for (auto x : g[v]) {
            if (!used[x]) {
                topsort(x);
            }
        }
        ts.push_back(v);
    };
    function<void(int, int)> dfs = [&] (int v, int c) {
        comp[v] = c;
        for (auto x : g2[v]) {
            if (comp[x] == -1) {
                dfs(x, c);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            topsort(i);
        }
    }
    reverse(ts.begin(), ts.end());
    int cnt = 0;
    for (auto x : ts) {
        if (comp[x] == -1) {
            dfs(x, cnt);
            cnt++;
        }
    }
    return comp;
}

void solve() {
    int n, m;
    cin >> n >> m;
    ve<ve<int>> g(n);
    forn (i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
    }
    ve<int> ans(n, 0);
    function<void(int)> dfs = [&] (int v) {
        ans[v] = 1;
        for (auto x : g[v]) {
            if (ans[x] == 0) dfs(x);
        }
    };
    function<void(int)> dfs2 = [&] (int v) {
        ans[v] = -1;
        for (auto x : g[v]) {
            if (ans[x] != -1) dfs2(x);
        }
    };
    dfs(0);
    auto comp = find_kss(g);
    int k = *max_element(all(comp)) + 1;
    ve<ve<int>> G(k);
    forn (i, n) G[comp[i]].pb(i);
    forn (i, k) {
        int f = 0, v = G[i][0];
        if (ans[v] == 0) continue;
        if (sz(G[i]) >= 2) f = 1;
        for (auto x : g[v]) if (x == v) f = 1;
        if (f) {
            dfs2(v);
        }
    }
    ve<int> cnt(k);
    cnt[comp[0]] = 1;
    for (auto& x : ans) if (x == 1) x = 2;
    forn (i, k) {
        int v = G[i][0];
        if (cnt[i] == 1 && ans[v] == 2) {
            ans[v] = 1;
            for (auto x : g[v]) {
                cnt[comp[x]]++;
            }
        }
        else {
            if (ans[v] == 2) {
                for (auto v : G[i]) for (auto x : g[v]) cnt[comp[x]] = 2;
            }
        }
    }
    for (auto x : ans) cout << x << " ";
    cout << '\n';
}

signed main() {
    //
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
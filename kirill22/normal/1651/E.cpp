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

int n;

int solve(pii a, pii b, int v, int u) {
    if (a.fi <= v && v <= a.se) return 0;
    if (a.fi <= u && u <= a.se) return 0;
    if (b.fi <= v && v <= b.se) return 0;
    if (b.fi <= u && u <= b.se) return 0;
    int res = 1, vl, vr;
    vl = 0, vr = a.fi;
    if (v <= a.fi) {
        vl = max(vl, v + 1);
    }
    if (u <= a.fi) {
        vl = max(vl, u + 1);
    }
    res *= (vr - vl + 1);
    vl = a.se, vr = n - 1;
    if (v >= a.se && v < n) {
        vr = min(vr, v - 1);
    }
    if (u >= a.se && u < n) {
        vr = min(vr, u - 1);
    }
    res *= (vr - vl + 1);
    vl = n, vr = b.fi;
    if (v >= n && v < b.fi) {
        vl = max(vl, v + 1);
    }
    if (u >= n && u < b.fi) {
        vl = max(vl, u + 1);
    }
    res *= (vr - vl + 1);
    vl = b.se, vr = 2 * n - 1;
    if (v >= b.se) {
        vr = min(vr, v - 1);
    }
    if (u >= b.se) {
        vr = min(vr, u - 1);
    }
    res *= (vr - vl + 1);
    return res;
}

void solve() {
    cin >> n;
    vector<vector<int>> g(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    vector<int> used(2 * n), ts;
    function<void(int)> dfs = [&] (int v) {
        ts.pb(v);
        used[v] = 1;
        for (auto u : g[v]) {
            if (!used[u]) {
                dfs(u);
            }
        }
    };
    int ans = 0;
    for (int v = 0; v < 2 * n; v++) {
        if (used[v]) {
            continue;
        }
        ts.clear();
        dfs(v);
        pii res = {1e9, -1e9}, res2 = {1e9, -1e9};
        for (auto x : ts) {
            if (x < n) {
                res.fi = min(res.fi, x);
                res.se = max(res.se, x);
            } else {
                res2.fi = min(res2.fi, x);
                res2.se = max(res2.se, x);
            }
        }
        ans += (int) ts.size() / 2 * (res.fi + 1) * (n - res.se) * (res2.fi - n + 1) * (2 * n - res2.se);
        int m = sz(ts);
        for (int l = 0; l < m; l++) {
            pii res = {1e9, -1e9}, res2 = {1e9, -1e9};
            int z = 0;
            for (int r = (l + 2) % m; r != l; r = (r + 1) % m) {
                int x = ts[(r + m - 1) % m];
                z++;
                if (x < n) {
                    res.fi = min(res.fi, x);
                    res.se = max(res.se, x);
                } else {
                    res2.fi = min(res2.fi, x);
                    res2.se = max(res2.se, x);
                }
                if (r == (l + 2) % m) continue;
                int cnt = z / 2;
                ans += solve(res, res2, ts[l], ts[r]) * cnt;
            }
        }
        for (int l = 0; l < m; l++) {
            pii res = {1e9, -1e9}, res2 = {1e9, -1e9};
            for (int r = 0; r < m; r++) {
                if (r == l) continue;
                int x = ts[r];
                if (x < n) {
                    res.fi = min(res.fi, x);
                    res.se = max(res.se, x);
                } else {
                    res2.fi = min(res2.fi, x);
                    res2.se = max(res2.se, x);
                }
            }
            ans += (m / 2 - 1) * solve(res, res2, ts[l], ts[l]);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
    while (q--) {
        solve();
    }
}
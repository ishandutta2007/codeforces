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

class dsu {
 public:
    vector<int> p;
    vector<vector<int>> vertex;
    int n;
    dsu(int n) : n(n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        vertex.resize(n);
        for (int i = 0; i < n; i++) {
            vertex[i].push_back(i);
        }
    }
    void clear() {
        iota(p.begin(), p.end(), 0);
        for (int i = 0; i < n; i++) {
            vertex[i].clear();
            vertex[i].push_back(i);
        }
    }
    int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        if (vertex[x].size() < vertex[y].size()) swap(x, y);
        p[y] = x;
        while (vertex[y].size() > 0) {
            vertex[x].push_back(vertex[y].back());
            vertex[y].pop_back();
        }
        return true;
    }
};

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
    int n, q, s, d;
    cin >> n >> q >> s >> d;
    s--;
    ve<int> a(n);
    forn (i, n) cin >> a[i];
    ve<int> dp(n);
    //
    dsu G(n);
    ve<ve<int>> g(n);
    set<pii> b;
    for (int i = 0; i < n; i++) b.insert({a[i], i});
    while ((int) G.vertex[G.get(0)].size() != n) {
        ve<ve<int>> upd(n, {(int) 1e18, -1, -1});
        for (int i = 0; i < n; i++) {
            if (G.get(i) == i) {
                for (auto x : G.vertex[i]) {
                    b.erase({a[x], x});
                }
                for (auto x : G.vertex[i]) {
                    int y = a[x];   
                    auto update = [&] (pii z) {
                        int dist = abs(y - z.fi);
                        int res = abs(d - dist);
                        upd[i] = min(upd[i], {res, z.se, x});
                    };
                    auto it = b.lower_bound({y - d, -1});
                    if (it != b.end()) update(*it);
                    if (it != b.begin()) {
                        it--;
                        update(*it);
                    }
                    it = b.lower_bound({y + d, -1});
                    if (it != b.end()) update(*it);
                    if (it != b.begin()) {
                        it--;
                        update(*it);
                    }
                }
                for (auto x : G.vertex[i]) {
                    b.insert({a[x], x});
                }
            }
        }
        //debug(upd);
        forn (i, n) {
            if (upd[i][2] != -1) {
                if (G.unite(upd[i][1], upd[i][2])) {
                    g[upd[i][2]].pb(upd[i][1]);
                    g[upd[i][1]].pb(upd[i][2]);
                }
            }
        }
    }
    function<void(int, int, int)> dfs;
    dfs = [&] (int v, int tmp, int pr) {
        dp[v] = tmp;
        for (auto x : g[v]) {
            if (x == pr) continue;
            int dist = abs(a[x] - a[v]);
            int res = abs(d - dist);
            dfs(x, max(tmp, res), v);
        } 
    };
    dfs(s, 0, -1);
    //debug(dp, g);
    while (q--) {
        int i, x;
        cin >> i >> x;
        i--;
        if (dp[i] <= x) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
}
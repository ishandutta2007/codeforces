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

const int N = 3e5, K = 20;
vector<int> g[N];
int h[N], dist[N], par[N], dp[N], jump[N][K], go[N][K];
vector<int> ts;

int dfs(int v, int pr, int A) {
    for (int j = 1; j < K; j++) {
        jump[v][j] = jump[jump[v][j - 1]][j - 1];
    }
    dp[v] = 0;
    int ok = (v == A);
    for (auto x : g[v]) {
        if (x != pr) {
            jump[x][0] = v;
            int res = dfs(x, v, A);
            if (res) {
                ok = 1;
            } else {
                dp[v] = max(dp[v], dp[x] + 1); 
            }
        }
    }
    if (ok) {
        ts.pb(v);
    }
    return ok;
}

pii get(int v, int pr) {
    pii res = {0, v};
    for (auto x : g[v]) {
        if (x != pr) {
            par[x] = v;
            h[x] = h[v] + 1;
            auto res2 = get(x, v);
            res = max(res, {res2.fi + 1, res2.se});
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    ts.clear();
    forn (i, n) g[i].clear(), par[i] = 0;
    forn (i, n - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    auto A = get(0, -1);
    vector<int> ans(n + 1);
    int d = A.fi;
    dfs(0, -1, A.se);
    reverse(all(ts));
    for (int i = d; i <= n; i++) {
        ans[i] = d;
    }
    forn (i, K) go[0][i] = -1e9;
    for (int i = 1; i < sz(ts); i++) {
        int v = ts[i];
        go[v][0] = dp[ts[i - 1]] - h[ts[i - 1]];
        for (int j = 1; j < K; j++) {
            go[v][j] = max(go[v][j - 1], go[jump[v][j - 1]][j - 1]);
        }
    }
    vector<int> mx(sz(ts) + 1);
    forn (i, sz(ts)) {
        mx[i + 1] = max(mx[i], dp[ts[i]] + h[ts[i]]);
    }
    int j = d;
    while (j) {
        int l = 0, r = j;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            int ok = 1;
            int v = A.se;
            int g = ans[j] - 1 - m;
            forn (i, K) if (g >> i & 1) v = jump[v][i];
            int tmp = v;
            for (int i = K - 1; i >= 0; i--) {
                if (m + go[tmp][i] + h[v] < ans[j]) {
                    tmp = jump[tmp][i];
                }
            }
            g = h[tmp];
            if (mx[g] >= ans[j]) ok = 0;
            if (ok) {
                l = m;
            } else {
                r = m;
            }
        }
        for (int i = j - 1; i >= r; i--) {
            ans[i] = ans[j];
        }
        ans[l] = ans[j] - 1;
        j = l;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
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

const int N = 4e5;
set<int> g[N];
set<int> g2[N];
set<pii> st, st2;
ve<int> ts;
int used[N], A[N], B[N];

void add(int v) {
    if (sz(g[v]) && A[v]) st.insert({sz(g[v]), v});
    if (sz(g2[v]) && B[v]) st2.insert({sz(g2[v]), v});
}

void del(int v) {
    if (sz(g[v])) st.erase({sz(g[v]), v});
    if (sz(g2[v])) st2.erase({sz(g2[v]), v});
}

void dfs(int v) {
    used[v] = 1;
    for (auto x : g[v]) {
        if (!used[x]) dfs(x);
    }
    ts.pb(v);
}

void solve() {
    int n, m;
    cin >> n >> m;
    fill(A, A + n, 1);
    fill(B, B + n, 1);
    forn (i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].insert(y);
        g2[y].insert(x);
    }
    forn (i, n) add(i);
    while (1) {
        //debug(st, st2);
        int upd = 0;
        if (sz(st) && st.begin()->fi == 1) {
            upd = 1;
            auto v = st.begin()->se;
            int u = *g[v].begin();
            del(v), del(u);
            g[v].erase(u);
            g2[u].erase(v);
            B[u] = 0;
            add(v), add(u);
        }
        if (sz(st2) && st2.begin()->fi == 1) {
            upd = 1;
            auto v = st2.begin()->se;
            int u = *g2[v].begin();
            del(v), del(u);
            g[u].erase(v);
            g2[v].erase(u);
            A[u] = 0;
            add(v), add(u);
        }
        if (!upd) break;
    }
    forn (i, n) if (!used[i]) dfs(i);
    vector<int> dp(n, 1);
    for (auto x : ts) {
        for (auto y : g[x]) {
            dp[x] = max(dp[x], dp[y] + 1);
        }
    }
    cout << *max_element(all(dp)) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    if (0) cin >> t;
    while (t--) solve();
}
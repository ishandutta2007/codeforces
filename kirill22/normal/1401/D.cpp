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
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

vector<vector<int>> g;
vector<int> c, b;

void dfs(int v, int p, int n) {
    c[v] = 1;
    for (auto x : g[v]) {
        if (x != p) {
            dfs(x, v, n);
            c[v] += c[x];
            b.pb((n - c[x]) * c[x]);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    b.clear();
    g.clear();
    g.resize(n);
    c.clear();
    c.resize(n, 0);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0, -1, n);
    sort(rall(b));
    int m;
    cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    sort(rall(a));
    const int mod = 1e9 + 7;
    int ans = 0;
    if (m <= n - 1) {
        while (a.size() < n - 1) a.pb(1);
        for (int i = 0; i < n - 1; i++) {
            b[i] %= mod;
            ans = (ans + a[i] * b[i]) % mod;
        }
    }
    else {
        int k = m - (n - 2);
        for (int i = 1; i < n - 1; i++) {
            b[i] %= mod;
            ans = (ans + a[i - 1 + k] * b[i]) % mod;
        }
        int v = 1;
        for (int i = 0; i < k; i++) v = (v * a[i]) % mod;
        v = (v * b[0]) % mod;
        ans = (ans + v) % mod;
    }
    cout << ans << '\n';
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
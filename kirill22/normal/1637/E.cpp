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
//#define int long long
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

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> cnt;
    vector<int> b;
    forn (i, n) {
        int x;
        cin >> x;
        cnt[x]++;
        b.pb(x);
    }
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());
    unordered_map<int, int> ind;
    unordered_set<int> ban[sz(b)];
    forn (i, sz(b)) ind[b[i]] = i;
    forn (i, m) {
        int x, y;
        cin >> x >> y;
        ban[ind[x]].insert(ind[y]);
        ban[ind[y]].insert(ind[x]);
    }
    vector<pii> g[n + 1];
    vector<int> z;
    for (auto [x, y] : cnt) {
        g[y].pb({x, ind[x]});
        z.pb(y);
    }
    sort(all(z));
    z.resize(unique(all(z)) - z.begin());
    forn (i, n + 1) {
        if (sz(g[i])) {
            sort(rall(g[i]));
        }
    }
    long long ans = 0;
    for (int v = 2; v <= n; v++) {
        for (auto x : z) {
            if (x >= v || sz(g[v - x]) == 0) continue;
            int y = v - x, mx = 0;
            for (auto [a, b] : g[x]) {
                for (auto [a2, b2] : g[y]) {
                    if (ban[b].find(b2) != ban[b].end() || a == a2) continue;
                    if (a + a2 < mx) break;
                    ans = max(ans, (long long) v * 1ll * (a + a2));
                    mx = max(mx, a + a2);
                    break;
                }
            }
        }
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
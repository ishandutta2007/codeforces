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


#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define ld long double
#define forn(i, n) for (int i = 0; i < n; i++)

class dsu {
public:
    vector<int> p;
    int n;
    dsu(int n) : n(n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    void clear() {
        iota(p.begin(), p.end(), 0);
    }
    int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), g2(n);
    vector<int> a(m), b(m), used(m);
    dsu G(n);
    forn (i, m) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        g2[a[i]].push_back(i);
        g2[b[i]].push_back(i);
    }
    vector<int> usd(n);
    vector<int> ans(m, -1);
    function<void(int, int)> bfs = [&] (int v, int h = 0) {
        usd[v] = 1;
        for (auto i : g2[v]) {
            int z = a[i] ^ b[i] ^ v;
            if (!usd[z]) {
                used[i] = 1;
                ans[i] = h;
                g[a[i]].push_back(i);
                g[b[i]].push_back(i);
                bfs(z, (h ^ 1));
            }
        }
    };
    bfs(0, 0);
    vector<int> d;
    forn (i, m) if (ans[i] == -1) {
        d.push_back(i);
    }
    vector<int> res(m);
    int all = 2 * n + 1;
    forn (msk, (1 << sz(d))) {
        forn (i, sz(d)) {
            ans[d[i]] = (msk >> i & 1);
        }
        int cnt = 2 * n;
        forn (t, 2) {
            G.clear();
            forn (i, m) if (ans[i] == t) {
                if (G.unite(a[i], b[i])) cnt--;
            }
        }
        if (cnt < all) {
            all = cnt;
            res = ans;
        }
    }
    forn (i, m) cout << res[i];
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
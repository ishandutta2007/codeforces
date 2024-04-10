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
    vector<int> p, rang;
    int n;
    dsu(int n) : n(n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rang.resize(n, 1);
    }
    void clear() {
        iota(p.begin(), p.end(), 0);
        fill(rang.begin(), rang.end(), 1);
    }
    int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    int unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (rang[x] < rang[y]) swap(x, y);
        if (x != y) {
            p[y] = x;
            rang[x] += (rang[x] == rang[y]);
            return x;
        }
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x;
    cin >> n >> m >> x;
    set<pii> st;
    ve<int> a(n);
    forn (i, n) {
        cin >> a[i];
        st.insert({a[i], i});
    }
    ve<pii> R;
    ve<set<int>> d(n);
    forn (i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        d[x].insert(i);
        d[y].insert(i);
        R.pb({x, y});
    }
    vector<int> ans;
    int cnt = n - 1;
    while (cnt) {
        auto el = *st.rbegin();
        if (el.fi < x) break;
        int v = el.se;
        if (sz(d[v]) == 0) {
            cout << "NO";
            return 0;
        }
        auto ind = *d[v].begin();
        ans.pb(ind);
        int u = R[ind].fi ^ R[ind].se ^ v;
        st.erase({a[v], v});
        st.erase({a[u], u});
        if (sz(d[v]) < sz(d[u])) swap(v, u);
        a[v] = a[v] + a[u] - x;
        a[u] = -1;
        st.insert({a[v], v});
        for (auto e : d[u]) {
            if (R[e] == make_pair(v, u) || R[e] == make_pair(u, v)) {
                d[v].erase(e);
                continue;
            }
            d[v].insert(e);
            if (R[e].fi == u) R[e].fi = v;
            else R[e].se = v;
        }
        cnt--;
    }
    dsu g(n);
    forn (i, m) {
        int v = R[i].fi, u = R[i].se;
        if (a[v] == -1 || a[u] == -1) continue;
        v = g.get(v), u = g.get(u);
        if (v == u || a[v] + a[u] < x) continue;
        int p = g.unite(v, u);
        a[p] = a[v] + a[u] - x;
        ans.pb(i);
        cnt--;
    }
    if (cnt) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (auto x : ans) cout << x + 1 << " ";
}
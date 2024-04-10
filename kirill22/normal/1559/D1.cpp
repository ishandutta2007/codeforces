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
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (rang[x] < rang[y]) swap(x, y);
        if (x != y) {
            p[y] = x;
            rang[x] += (rang[x] == rang[y]);
            return true;
        }
        return false;
    }
};

void solve() {
    int n, m, m2;
    cin >> n >> m >> m2;
    dsu a(n), b(n);
    forn (i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        a.unite(x, y);
    }
    forn (i, m2) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        b.unite(x, y);
    }
    ve<pii> ans;
    forn (x, n) forn (y, n) {
        if (a.get(x) != a.get(y) && b.get(x) != b.get(y)) {
            a.unite(x, y);
            b.unite(x, y);
            ans.pb({x, y});
        }
    }
    cout << sz(ans) << '\n';
    for (auto [x, y] : ans) cout << x + 1 << " " << y + 1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
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

ve<ve<int>> g;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    g.resize(n);
    ve<pii> R;
    forn (i, n - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        R.pb({min(x, y), max(x, y)});
        g[x].pb(y);
        g[y].pb(x);
    }
    set<int> b;
    forn (i, n) b.insert(i);
    cout << "? " << sz(b) << " ";
    for (auto x : b) cout << x + 1 << " ";
    cout << endl;
    int mx;
    cin >> mx;
    set<pii> ban;
    int cnt = n - 1;
    while (cnt > 1) {
        int x = cnt / 2;
        b.clear();
        set<pii> st;
        ve<int> cnt2(n);
        for (auto el : R) {
            if (ban.find(el) == ban.end()) {
                cnt2[el.fi]++;
                cnt2[el.se]++;
            }
        }
        auto gfs = [&] (int v) {
            b.insert(v);
            ve<int> D = {v};
            forn (i, sz(D)) {
                v = D[i];
                if (x == 0) break;
                for (auto u : g[v]) {
                    if (b.find(u) == b.end() && ban.find({min(v, u), max(v, u)}) == ban.end() && x) {
                        x--;
                        st.insert({min(v, u), max(v, u)});
                        b.insert(u);
                        D.pb(u);
                    }
                }
            }
        };
        forn (i, n) {
            if (cnt2[i] == 1 && x > 0 && b.find(i) == b.end()) {
                gfs(i);
            }
        }
        cout << "? " << sz(b) << " ";
        for (auto x : b) cout << x + 1 << " ";
        cout << endl;
        int res; cin >> res;
        x = cnt / 2;
        if (res == mx) {
            cnt = x;
            for (auto el : R) {
                if (st.find(el) == st.end()) ban.insert(el);
            }
        } else {
            cnt -= x;
            for (auto el : st) ban.insert(el);
        }
    }
    cout << "! ";
    for (auto [x, y] : R) {
        if (ban.find({x, y}) == ban.end()) {
            cout << x + 1 << " " << y + 1 << endl;
        }
    }
}
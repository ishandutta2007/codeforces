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
#define eb emplace_back
#define ld long double

vector<vector<pii>> g;

vector<int> get(int v) {
    int n = g.size();
    vector<int> dist(n, 1e18);
    dist[v] = 0;
    set<pii> st;
    for (int i = 0; i < n; i++) st.insert({dist[i], i});
    while (st.size() > 0) {
        auto el = *st.begin();
        st.erase(el);
        int x = el.se;
        for (auto p : g[x]) {
            int y = p.fi, d = p.se;
            if (dist[y] > dist[x] + d) {
                st.erase({dist[y], y});
                dist[y] = dist[x] + d;
                st.insert({dist[y], y});
            }
        }
    }
    return dist;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    g.resize(n);
    vector<pii> upd;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        upd.pb({x, y});
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
    vector<int> l(k), r(k);
    for (int i = 0; i < k; i++) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
    }
    vector<vector<int>> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = get(i);
    }
    int ans = 1e18;
    for (auto el : upd) {
        int x = el.fi, y = el.se;
        int res = 0;
        for (int i = 0; i < k; i++) {
            int z = d[l[i]][r[i]];
            z = min(z, d[l[i]][x] + d[y][r[i]]);
            z = min(z, d[l[i]][y] + d[x][r[i]]);
            res += z;
        }
        ans = min(ans, res);
    }
    cout << ans;
}
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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a[n];
    set<pii> g[n];
    vector<int> dp(n, 0), sz(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x].pb(y);
        a[y].pb(x);
        sz[x]++;
        sz[y]++;
    }
    set<pii> st;
    for (int i = 0; i < n; i++) {
        for (auto x : a[i]) {
            if (sz[x] == 1) dp[i]++;
            g[i].insert({sz[x], x});
        }
        st.insert({dp[i], i});
    }
    vector<int> lst = sz;
    int ans = 0;
    while (st.size() > 0) {
        auto el = *st.rbegin();
        int x = el.se;
        if (dp[x] < k) {
            break;
        }
        ans++;
        //debug(x);
        st.erase(el);
        for (int i = 0; i < k; i++) {
            auto el = *g[x].begin();
            int v = el.se;
            //debug(v);
            st.erase({dp[v], v});
            sz[x]--;
            dp[x]--;
            g[x].erase(el);
        }
        st.insert({dp[x], x});
        if (sz[x] == 1) {
            auto v = (*g[x].begin()).se;
            st.erase({dp[v], v});
            dp[v]++;
            st.insert({dp[v], v});
            g[v].erase({lst[x], x});
            g[v].insert({1, x});
        }
    }
    cout << ans << endl;
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
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

void solve() {
    int n, m;
    cin >> n >> m;
    ve<ve<int>> g(2 * n);
    forn (i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y + n);
        g[y + n].pb(x);
    }
    ve<int> used(2 * n);
    function<void(int, int)> dfs = [&] (int v, int flag) {
        used[v] = 1;
        vector<int> go = {};
        if (flag) {
            if (v >= n) go = {v - n};
            else go = {v + n};
        } else {
            go = g[v];
        }
        for (auto x : go) if (!used[x]) dfs(x, 1 - flag);
    };
    for (int start : {(int) 0, (int) n}) {
        fill(all(used), 0);
        dfs(start, 0);
        int sum = accumulate(all(used), 0ll);
        if (sum != 2 * n) {
            cout << "Yes\n";
            int cnt = 0;
            forn (i, n) cnt += used[i];
            if (start == 0) {
                cout << cnt << " " << n - cnt << '\n';
                forn (i, n) if (used[i]) cout << i + 1 << " ";
                cout << '\n';
                forn (i, n) if (!used[i + n]) cout << i + 1 << " ";
                cout << '\n';
            } else {
                cout << n - cnt << " " << cnt << '\n';
                forn (i, n) if (!used[i]) cout << i + 1 << " ";
                cout << '\n';
                forn (i, n) if (used[i + n]) cout << i + 1 << " ";
                cout << '\n';
            }
            return;
        }
    }
    cout << "No\n";
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
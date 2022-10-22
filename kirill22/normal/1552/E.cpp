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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    ve<int> a(n * k);
    ve<ve<int>> g(n);
    forn (i, n * k) {
        int x;
        cin >> x;
        x--;
        g[x].pb(i);
    }
    ve<int> used(n);
    ve<pii> ans(n);
    forn (v, n) {
        pii res = {1e9, 1e9};
        forn (i, n) {
            if (used[i]) continue;
            forn (j, sz(g[i]) - 1) {
                int l = g[i][j], r = g[i][j + 1], mx = 0;
                for (int i = l; i <= r; i++) mx = max(mx, a[i]);
                if (mx >= (n + k - 2) / (k - 1)) continue;
                res = min(res, {r, i});
            }
        }
        int i = res.se;
        used[i] = 1;
        forn (j, sz(g[i]) - 1) {
            int l = g[i][j], r = g[i][j + 1], mx = 0;
            for (int i = l; i <= r; i++) mx = max(mx, a[i]);
            if (mx >= (n + k - 2) / (k - 1)) continue;
            for (int i = l; i <= r; i++) a[i]++;
            ans[i] = {l, r};
            break;
        }
    }
    forn (i, n) cout << ans[i].fi + 1 << " " << ans[i].se + 1 << '\n';
}
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
    int n;
    cin >> n;
    int m = (1 << n);
    int r = n * (m / 2);
    ve<ve<int>> g(m);
    ve<int> ans(m);
    forn (i, r) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    function<void(ve<int>)> solve = [&] (ve<int> A) {
        //debug(A);
        if (sz(A) == 1) {
            ans[A[0]] = 0;
            return;
        }
        ve<int> usd(m, 0);
        for (auto x : A) usd[x] = 1;
        int l, r;
        for (auto x : A) {
            for (auto y : g[x]) if (usd[x] && usd[y]) l = x, r = y;
        }
        ve<int> L;
        ve<pii> st;
        st.pb({l, 1});
        st.pb({r, 2});
        ve<int> used(m);
        used[l] = 1;
        used[r] = 2;
        forn (i, sz(st)) {
            int v = st[i].fi, t = st[i].se;
            if (t == 1) L.pb(v);
            for (auto x : g[v]) {
                if (!usd[x] || used[x]) continue;
                used[x] = t;
                st.pb({x, t});
            }
        }
        solve(L);
        //debug(L);
        for (auto x : L) {
            for (auto y : g[x]) {
                if (usd[y] && used[y] == 2) {
                    ans[y] = ans[x] + sz(A) / 2;
                }
            }
        }
       // debug(ans);
    };
    ve<int> tmp(m); iota(all(tmp), 0);
    solve(tmp);
    //debug(ans);
    ve<int> answer(m);
    forn (i, m) answer[ans[i]] = i;
    for (auto x : answer) cout << x << " ";
    cout << '\n';
    if (m % n != 0) {
        cout << -1 << '\n';
    }
    else {
        forn (i, m) {
            int res = 0;
            forn (j, n) {
                if ((ans[i] & (1 << j)) > 0) res ^= j;
            }
            cout << res << " ";
        } cout << '\n';
    }
}

signed main() {
    //
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
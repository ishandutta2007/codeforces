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

const int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    ve<ve<int>> g(k);
    ve<ve<int>> a(n);
    ve<ve<int>> G(n);
    forn (i, n) {
        int m;
        cin >> m;
        forn (j, m) {
            int x;
            cin >> x;
            x--;
            a[i].pb(x);
            g[x].pb(i);
        }
    }
    int usd = 0;
    forn (i, k) {
        if (sz(g[i]) == 0) usd++;
        else {
            for (auto x : g[i]) {
                if (x != g[i][0]) {
                    G[x].pb(g[i][0]);
                    G[g[i][0]].pb(x);
                }
            }
        }
    }
    ve<int> p(n, -1), ts;
    function<void(int)> dfs = [&] (int v) {
          ts.pb(v);
          for (auto x : G[v]) {
              if (p[x] == -1) {
                  p[x] = v;
                  dfs(x);
              }
          }
    };
    ve<int> AB(5 * k, 0), pos(k, -1);
    map<int, int> d;
    forn (i, n) {
        if (p[i] != -1) continue;
        ts.clear();
        p[i] = n;
        dfs(i);
        ve<int> C;
        for (auto v : ts) {
            for (auto x : a[v]) C.pb(x);
        }
        sort(all(C));
        C.resize(unique(all(C)) - C.begin());
        int ok = 1;
        for (auto v : ts) {
            auto A = a[v];
            sort(all(A));
            forn (i, sz(A) - 1) if (A[i] == A[i + 1]) ok = 0;
        }
        if (!ok) continue;
        int st = 2 * k;
        for (auto x : a[ts[0]]) {
            AB[st] = x;
            pos[x] = st;
            st++;
        }
        for (auto v : ts) {
            if (v == ts[0]) continue;
            int fi = 0;
            forn (j, sz(a[v])) {
                if (pos[a[v][j]] != -1) {
                    fi = pos[a[v][j]] - j;
                    break;
                }
            }
            forn (j, sz(a[v])) {
                if (fi + j < 0 || fi + j >= sz(AB)) {
                    ok = 0;
                    break;
                }
                if (pos[AB[fi + j]] == fi + j) {
                    if (AB[fi + j] != a[v][j]) ok = 0;
                } else {
                    if (pos[a[v][j]] == -1) {
                        AB[fi + j] = a[v][j];
                        pos[a[v][j]] = fi + j;
                    } else {
                        ok = 0;
                    }  
                }
            }
            if (!ok) break;
        }
        if (!ok) {
            for (auto x : C) pos[x] = -1; 
            continue;
        }
        int mn = 1e18, mx = -1e18;
        for (auto x : C) {
            mn = min(mn, pos[x]);
            mx = max(mx, pos[x]);
        }
        d[mx - mn + 1]++;
        for (auto x : C) pos[x] = -1; 
    }
    //debug(d, usd);
    ve<int> dp(m + 1);
    dp[0] = 1;
    forn (i, m) {
        dp[i + 1] = (dp[i] * usd) % mod;
        for (auto [x, y] : d) {
            if (x <= i + 1) {
                dp[i + 1] = (dp[i + 1] + dp[i + 1 - x] * y) % mod;
            }
        }
    }
    //debug(dp);
    cout << dp[m];
}
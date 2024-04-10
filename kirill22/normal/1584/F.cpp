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
//#define int long long
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

const int N = 100;
string s[N];

void dfs(int v, vector<vector<int>>& g, vector<int>& used, vector<int>& dp) {
    used[v] = 1;
    dp[v] = 1;
    for (auto x : g[v]) {
        if (!used[x]) dfs(x, g, used, dp);
        dp[v] = max(dp[v], dp[x] + 1);
    }
}

long long get(vector<int>& tmp) {
    long long res = 0;
    forn (i, sz(tmp)) {
        res *= (long long) sz(s[i]);
        res += tmp[i];
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a;
    unordered_map<long long, int> id;
    vector<char> b;
    forn (i, n) cin >> s[i];
    for (int c = 'a'; c <= 'z'; c++) {
        ve<pii> pos(n, {-1, -1});
        forn (i, n) {
            forn (j, sz(s[i])) {
                if (s[i][j] == c) {
                    if (pos[i].fi == -1) pos[i].fi = j;
                    else pos[i].se = j;
                }
            }
        }
        forn (msk, (1 << n)) {
            vector<int> tmp(n);
            int ok = 1;
            forn (i, n) {
                if (msk >> i & 1) {
                    tmp[i] = pos[i].se;
                } else {
                    tmp[i] = pos[i].fi;
                }
                if (tmp[i] == -1) ok = 0;
            }
            if (!ok) continue;
            a.pb(tmp);
            b.pb(c);
        }
    }
    for (int c = 'A'; c <= 'Z'; c++) {
        ve<pii> pos(n, {-1, -1});
        forn (i, n) {
            forn (j, sz(s[i])) {
                if (s[i][j] == c ) {
                    if (pos[i].fi == -1) pos[i].fi = j;
                    else pos[i].se = j;
                }
            }
        }
        forn (msk, (1 << n)) {
            vector<int> tmp(n);
            int ok = 1;
            forn (i, n) {
                if (msk >> i & 1) {
                    tmp[i] = pos[i].se;
                } else {
                    tmp[i] = pos[i].fi;
                }
                if (tmp[i] == -1) ok = 0;
            }
            if (!ok) continue;
            a.pb(tmp);
            b.pb(c);
        }
    }
    int p = sz(a);
    if (p == 0) {
        cout << 0 << '\n' << '\n';
        return;
    }
    forn (i, p) id[get(a[i])] = i;
    ve<ve<int>> g(p);
    vector<int> pos2[n][100];
    forn (i, n) {
        forn (j, sz(s[i])) {
            if (s[i][j] >= 'a' && s[i][j] <= 'z') pos2[i][s[i][j] - 'a'].pb(j);
            else pos2[i][s[i][j] - 'A' + 50].pb(j);
        }
    }
    forn (t, p) {
        for (char c = 'a'; c <= 'z'; c++) {
            ve<int> pos(n, -1);
            forn (i, n) {
                for (auto j : pos2[i][(c - 'a')]) {
                    if (j > a[t][i]) {
                        pos[i] = j;
                        break;
                    }
                }
            }
            if (*min_element(all(pos)) == -1) continue;
            g[t].pb(id[get(pos)]);
        }
        for (char c = 'A'; c <= 'Z'; c++) {
            ve<int> pos(n, -1);
            forn (i, n) {
                for (auto j : pos2[i][c - 'A' + 50]) {
                    if (j > a[t][i]) {
                        pos[i] = j;
                        break;
                    }
                }
            }
            if (*min_element(all(pos)) == -1) continue;
            g[t].pb(id[get(pos)]);
        }
    }
    //debug(a, g);
    vector<int> used(p), dp(p);
    forn (i, p) {
        if (!used[i]) {
            dfs(i, g, used, dp);
        }
    }
    int x = max_element(all(dp)) - dp.begin();
    string ans = "";
    while (1) {
        ans.pb(b[x]);
        if (dp[x] == 1) break;
        for (auto y : g[x]) {
            if (dp[y] == dp[x] - 1) {
                x = y;
                break;
            }
        }
    }
    cout << sz(ans) << '\n' << ans << '\n';
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
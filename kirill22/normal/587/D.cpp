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

ve<int> vx, vy, c, t;
ve<ve<int>> g, g2;
ve<int> usd, ts, ts2;

void get_path(int v) {
    ts.pb(v);
    usd[v] = 1;
    for (auto id : g2[v]) {
        int x = v ^ vx[id] ^ vy[id];
        if (!usd[x]) {
            ts2.pb(id);
            get_path(x);
        }
    }
}

mt19937 gen(time(0));

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    g2.resize(n);
    usd.resize(n);
    vx.resize(m);
    vy.resize(m);
    c.resize(m);
    t.resize(m);
    map<int, ve<int>> comp;
    forn (i, m) {
        cin >> vx[i] >> vy[i] >> c[i] >> t[i];
        vx[i]--, vy[i]--;
        g[vx[i]].pb(i);
        g[vy[i]].pb(i);
        comp[c[i]].pb(vx[i]);
        comp[c[i]].pb(vy[i]);
    }
    forn (i, n) {
        sort(all(g[i]), [&] (int x, int y) { return c[x] < c[y]; });
        map<int, int> dp;
        for (auto id : g[i]) dp[c[id]]++;
        for (auto [x, y] : dp) {
            if (y >= 3) {
                cout << "No";
                return 0;
            }
        }
    }
    int result = 0;
    set<int> ans;
    ve<int> uk(n);
    ve<int> used(n);
    ve<pair<ve<int>, ve<int>>> dp;
    for (auto [color, mas] : comp) {
        sort(all(mas));
        mas.resize(unique(all(mas)) - mas.begin());
        for (auto v : mas) {
            g2[v].clear();
            usd[v] = 0;
            while (uk[v] < sz(g[v]) && c[g[v][uk[v]]] == color) {
                g2[v].pb(g[v][uk[v]++]);
            }
        }
        for (auto v : mas) {
            if (!usd[v] && sz(g2[v]) == 1) {
                ts.clear();
                ts2.clear();
                get_path(v);
                if (sz(ts) == 2) continue;
                dp.pb({ts, ts2});
            }
        }
        for (auto v : mas) {
            if (!usd[v]) {
                ts.clear();
                ts2.clear();
                get_path(v);
                for (auto id : g2[ts.back()]) {
                    if (ts.back() ^ vx[id] ^ vy[id] == ts[0] && ts2[0] != id) {
                        ts2.pb(id);
                    }
                }
                if (sz(ts) % 2 == 1) {
                    cout << "No";
                    return 0;
                }
                for (auto x : ts) {
                    if (used[x]) {
                        cout << "No";
                        return 0;
                    }
                    used[x] = 1;
                }
                int res = 0, res2 = 0;
                forn (i, sz(ts2)) {
                    if (i % 2 == 0) res = max(res, t[ts2[i]]);
                    else res2 = max(res2, t[ts2[i]]);
                }
                //debug(res, res2, ts2);
                if (res < res2) {
                    result = max(result, res);
                    for (int i = 0; i < sz(ts2); i += 2) ans.insert(ts2[i]);
                }
                else {
                    result = max(result, res2);
                    for (int i = 1; i < sz(ts2); i += 2) ans.insert(ts2[i]);
                }
            }
        }
    }
    for (auto [a, b] : dp) {
        for (int i = 1; i + 1 < sz(a); i++) {
            if (used[a[i]]) {
                cout << "No";
                return 0;
            }
            used[a[i]] = 1;
        }
    }
    for (auto [a, b] : dp) {
        for (int i = 1; i + 1 < sz(a); i++) {
            used[a[i]] = 0;
        }
    }
    int RESULT;
    set<int> ANS;
    int l = -1, r = 1e9 + 5;
    int was = 0;
    while (l + 1 < r) {
        //debug(l, r);
        int mid = (l + r) / 2;
        int m = sz(dp);
        ve<int> usd(m);
        int is_ok = 1;
        set<int> ANSWER = ans;
        ve<int> USED = used;
        forn (j, m) {
            int res = 0, res2 = 0;
            forn (i, sz(dp[j].se)) {
                if (i % 2 == 0) res = max(res, t[dp[j].se[i]]);
                else res2 = max(res2, t[dp[j].se[i]]);
            }
            //debug(res, res2);
            if (res > mid && res2 > mid) {
                is_ok = 0;
                break;
            }
            if (res > mid) {
                for (int v = 1; v < sz(dp[j].se); v += 2) {
                    int id = dp[j].se[v];
                    if (USED[vx[id]] || USED[vy[id]]) {
                        is_ok = 0;
                        break;
                    }
                    ANSWER.insert(id);
                    USED[vx[id]] = USED[vy[id]] = 1;
                }
                usd[j] = 1;
            }
            else if (res2 > mid) {
                for (int v = 0; v < sz(dp[j].se); v += 2) {
                    int id = dp[j].se[v];
                    if (USED[vx[id]] || USED[vy[id]]) {
                        is_ok = 0;
                        break;
                    }
                    ANSWER.insert(id);
                    USED[vx[id]] = USED[vy[id]] = 1;
                }
                usd[j] = 1;
            }
        }
        if (!is_ok) {
            l = mid;
            continue;
        }
        forn (j, m) {
            if (usd[j]) continue;
            if (sz(dp[j].fi) % 2 != 0) continue;
            for (int v = 1; v < sz(dp[j].se); v += 2) {
                int id = dp[j].se[v];
                if (USED[vx[id]] || USED[vy[id]]) {
                    is_ok = 0;
                    break;
                }
                ANSWER.insert(id);
                USED[vx[id]] = USED[vy[id]] = 1;
            }
            usd[j] = 1;
        }
        if (!is_ok) {
            l = mid;
            continue;
        }
        ve<set<int>> G(n);
        forn (j, m) {
            if (!usd[j]) {
                int v = dp[j].fi[0], u = dp[j].fi.back();
                G[v].insert(j);
                G[u].insert(j);
            }
        }
        //debug(mid, G, USED);
        set<pii> tmp;
        ve<int> ban(n);
        forn (j, m) {
            for (int i = 1; i + 1 < sz(dp[j].fi); i++) ban[dp[j].fi[i]] = 1;
        }
        forn (i, n) if (!USED[i] && !ban[i]) tmp.insert({sz(G[i]), i});
        while (sz(tmp)) {
            auto el = *tmp.begin();
            tmp.erase(el);
            int v = el.se, c = el.fi;
            if (c == 0) continue;
            if (c >= 3) {
                is_ok = 0;
                break;
            }
            int j = *G[v].begin();
            int u = v ^ dp[j].fi[0] ^ dp[j].fi.back();
            //debug(v, u, j);
            if (tmp.find({sz(G[u]), u}) != tmp.end()) {
                tmp.erase({sz(G[u]), u});
                G[u].erase(j);
                tmp.insert({sz(G[u]), u});   
            }
            if (v != dp[j].fi[0]) {
                reverse(all(dp[j].fi));
                reverse(all(dp[j].se));
            }
            for (int v = 0; v < sz(dp[j].se); v += 2) {
                int id = dp[j].se[v];
                if (USED[vx[id]] || USED[vy[id]]) {
                    is_ok = 0;
                    break;
                }
                ANSWER.insert(id);
                USED[vx[id]] = USED[vy[id]] = 1;
            }
            //debug(is_ok);
            if (!is_ok) break;
            usd[j] = 1;
        }
        for (auto x : usd) if (!x) is_ok = 0;
        if (!is_ok) {
            l = mid;
            continue;
        }
        was = 1;
        RESULT = max(result, mid);
        ANS = ANSWER;
        r = mid;
    }
    if (was) {
        cout << "Yes\n" << RESULT << " " << sz(ANS) << '\n';
        for (auto x : ANS) cout << x + 1 << " ";
    }
    else {
        cout << "No";
    }
}
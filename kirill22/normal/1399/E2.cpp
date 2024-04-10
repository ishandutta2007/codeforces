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

vector<vector<pii>> g;
vector<int> l, r, d, cnt, c;

int dfs(int v, int pr) {
    if (v != 0 && g[v].size() == 1) {
        if (pr != -1) {
            cnt[pr]++;
        }
        return 1;
    }
    int c = 0;
    for (auto el : g[v]) {
        if (el.se == pr) continue;
        c += dfs(el.fi, el.se);
    }
    if (pr != -1) cnt[pr] += c;
    return c;
}

int f(int x) {
    return x - x / 2;
}

void solve() {
    int n, m, s;
    cin >> n >> s;
    m = n - 1;
    g.clear();
    l.clear();
    r.clear();
    d.clear();
    c.clear();
    cnt.clear();
    g.resize(n);
    l.resize(m);
    r.resize(m);
    d.resize(m);
    c.resize(m);
    cnt.resize(m, 0);
    for (int i = 0; i < m; i++) {
        int x, y, w, C;
        cin >> x >> y >> w >> C;
        c[i] = C;
        x--, y--;
        g[x].pb({y, i});
        g[y].pb({x, i});
        l[i] = x, r[i] = y, d[i] = w;
    }
    dfs(0, -1);
    int s2 = 0;
    set<pii> st1, st2;
    for (int i = 0; i < m; i++) {
        if (c[i] == 1) {
            s2 += cnt[i] * d[i];
            st1.insert({f(d[i]) * cnt[i], i});
        }
        else {
            s2 += cnt[i] * d[i];
            st2.insert({f(d[i]) * cnt[i], i});
        }
    }
    //debug(cnt, s2);
    int ans = 0;
    while (s2 > s) {
        ans++;
        if (st1.size() == 0) {
            auto el2 = *st2.rbegin();
            st2.erase(el2);
            s2 -= el2.fi;
            int i = el2.se;
            d[i] -= el2.fi / cnt[i];
            st2.insert({f(d[i]) * cnt[i], i});
            ans++;
            continue;
        }
        if (st2.size() == 0) {
            auto el = *st1.rbegin();
            st1.erase(el);
            s2 -= el.fi;
            int i = el.se;
            d[i] -= el.fi / cnt[i];
            st1.insert({f(d[i]) * cnt[i], i});
            continue;
        }
        auto el = *st1.rbegin();
        auto el2 = *st2.rbegin();
        int z = el.fi + cnt[el.se] * f(d[el.se] - el.fi / cnt[el.se]);
        if (el.fi >= el2.fi || s2 - el.fi <= s || z >= el2.fi) {
            st1.erase(el);
            s2 -= el.fi;
            int i = el.se;
            d[i] -= el.fi / cnt[i];
            st1.insert({f(d[i]) * cnt[i], i});
            continue;
        }
        st1.erase(el);
        if (st1.size() > 0) {
            auto EL = *st1.rbegin();
            if (EL.fi + el.fi >= el2.fi) {
                s2 -= el.fi;
                int i = el.se;
                d[i] -= el.fi / cnt[i];
                st1.insert({f(d[i]) * cnt[i], i});
                continue;
            }
            st1.insert(el);
        }
        else st1.insert(el);
        ans++;
        st2.erase(el2);
        s2 -= el2.fi;
        int i = el2.se;
        d[i] -= el2.fi / cnt[i];
        st2.insert({f(d[i]) * cnt[i], i});
    }
    cout << ans << '\n';
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
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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> gist;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (auto x : a) gist[x]++;
    for (auto x : b) gist[x]++;
    for (auto el : gist) {
        if (el.se != 2) {
            cout << -1 << endl;
            return;
        }
    }
    set<int> ma, mb;
    gist.clear();
    for (auto x : a) gist[x]++;
    for (auto el : gist) {
        if (el.se == 2) ma.insert(el.fi);
    }
    gist.clear();
    for (auto x : b) gist[x]++;
    for (auto el : gist) {
        if (el.se == 2) mb.insert(el.fi);
    }
    if (ma.size() != mb.size()) {
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    vector<int> pos(n + 1, 0), pos2(n + 1, 0);
    for (int i = 0; i < n; i++) pos[a[i]] = i;
    for (int i = n - 1; i >= 0; i--) pos2[a[i]] = i;
    vector<pii> g[n + 1];
    map<pii, int> fst;
    set<int> p;
    for (auto x : ma) {
        int l = pos2[x], r = pos[x];
        vector<int> t1, t2;
        int tl = l, tr = r;
        while (true) {
            t1.pb(tl);
            if (mb.find(b[tl]) != mb.end()) {
                break;
            }
            int y = b[tl];
            tl = pos[y];
        }
        while (true) {
            t2.pb(tr);
            if (mb.find(b[tr]) != mb.end()) {
                break;
            }
            int y = b[tr];
            tr = pos[y];
        }
        if (b[t1.back()] == b[t2.back()]) {
            p.insert(x);
            p.insert(b[t1.back()]);
            if (t1.size() > t2.size()) swap(t1, t2);
            for (auto u : t1) ans.pb(u);
            continue;
        }
        g[x].pb({b[t1.back()], t1.size()});
        g[x].pb({b[t2.back()], t2.size()});
        g[b[t1.back()]].pb({x, t1.size()});
        g[b[t2.back()]].pb({x, t2.size()});
        fst[{x, b[t1.back()]}] = l;
        fst[{x, b[t2.back()]}] = r;
    }
    for (auto x : p) if (ma.find(x) != ma.end()) ma.erase(x);
    for (auto x : p) if (mb.find(x) != mb.end()) mb.erase(x);
    while (ma.size() > 0) {
        auto x = *ma.begin();
        vector<int> w;
        vector<int> v;
        int y = x, pr = -1;
        while (true) {
            for (auto el : g[y]) {
                if (el.fi != pr) {
                    w.pb(el.se);
                    v.pb(el.fi);
                    pr = y;
                    y = el.fi;
                    break;
                }
            }
            if (y == x) break;
        }
        int z = 0, z2 = 0;
        for (int i = 0; i < w.size(); i++) {
            if (i % 2 == 0) z += w[i];
            else z2 += w[i];
        }
        if (z >= z2) {
            for (int i = 1; i < w.size(); i += 2) {
                int x = v[i], y = v[i - 1];
                ma.erase(x);
                mb.erase(y);
                int tl = fst[{x, y}];
                while (true) {
                    ans.pb(tl);
                    if (b[tl] == y) {
                        break;
                    }
                    int z = b[tl];
                    tl = pos[z];
                }
            }
        }
        else {
            for (int i = 1; i < w.size(); i += 2) {
                int x = v[i], y = v[(i + 1) % (int) v.size()];
                ma.erase(x);
                mb.erase(y);
                int tl = fst[{x, y}];
                while (true) {
                    ans.pb(tl);
                    if (b[tl] == y) {
                        break;
                    }
                    int z = b[tl];
                    tl = pos[z];
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x + 1 << " ";
    cout << endl;
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
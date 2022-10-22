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

const int N = 1e5;
int p[2][N], cnt[2][N];
set<pii> t[2][N];
set<int> root[2];

int get(int j, int x) {
    return (x == p[j][x] ? x : (p[j][x] = get(j, p[j][x])));
}

void unite(int j, int x, int y) {
    x = get(j, x), y = get(j, y);
    if (x == y) return;
    if (cnt[j][x] < cnt[j][y]) swap(x, y);
    p[j][y] = x;
    root[j].erase(y);
    cnt[j][x] += cnt[j][y];
    for (auto [id, v] : t[j][y]) {
        t[j][x].insert({id, v});
        int r = get(1 - j, v);
        t[1 - j][r].erase({y, v});
        t[1 - j][r].insert({x, v});
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, m2;
    cin >> n >> m >> m2;
    forn (i, n) {
        forn (j, 2) {
            p[j][i] = i;
            root[j].insert(i);
            t[j][i].insert({i, i});
            cnt[j][i] = 1;
        }
    }
    forn (i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        unite(0, x, y);
    }
    forn (i, m2) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        unite(1, x, y);
    }
    ve<pii> ans;
    while (1) {
        if (sz(root[0]) == 1 || sz(root[1]) == 1) break;
        int v = get(0, 0);
        auto L = *t[0][v].begin(), R = *t[0][v].rbegin();
        if (L.fi == R.fi) {
            for (auto x : root[1]) {
                if (x == L.fi) continue;
                unite(0, v, x);
                unite(1, v, x);
                ans.pb({v, x});
                break;
            }
        }
        else {
            for (auto x : root[0]) {
                if (x == v) continue;
                int y = L.se;
                if (L.fi == get(1, x)) y = R.se;
                unite(0, x, y);
                unite(1, x, y);
                ans.pb({x, y});
                break;
            }
        }
    }
    cout << sz(ans) << '\n';
    for (auto [x, y] : ans) cout << x + 1 << " " << y + 1 << '\n';
}
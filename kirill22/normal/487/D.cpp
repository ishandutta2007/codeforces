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

int n, m, M;
ve<ve<char>> a;
ve<ve<pii>> t;

ve<pii> build(int j) {
    ve<pii> res(M);
    forn (i, M) {
        int x = j, y = i;
        while (y >= 0 && y < M) {
            if (a[x][y] == '^') {
                x--;
                break;
            }
            if (a[x][y] == '>') {
                if (y + 1 < M && a[x][y + 1] == '<') {
                    x = -2, y = -2;
                    break;
                }
                y++;
            }
            else if (a[x][y] == '<') {
                if (y - 1 >= 0 && a[x][y - 1] == '>') {
                    x = -2, y = -2;
                    break;
                }
                y--;
            }
        }
        res[i] = {x, y};
    }
    return res;
}

ve<pii> merge(ve<pii> a, ve<pii> b) {
    ve<pii> res(M);
    forn (i, M) {
        if (b[i].se <= -1 || b[i].se >= M) {
            res[i] = b[i];
            continue;
        }
        int pos = b[i].se;
        res[i] = a[pos];
    }
    return res;
}

void build(int v, int l, int r) {
    if (l + 1 == r) {
        t[v] = build(l);
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

void update(int v, int l, int r, int i) {
    if (l + 1 == r) {
        t[v] = build(l);
        return;
    }
    int m = (l + r) / 2;
    if (i < m) update(v * 2 + 1, l, m, i);
    else update(v * 2 + 2, m, r, i);
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

pii get(int v, int l, int r, int x, int y) {
    //debug(v, l, r, x, y);
    if (r - 1 == x) {
        pii res = t[v][y];
        return res;
    }
    int m = (l + r) / 2;
    if (x < m) return get(v * 2 + 1, l, m, x, y);
    pii res = get(v * 2 + 2, m, r, x, y);
    //debug(v, res);
    if (res.se <= -1 || res.se >= M) return res;
    return get(v * 2 + 1, l, m, res.fi, res.se);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n >> m >> q;
    M = m;
    a.resize(n, ve<char> (m));
    forn (i, n) {
        forn (j, m) {
            cin >> a[i][j];
        }
    }
    t.resize(4 * n);
    build(0, 0, n);
    while (q--) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        x--, y--;
        if (c == 'C') {
            cin >> c;
            a[x][y] = c;
            update(0, 0, n, x);
        }
        else {
            auto res = get(0, 0, n, x, y);
            cout << res.fi + 1 << " " << res.se + 1 << '\n';
        }
    }
}
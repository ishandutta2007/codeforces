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

struct node {
    int len, ans, xl, xr, cl, cr;
    node() : ans(0) {}
    node(int x) : len(1), ans(1), xl(x), xr(x), cl(1), cr(1) {}
};

ve<node> t;
ve<int> a;

node merge(node a, node b) {
    if (a.ans == 0) return b;
    if (b.ans == 0) return a;
    node res;
    res.ans = a.ans + b.ans;
    res.len = a.len + b.len;
    res.xl = a.xl, res.xr = b.xr;
    if (a.xr <= b.xl) {
        res.ans += a.cr * b.cl;
    }
    res.cl = a.cl;
    if (a.cl == a.len && a.xr <= b.xl) res.cl += b.cl;
    res.cr = b.cr;
    if (b.cr == b.len && a.xr <= b.xl) res.cr += a.cr;
    return res;
}

void build(int v, int l, int r) {
    if (l + 1 == r) {
        t[v] = node(a[l]);
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

void update(int v, int l, int r, int i, int x) {
    if (l + 1 == r) {
        t[v] = node(x);
        return;
    }
    int m = (l + r) / 2;
    if (i < m) update(v * 2 + 1, l, m, i, x);
    else update(v * 2 + 2, m, r, i, x);
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

node get(int v, int l, int r, int l1, int r1) {
    if (l1 >= r || l >= r1) return node();
    if (l1 <= l && r <= r1) return t[v];
    int m = (l + r) / 2;
    return merge(get(v * 2 + 1, l, m, l1,r1), get(v * 2 + 2, m, r, l1, r1));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    a.resize(n);
    t.resize(4 * n);
    forn (i, n) cin >> a[i];
    build(0, 0, n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            update(0, 0, n, i, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << get(0, 0, n, l, r + 1).ans << '\n';
        }
    }
}
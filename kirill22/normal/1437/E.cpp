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
#define eb emplace_back
#define ld long double

struct node {
    int x = 0, y = 0, cnt = 0, z = 0;
    node* l;
    node* r;
    node() {};
    node(int x, int z) : x(x), y((rand() << 16) + rand()), cnt(z), z(z), l(nullptr), r(nullptr) {};
};

typedef node* pnode;

void update(pnode t) {
    t->cnt = t->z;
    if (t->l) t->cnt = max(t->cnt, t->l->cnt);
    if (t->r) t->cnt = max(t->cnt, t->r->cnt);
}

pair<pnode, pnode> split(pnode t, int x) {
    if (!t) return {nullptr, nullptr};
    if (t->x <= x) {
        auto res = split(t->r, x);
        t->r = res.fi;
        update(t);
        return {t, res.se};
    }
    else {
        auto res = split(t->l, x);
        t->l = res.se;
        update(t);
        return {res.fi, t};
    }
}

pnode merge(pnode a, pnode b) {
    if (!a) return b;
    if (!b) return a;
    if (a->y < b->y) {
        a->r = merge(a->r, b);
        update(a);
        return a;
    }
    else {
        b->l = merge(a, b->l);
        update(b);
        return b;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> z = {-1};
    for (int j = 0; j < k; j++) {
        int x;
        cin >> x;
        z.pb(x - 1);
    }
    z.pb(n);
    int ans = 0;
    auto solve = [&] (int l, int r, int x, int y) {
        if (l > r) return 0ll;
        if (y - x + 1 < r - l + 1) return -1ll;
        int mx = 0;
        pnode A = nullptr;
        for (int i = r; i >= l; i--) {
            if (r - i <= y - a[i] && a[i] <= y && a[i] >= x && a[i] - x >= i - l) {
                int z = 1;
                auto res = split(A, a[i] - i - 1);
                if (res.se) z = max(z, res.se->cnt + 1);
                pnode X = new node(a[i] - i, z);
                pnode Y = merge(X, res.se);
                A = merge(res.fi, Y);
                mx = max(mx, z);
            }
        }
        return r - l + 1 - mx;
    };
    for (int i = 1; i < z.size(); i++) {
        int x = -1e9;
        if (z[i - 1] != -1) x = a[z[i - 1]] + 1;
        int y = 1e9 * 2;
        if (z[i] != n) y = a[z[i]] - 1;
        int p = solve(z[i - 1] + 1, z[i] - 1, x, y);
        if (p == -1) {
            cout << -1;
            return 0;
        }
        ans += p;
    }
    for (int i = 2; i + 1 < z.size(); i++) {
        if (a[z[i - 1]] >= a[z[i]]) {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
}
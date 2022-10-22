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

vector<int> fa, fb;

void update(int x, int d) {
    while (x < fa.size()) {
        fa[x] += d;
        x = (x | (x + 1));
    }
}

void update2(int x, int d) {
    while (x < fb.size()) {
        fb[x] += d;
        x = (x | (x + 1));
    }
}

int get(int x) {
    int res = 0;
    while (x >= 0) {
        res += fa[x];
        x = (x & (x + 1)) - 1;
    }
    return res;
}

int get2(int x) {
    int res = 0;
    while (x >= 0) {
        res += fb[x];
        x = (x & (x + 1)) - 1;
    }
    return res;
}


vector<int> t, d;

void push(int v, int l, int r) {
    if (l + 1 != r) {
        d[v * 2 + 1] += d[v];
        d[v * 2 + 2] += d[v];
    }
    t[v] += d[v];
    d[v] = 0;
}

int Get(int v, int l, int r, int l1, int r1) {
    push(v, l, r);
    if (l1 >= r || l >= r1) return -1e18;
    if (l1 <= l && r <= r1) return t[v];
    int m = (l + r) / 2;
    return max(Get(v * 2 + 1, l, m, l1, r1), Get(v * 2 + 2, m, r, l1, r1));
}

void Update(int v, int l, int r, int l1, int r1, int x) {
    push(v, l, r);
    if (l1 >= r || l >= r1) return;
    if (l1 <= l && r <= r1) {
        d[v] += x;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    Update(v * 2 + 1, l, m, l1, r1, x);
    Update(v * 2 + 2, m, r, l1, r1, x);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

vector<int> t2, d2;

void push2(int v, int l, int r) {
    if (l + 1 != r) {
        d2[v * 2 + 1] += d2[v];
        d2[v * 2 + 2] += d2[v];
    }
    t2[v] += d2[v];
    d2[v] = 0;
}

int Get2(int v, int l, int r, int l1, int r1) {
    push2(v, l, r);
    if (l1 >= r || l >= r1) return -1e18;
    if (l1 <= l && r <= r1) return t2[v];
    int m = (l + r) / 2;
    return max(Get2(v * 2 + 1, l, m, l1, r1), Get2(v * 2 + 2, m, r, l1, r1));
}

void Update2(int v, int l, int r, int l1, int r1, int x) {
    push2(v, l, r);
    if (l1 >= r || l >= r1) return;
    if (l1 <= l && r <= r1) {
        d2[v] += x;
        push2(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    Update2(v * 2 + 1, l, m, l1, r1, x);
    Update2(v * 2 + 2, m, r, l1, r1, x);
    t2[v] = max(t2[v * 2 + 1], t2[v * 2 + 2]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pii> a, b;
    vector<int> c;
    for (int i = 0; i < n; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        c.pb(x);
        c.pb(y);
        if (t == 1) {
            a.pb({x, y});
        }
        else {
            b.pb({x, y});
        }
    }
    int ans = max(a.size(), b.size());
    sort(all(c));
    c.resize(unique(all(c)) - c.begin());
    unordered_map<int, int> ind;
    for (int i = 0; i < c.size(); i++) ind[c[i]] = i;
    for (int i = 0; i < a.size(); i++) {
        a[i].fi = ind[a[i].fi];
        a[i].se = ind[a[i].se];
    }
    for (int i = 0; i < b.size(); i++) {
        b[i].fi = ind[b[i].fi];
        b[i].se = ind[b[i].se];
    }
    //debug(a, b);
    fa.resize(c.size() + 10);
    fb.resize(c.size() + 10);
    t.resize(4 * (a.size() + 1), 0);
    d.resize(4 * (a.size() + 1), 0);
    t2.resize(4 * (b.size() + 1), 0);
    d2.resize(4 * (b.size() + 1), 0);
    sort(all(a), [&] (pii x, pii y) {
         if (x.se != y.se) return x.se < y.se;
         return x.fi > y.fi;
    });
    sort(all(b), [&] (pii x, pii y) {
         if (x.se != y.se) return x.se < y.se;
         return x.fi > y.fi;
    });
    vector<int> dp(a.size() + 1, 0), dp2(b.size() + 1, 0);
    int i = 0, j = 0;
    while (i < a.size() || j < b.size()) {
        bool f = true;
        if (i == a.size()) f = false;
        if (i != a.size() && j != b.size() && a[i].se > b[j].se) f = false;
        if (f) {
            dp[i + 1] = dp[i];
            update(a[i].fi, 1);
            int l = -1, r = j;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (b[m].se >= a[i].fi) r = m;
                else l = m;
            }
            Update2(0, 0, b.size() + 1, l + 2, j + 1, -1);
            dp[i + 1] = max(dp[i + 1], Get2(0, 0, b.size() + 1, 0, l + 2) + (i + 1));
            Update(0, 0, a.size() + 1, i + 1, i + 2, dp[i + 1] - get2(a[i].se));
            i++;
        }
        else {
            dp2[j + 1] = dp2[j];
            update2(b[j].fi, 1);
            int l = -1, r = i;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (a[m].se >= b[j].fi) r = m;
                else l = m;
            }
            Update(0, 0, a.size() + 1, l + 2, i + 1, -1);
            dp2[j + 1] = max(dp2[j + 1], Get(0, 0, a.size() + 1, 0, l + 2) + (j + 1));
            Update2(0, 0, b.size() + 1, j + 1, j + 2, dp2[j + 1] - get(b[j].se));
            j++;
        }
    }
    //debug(dp, dp2);
    for (auto x : dp) ans = max(ans, x);
    for (auto x : dp2) ans = max(ans, x);
    cout << ans;
}
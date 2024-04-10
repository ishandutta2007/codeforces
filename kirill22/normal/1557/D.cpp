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

ve<pii> t, d;

void push(int v, int l, int r) {
    t[v] = max(t[v], d[v]);
    if (l + 1 != r) {
        d[v * 2 + 1] = max(d[v * 2 + 1], d[v]);
        d[v * 2 + 2] = max(d[v * 2 + 2], d[v]);
    }
    d[v] = {-1, -1};
}

void update(int v, int l, int r, int l1, int r1, pii x) {
    push(v, l, r);
    if (l1 >= r || l >= r1) return;
    if (l1 <= l && r <= r1) {
        d[v] = x;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    update(v * 2 + 1, l, m, l1, r1, x);
    update(v * 2 + 2, m, r, l1, r1, x);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

pii get(int v, int l, int r, int l1, int r1) {
    push(v, l, r);
    if (l1 >= r || l >= r1) return {-1, -1};
    if (l1 <= l && r <= r1) return t[v];
    int m = (l + r) / 2;
    return max(get(v * 2 + 1, l, m, l1, r1), get(v * 2 + 2, m, r, l1, r1));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    ve<ve<pii>> a(n);
    ve<int> z;
    forn (i, m) {
        int j, l, r;
        cin >> j >> l >> r;
        j--;
        a[j].pb({l, r});
        z.pb(l);
        z.pb(r);
    }
    sort(all(z)); z.resize(unique(all(z)) - z.begin());
    forn (i, n) for (auto& [x, y] : a[i]) {
        x = lower_bound(all(z), x) - z.begin();
        y = lower_bound(all(z), y) - z.begin();
    }
    t.resize(4 * sz(z), {-1, -1});
    d.resize(4 * sz(z), {-1, -1});
    ve<int> dp(n), pr(n);
    forn (i, n) {
        pii res = {0, -1};
        for (auto [l, r] : a[i]) {
            res = max(res, get(0, 0, sz(z), l, r + 1));
        }
        dp[i] = res.fi + 1, pr[i] = res.se;
        for (auto [l, r] : a[i]) {
            update(0, 0, sz(z), l, r + 1, {dp[i], i});
        }
    }
    int j = 0;
    forn (i, n) if (dp[i] > dp[j]) j = i;
    ve<int> used(n);
    cout << n - dp[j] << '\n';
    while (j >= 0) {
        used[j] = 1;
        j = pr[j];
    }
    forn (i, n) if (!used[i]) cout << i + 1 << " ";
}
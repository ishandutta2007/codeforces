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

const int mod = 1e9 + 7;

int inv(int x);
int sum(int x, int y) { return (x + y) % mod; }
int raz(int x, int y) { return (x - y + mod) % mod; }
int mul(int x, int y) { return (x * 1ll * y) % mod; }
int del(int x, int y) { return (x * 1ll * inv(y)) % mod; }

int binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n % 2 == 1) res = mul(res, a);
        n >>= 1;
        a = mul(a, a);
    }
    return res;
}

int inv(int x) { return binpow(x, mod - 2); }

vector<int> fact(1, 1);
vector<int> inv_fact(1, 1);

void fast(int n) {
    while ((int) fact.size() < n + 1) {
        fact.push_back(mul(fact.back(), (int) fact.size()));
    }
    inv_fact.resize(n + 1, 1);
    inv_fact[n] = del(1, fact[n]);
    for (int i = n - 1; i >= 2; i--) {
        inv_fact[i] = mul(inv_fact[i + 1], (i + 1));
    }
}

int C(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    while ((int) fact.size() < n + 1) {
        fact.push_back(mul(fact.back(), (int) fact.size()));
        inv_fact.push_back(inv(fact.back()));
    }
    return mul(mul(fact[n], inv_fact[k]), inv_fact[n - k]);
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        int x = r - i;
        if (x > 0 && l + x <= n) st.insert(x);
        x = i - l;
        if (x > 0 && r - x >= 1) st.insert(x);
    }
    int L = 1, R = r - 1;
    R = min(R, n - l);
    if (R < L) {
        cout << 0 << '\n';
        return;
    }
    int ans = 0;
    int cnt = R - L + 1 - sz(st);
    //debug(st, cnt, L, R);
    ve<int> tmp = {n / 2};
    if (n % 2 == 1) tmp.pb((n + 1) / 2);
    for (auto x : tmp) {
        int res = mul(cnt, C(n, x));
        ans = sum(ans, res);
        for (auto y : st) {
            int R = min(n, r - y);
            int L = max(1ll, l + y);
            if (R + 1 < L) continue;
            int need = x - (L - 1);
            ans = sum(ans, C(R - L + 1, need));
        }
    }
    cout << ans << '\n';
}

signed main() {
    //
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
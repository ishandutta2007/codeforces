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


#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define ld long double
#define forn(i, n) for (int i = 0; i < n; i++)

const int mod = 998244353;

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
    int n;
    cin >> n;
    fast(n + 5);
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = sum(dp[i], mul(dp[i - 2], mul(2, i - 1)));
    }
    vector<int> dp2(n + 1);
    dp2[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp2[i] = dp2[i - 1];
        if (i >= 2) {
            dp2[i] = sum(dp2[i], mul(dp2[i - 2], i - 1));
        }
    }
    int ans = 0;
    for (int x = 0; x * 2 <= n; x += 2) {
        int res = mul(C(n - x, x), mul(dp[x], dp2[n - 2 * x]));
        //cout << x << " " << res << " " << dp[x] << endl;
        ans = sum(ans, res);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
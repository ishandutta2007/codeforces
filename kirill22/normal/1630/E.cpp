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
    map<int, int> b;
    forn (i, n) {
        int x;
        cin >> x;
        b[x]++;
    }
    C(n + 1, 0);
    vector<int> a;
    for (auto el : b) a.pb(el.se);
    sort(all(a));
    if (sz(a) == 1) {
        cout << 1 << '\n';
        return;
    }
    int ans = 0, sum = 0;
    vector<int> res(n + 1), dp(n + 1);
    for (int j = 1; j <= n; j++) {
        if (n % j != 0) continue;
        int k = n / j;
        int f = 1;
        for (auto x : a) {
            if (x % k) {
                f = 0;
                break;
            }
        }
        if (!f) continue;
        int A = 1;
        int s = j;
        for (auto x : a) {
            x /= k;
            A = A * C(s, x) % mod;
            s -= x;
        }
        //debug(A);
        res[j] = (res[j] + A) % mod;
        for (int x = j + j; x <= n; x += j) {
            res[x] = (res[x] - res[j] + mod) % mod;
        }
        //debug(j, res[j]);
        res[j] = res[j] * inv(j) % mod;
        //debug(res[j]);
        sum = (sum + res[j]) % mod;
        int B = 0;
        int AA = fact[j - 2];
        for (auto x : a) AA = AA * inv_fact[x / k] % mod;
        forn (i, sz(a)) {
            int x = a[i] / k;
            if (x < 2) continue;
            int A = AA * fact[x] % mod * inv_fact[x - 2] % mod;
            //debug(A);
            B = (B + A) % mod;
        }
        B = B * k * j % mod;
        dp[j] = (dp[j] + B) % mod;
        for (int x = j + j; x <= n; x += j) {
            dp[x] = (dp[x] - (x / x) * dp[j] % mod + mod) % mod;
        }
        //debug(B, dp[j]);
        ans = (ans + dp[j] * inv(j)) % mod;
    }
    cout << (sum * n % mod - ans + mod) % mod * inv(sum) % mod << '\n';
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
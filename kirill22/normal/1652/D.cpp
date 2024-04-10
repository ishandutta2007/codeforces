#include<bits/stdc++.h>

using namespace std;

template<typename A, typename B>
string to_string(pair<A, B> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char& c) {
    string res = "'";
    res += c;
    return res + "'";
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template<typename A>
string to_string(A a) {
    string res = "{";
    int f = 0;
    for (const auto& x : a) {
        if (f) {
            res += ", ";
        }
        f = 1;
        res += to_string(x);
    }
    return res + "}";
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
    return "{" + to_string(p.first) + ", " + to_string(p.second) + "}";
}

void debug_out() { cerr << endl; }

template<typename Head, typename... Tail>
void debug_out(Head h, Tail... t) {
    cerr << " " << to_string(h);
    debug_out(t...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << ":] ", debug_out(__VA_ARGS__)
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int) (x).size()
#define ld long double
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)

const int mod = 998244353;

int binpow(int x, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % mod;
        }
        n /= 2;
        x = x * x % mod;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<pii> dp(n);
    vector<int> x(n), y(n), A(n), B(n);
    vector<vector<int>> g(n);
    forn (i, n - 1) {
        cin >> x[i] >> y[i] >> A[i] >> B[i];
        x[i]--, y[i]--;
        g[x[i]].pb(i);
        g[y[i]].pb(i);
    }
    map<int, int> cnt2;
    map<int, int> tmp;
     vector<int> d(n + 1), prime;
    for (int i = 2; i <= n; i++) {
        if (d[i] == 0) {
            d[i] = i;
            prime.push_back(i);
        }
        for (auto j : prime) {
            if (j * i > n || j > d[i]) break;
            d[i * j] = j;
        }
    }
    function<void(int, int)> dfs = [&] (int v, int pr) {
        for (auto i : g[v]) {
            int u = x[i] ^ y[i] ^ v;
            if (u == pr) continue;
            if (v != x[i]) swap(A[i], B[i]), swap(x[i], y[i]);
            {
                int x = B[i];
                while (x > 1) {
                    int k = d[x];
                    while (x % k == 0) tmp[k]++, x /= k;
                }
            }
            {
                int x = A[i];
                while (x > 1) {
                    int k = d[x];
                    while (x % k == 0) {
                        tmp[k]--, x /= k;
                        if (tmp[k] < 0) cnt2[k] = max(cnt2[k], -tmp[k]);
                    }
                }
            }
            dfs(u, v);
            {
                int x = B[i];
                while (x > 1) {
                    int k = d[x];
                    while (x % k == 0) tmp[k]--, x /= k;
                }
            }
            {
                int x = A[i];
                while (x > 1) {
                    int k = d[x];
                    while (x % k == 0) {
                        tmp[k]++, x /= k;
                    }
                }
            }
        }
    };
    dfs(0, -1);
    int X = 1;
    for (auto [y, z] : cnt2) {
        forn (i, z) X = X * y % mod;
    }
    //debug(X);
    int ans = 0;
    function<void(int, int, int)> dfs2 = [&] (int v, int pr, int X) {
        //debug(v, X);
        ans = (ans + X) % mod;
        for (auto i : g[v]) {
            int u = x[i] ^ y[i] ^ v;
            if (u == pr) continue;
            if (v != x[i]) swap(A[i], B[i]);
            int y = X * B[i] % mod;
            y = y * binpow(A[i], mod - 2) % mod;
            dfs2(u, v, y);
        }
    };
    dfs2(0, -1, X);
    cout << ans << '\n';
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
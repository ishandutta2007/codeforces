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

void solve() {
    int n, mod;
    cin >> n >> mod;
    int ans = 0;
    int mx = n * (n - 1) / 2 + 1; 
    ve<ve<int>> dp(n + 1, ve<int> (mx));
    ve<ve<int>> C(n + 1, ve<int> (n + 1));
    forn (i, n + 1) {
        forn (j, n + 1) {
            if (j > i) {
                C[i][j] = 0;
            }
            else {
                if (j == 0 || j == i) {
                    C[i][j] = 1;
                }
                else {
                    C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
                }
            }
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x < i; x++) {
            forn (v, mx) {
                if (v + x < mx) {
                    dp[i][v + x] = (dp[i][v + x] + dp[i - 1][v]) % mod;
                }
            }
        }
    }
    ve<ve<int>> calc(n + 1, ve<int> (n + 1));
    for (int need = 1; need <= n - 1; need++) {
        for (int cnt = 0; cnt <= need; cnt++) {
            int sum = 0;
            forn (A, mx) {
                if (A - cnt - 2 >= 0) {
                    sum = (sum + dp[need][A - cnt - 2]) % mod;
                }
                calc[need][cnt] = (calc[need][cnt] + sum * dp[need][A]) % mod;
            }
        }
    }
    ve<int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;
    forn (pos, n) {
        int need = n - pos - 1;
        for (int z = 1; z <= n - 1; z++) {
            for (int cnt = 0; cnt <= min(z - 1, need - 1); cnt++) {
                int res = C[z - 1][cnt];
                if (need - cnt - 1 > n - (z - 1) - 2) continue;
                res = (res * C[n - (z - 1) - 2][need - cnt - 1]) % mod;
                res = (res * (n - z)) % mod;
                res = (res * fact[pos]) % mod;
                ans = (ans + res * calc[need][cnt]) % mod;
            }
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
    q = 1;
    while (q--) {
        solve();
    }
}
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

void solve() {
    int n;
    cin >> n;
    ve<int> a;
    forn (i, n) {
        char c;
        cin >> c;
        if (c == '-') a.pb(-1);
        else {
            int x;
            cin >> x;
            a.pb(x);
        }
    }
    int ans = 0;
    forn (j, n) {
        if (a[j] == -1) continue;
        int x = a[j];
        ve<int> dp(n + 1, 0);
        dp[0] = 1;
        forn (i, j) {
            if (a[i] == -1) {
                dp[0] = (dp[0] * 2) % mod;
                forn (v, n) dp[v] = (dp[v] + dp[v + 1]) % mod;
            }
            else if (a[i] <= x) {
                for (int v = n; v >= 1; v--) dp[v] = (dp[v] + dp[v - 1]) % mod;
            }
            else {
                for (auto& x : dp) x = (x * 2) % mod;
            }
        }
        //debug(dp);
        for (int v = n; v >= 1; v--) dp[v] = dp[v - 1];
        dp[0] = 0;
        for (int i = j + 1; i < n; i++) {
            if (a[i] == -1) {
                forn (v, n) dp[v] = (dp[v] + dp[v + 1]) % mod;
            }
            else if (a[i] < x) {
                for (int v = n; v >= 1; v--) dp[v] = (dp[v] + dp[v - 1]) % mod;
            }
            else {
                for (auto& x : dp) x = (x * 2) % mod;
            }
            dp[0] = 0;
        }
        for (auto y : dp) {
            ans = (ans + x * y) % mod;
        }
        //debug(j, dp);
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
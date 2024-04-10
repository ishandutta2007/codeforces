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

const int N = 1e4 + 22, D = 2001 + 22;
ve<ve<int>> dp(N, ve<int> (D));
//vector<int> dp2[N];

void solve() {
    int n;
    cin >> n;
    int mx = 2001;
    forn (v, n + 1) forn (i, mx) dp[v][i] = 1e18;
    dp[0][0] = 0;
    ve<int> a(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i - 1] = x;
        forn (j, mx) {
            if (dp[i - 1][j] == (int) 1e18) continue;
            int m = dp[i - 1][j];
            if (j - x >= 0) {
                dp[i][j - x] = min(dp[i][j - x], m);
            } else {
                dp[i][0] = min(dp[i][0], m + x - j);
            }
            if (j + x <= m) {
                dp[i][x + j] = min(dp[i][x + j], m);
            } else {
                dp[i][0] = min(dp[i][0], m + (j + x) - m);
            }
        }
        forn (j, mx) {
            if (dp[i][j] >= mx) dp[i][j] = (int) 1e18;
            //if (dp[i][j] != (int) 1e18) debug(i, j, dp[i][j]);
        }
    }
    int ans = 1e18;
    forn (j, mx) ans = min(ans, dp[n][j]);
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
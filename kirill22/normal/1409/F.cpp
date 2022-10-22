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

void solve() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    if (t[0] == t[1]) {
        for (int i = 0; i < n; i++) if (s[i] != t[0] && k > 0) k--, s[i] = t[0];
        int res = 0;
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (s[i] == t[0] && s[j] == t[0]) res++;
        cout << res << endl;
        return;
    }
    int ans = 0;
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (k + 1, vector<int> (n + 1, -1e18)));
    for (int j = 0; j <= k; j++) {
        if (j == 0) {
            if (s[n - 1] == t[1]) {
                dp[n - 1][0][1] = 0;
            }
            else dp[n - 1][0][0] = 0;
        }
        else {
            dp[n - 1][j][1] = 0;
        }
    }
    auto upd = [&] (int x, int y, int z, int x2, int y2, int z2, int c) {
        if (dp[x2][y2][z2] != -1e18) {
            dp[x][y][z] = max(dp[x][y][z], dp[x2][y2][z2] + c);
        }
    };
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= k; j++) {
            for (int c = 0; c <= n; c++) {
                if (s[i] == t[1]) {
                    if (c) upd(i, j, c, i + 1, j, c - 1, 0);
                }
                else if (s[i] == t[0]) {
                    upd(i, j, c, i + 1, j, c, c);
                }
                else upd(i, j, c, i + 1, j, c, 0);
                if (j) {
                    if (c) upd(i, j, c, i + 1, j - 1, c - 1, 0);
                    upd(i, j, c, i + 1, j - 1, c, c);
                }
            }
        }
    }
    //debug(dp);
    for (int i = 0; i < n; i++) for (int j = 0; j <= k; j++) for (int c = 0; c <= n; c++) ans = max(ans, dp[i][j][c]);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    q = 1;
    while (q--) solve();
}
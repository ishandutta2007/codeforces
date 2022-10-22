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
#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n >= 4 && m >= 4) {
        cout << -1;
        return;
    }
    if (n == 1 || m == 1) {
        cout << 0;
        return;
    }
    auto get = [&] (int x, int j) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            if ((j & (1 << i)) && a[i][x] == '0') res++;
            if ((j & (1 << i)) == 0 && a[i][x] == '1') res++;
        }
        return res;
    };
    int x = 4;
    if (n == 3) x = 8;
    vector<vector<int>> dp(m, vector<int> (x, 1e9));
    bool f[x][x];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            f[i][j] = true;
            for (int v = 0; v < n - 1; v++) {
                int res = 0;
                if ((i & (1 << v))) res++;
                if ((j & (1 << v))) res++;
                if ((i & (1 << (v + 1)))) res++;
                if ((j & (1 << (v + 1)))) res++;
                if (res % 2 == 0) f[i][j] = false;
            }
        }
    }
    for (int i = 0; i < x; i++) {
        dp[0][i] = get(0, i);
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < x; j++) {
            for (int j2 = 0; j2 < x; j2++) {
                if (f[j][j2]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j2] + get(i, j));
                }
            }
        }
    }
    //debug(dp);
    int ans = 1e9;
    for (int i = 0; i < x; i++) ans = min(ans, dp[m - 1][i]);
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
    while (q--) {
        solve();
    }
}
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

int go(int v, int k, int x) {
    forn (i, k + 1) {
        if (v == x) return 1;
        v /= 2;
    }
    return 0;
}

ve<int> solve(int v, map<int, int> a, int k) {
    ve<int> dp(3);
    if (sz(a) == 0) {
        int x = 1;
        for (int i = 2; i <= k; i++) {
            x = (4 * x) % mod;
            x = (x * x) % mod;
        }
        dp[0] = dp[1] = dp[2] = (x * 2) % mod;
        return dp;
    }
    if (k == 1) {
        dp[a[v]] = 1;
        return dp;
    }
    map<int, int> l, r;
    for (auto [x, y] : a) {
        if (x != v && go(x, k - 2, v * 2)) {
            l[x] = y;
        }
        if (x != v && go(x, k - 2, v * 2 + 1)) {
            r[x] = y;
        }
    }
    //debug(l, r);
    auto L = solve(v * 2, l, k - 1), R = solve(v * 2 + 1, r, k - 1);
    forn (i, 3) forn (j, 3) {
        forn (v, 3) {
            if (v != i && v != j) {
                dp[v] = (dp[v] + L[i] * R[j]) % mod;
            }
        }
    }
    if (a.find(v) != a.end()) {
        int x = a[v];
        forn (i, 3) {
            if (i != x) dp[i] = 0;
        }
    } else {
        for (auto& x : dp) {
            x = (x * 2) %  mod;
        }
    }
    //debug(v, dp);
    return dp;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    map<int, int> a;
    forn (i, k) {
        int x;
        cin >> x;
        string s;
        cin >> s;
        if (s[0] == 'w' || s[0] == 'y') a[x] = 0;
        if (s[0] == 'g' || s[0] == 'b') a[x] = 1;
        if (s[0] == 'r' || s[0] == 'o') a[x] = 2;
    }
    auto res = solve(1, a, n);
    int ans = 0;
    for (auto x : res) ans = (ans + x) % mod;
    cout << ans;
}
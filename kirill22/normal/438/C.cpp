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

int cos(pii a, pii b) {
    return a.fi * b.fi + a.se * b.se;
}

int sin(pii a, pii b) {
    return a.fi * b.se - a.se * b.fi;
}

pii go(pii a, pii b) {
    return {b.fi - a.fi, b.se - a.se};
}

int chk(pii a, pii b, pii c, pii d) {
    a = go(b, a);
    c = go(b, c);
    d = go(b, d);
    if (sin(a, c) < 0) swap(a, c);
    return (sin(a, d) >= 0 && sin(d, c) >= 0 && (cos(a, d) >= 0 || cos(d, c) >= 0));
}

int in(pii a, pii b, pii c) {
    if (sin(go(c, a), go(c, b)) == 0 && cos(go(c, a), go(c, b)) < 0) return 1;
    return 0;
}

int check(pii a, pii b, pii c, pii d) {
    if (in(c, d, a) || in(c, d, b) || in(a, b, c) || in(a, b, d)) return 1;
    return (chk(c, b, d, a) && chk(c, a, d, b));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ve<pii> a(n);
    forn (i, n) cin >> a[i].fi >> a[i].se;
    int sum = 0;
    forn (i, n) {
        int j = (i + 1) % n;
        sum += sin(a[i], a[j]);
    }
    sum = abs(sum);
    ve<ve<int>> ok(n, ve<int> (n));
    forn (i, n) {
        forn (j, n) {
            ok[i][j] = 1;
            if ((i + 1) % n == j || (j + 1) % n == i) continue;
            ve<int> dp;
            for (int v = 0; v <= min(i, j); v++) dp.pb(v);
            for (int v = max(i, j); v < n; v++) dp.pb(v);
            int sum2 = 0;
            forn (i, sz(dp)) {
                int j = (i + 1) % sz(dp);
                sum2 += sin(a[dp[i]], a[dp[j]]);
            }
            sum2 = abs(sum2);
            //if (i == 0 && j == 2)
            if (sum < sum2) ok[i][j] = 0;
            dp.clear();
            for (int v = min(i, j); v <= max(i, j); v++) dp.pb(v);
            forn (i, sz(dp)) {
                int j = (i + 1) % sz(dp);
                sum2 += sin(a[dp[i]], a[dp[j]]);
            }
            sum2 = abs(sum2);
            //if (i == 0 && j == 2)
            if (sum < sum2) ok[i][j] = 0;
            sum2 = 0;
            forn (v, n) {
                if (v != i && v != j && in(a[i], a[j], a[v])) ok[i][j] = 0;
            }
            //if (i == 0 && j == 2) debug(ok[i][j]);
            forn (v, n) {
                int v2 = (v + 1) % n;
                if (v == i || v == j || v2 == i || v2 == j) continue;
                //if (i == 0 && j == 2) debug(ok[i][j], v);
                if (check(a[i], a[j], a[v], a[v2])) ok[i][j] = 0;
                //if (i == 0 && j == 2) debug(ok[i][j], v);
            }
        }
    }
    debug(ok);
    ve<ve<int>> dp(n, ve<int> (n));
    for (int len = 3; len <= n; len++) {
        for (int l = 0, r = len - 1; r < n; l++, r++) {
            if (len == 3) {
                if (ok[l][r - 1] && ok[l][r] && ok[r - 1][r]) dp[l][r] = 1;
                continue;
            }
            if (ok[l + 1][r]) {
                dp[l][r] = (dp[l][r] + dp[l + 1][r]) % mod;
            }
            for (int j = r - 1; j > l + 1; j--) {
                if (ok[l][j]) {
                    //debug(j);
                    int res = dp[l][j];
                    //debug(res);
                    if (ok[r][j]) {
                        if (j + 1 != r) {
                            res = (res * dp[j][r]) % mod;
                        }
                    }
                    else {
                        res = 0;
                    }
                    //debug(res);
                    dp[l][r] = (dp[l][r] + res) % mod;
                }
            }
        }
    }
    cout << dp[0][n - 1];
}
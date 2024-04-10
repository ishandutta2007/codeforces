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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    ve<ve<ve<ve<int>>>> G;
    ve<ve<ve<int>>> dp(a, ve<ve<int>> (b, ve<int> (n + 1, 0)));
    dp[0][0][0] = 1;
    G.pb(dp);
    for (auto c : s) {
        int x = c - '0';
        ve<ve<ve<int>>> dp2(a, ve<ve<int>> (b, ve<int> (n + 1, 0)));
        forn (i, a) forn (j, b) forn (c, n + 1) {
            if (dp[i][j][c] == 0) continue;
            dp2[(i * 10 + x) % a][j][c + 1] = 1;
            dp2[i][(j * 10 + x) % b][c] = 1;
        }
        dp = dp2;
        G.pb(dp);
    }
    int res = 1e18;
    forn (i, n + 1) {
        if (i != 0 && i != n && dp[0][0][i]) {
            res = min(res, abs(n - 2 * i));
        }
    }
    //cout << res << endl;
    if (res == (int) 1e18) {
        cout << -1 << endl;
        return;
    }
    int j;
    forn (i, n + 1) {
        if (i != 0 && i != n && dp[0][0][i] && abs(n - 2 * i) == res) {
            j = i;
        }
    }
    string ans(n, 'B');
    int x = 0, y = 0, z = j;
    for (int tmp = n - 1; tmp >= 0; tmp--) {
        int v = s[tmp] - '0';
        int ok = 0;
        //debug(x, y, z, tmp);
        forn (i, a) forn (j, b) {
            if (ok) continue;
            if (z && G[tmp][i][j][z - 1] && (i * 10 + v) % a == x && j == y) {
                ans[tmp] = 'R';
                x = i, z--;
                ok = 1;
            }
            else if (G[tmp][i][j][z] && i == x && (j * 10 + v) % b == y) {
                ans[tmp] = 'B';
                y = j;
                ok = 1;
            }
        }
    }
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
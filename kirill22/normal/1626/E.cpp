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

const int N = 3e5;
vector<int> g[N];
int ans[N], c[N], cnt[N], dp[N];

void dfs(int v, int pr) {
    int cc = 0;
    cnt[v] = c[v];
    for (auto x : g[v]) {
        if (x != pr) {
            dfs(x, v);
            cnt[v] += cnt[x];
            dp[v] |= dp[x];
            cc |= c[x];
        }
    }
    if (cc && cnt[v] >= 2) {
        dp[v] = 1;
    }
}

void solve(int v, int pr, int x, int y) {
    //debug(v + 1, pr + 1, x, y);
    int x2 = x, y2 = y + c[v], z = 0;
    for (auto u : g[v]) {
        if (u != pr) x2 += dp[u], y2 += cnt[u];
        if (c[u]) z++;
    }
    ans[v] = (x || dp[v] || c[v] || z);
    for (auto u : g[v]) {
        if (u != pr) {
            x2 -= dp[u], y2 -= cnt[u];
            z -= c[u];
            if (y2 >= 2 && z) {
                solve(u, v, 1, y2);
            } else {
                solve(u, v, min(1ll, x2), y2);
            }
            x2 += dp[u], y2 += cnt[u];
            z += c[u];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    forn (i, n) {
        cin >> c[i];
    }
    forn (i, n - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0, -1);
    solve(0, -1, 0, 0);
    forn (i, n) {
        cout << ans[i] << " ";
    }
}
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

const int N = 100000 + 28, p = 73, mod = 1e9 + 7;
pii ans = {-1e9, -1};
ve<int> g[N];
int dp[N];
map<int, int> tmp;

int binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n % 2 == 1) res = (res * a) % mod;
        n >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

void add(int x) {
    tmp[x]++;
}

void del(int x) {
    tmp[x]--;
    if (tmp[x] == 0) tmp.erase(x);
}

void dfs(int v, int pr) {
    //debug(v);
    for (auto x : g[v]) {
        if (x != pr) {
            //debug(v, x);
            dfs(x, v);
            dp[v] = (dp[v] + binpow(p, dp[x])) % mod;
        }
    }
    add(dp[v]);
}

void dfs2(int v, int pr) {
    //debug(v, pr);
    ans = max(ans, {sz(tmp), v});
    //debug(tmp);
    for (auto x : g[v]) {
        if (x == pr) continue;
        del(dp[v]);
        del(dp[x]);
        int A = dp[v], B = dp[x];
        dp[v] = (dp[v] - binpow(p, dp[x]) + mod) % mod;
        dp[x] = (dp[x] + binpow(p, dp[v])) % mod;
        add(dp[v]);
        add(dp[x]);
        dfs2(x, v);
        del(dp[v]);
        del(dp[x]);
        dp[v] = A, dp[x] = B;
        add(dp[v]);
        add(dp[x]);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(dp, dp + N, 0);
    int n;
    cin >> n;
    forn (i, n - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0, -1);
    dfs2(0, -1);
    cout << ans.se + 1;
}
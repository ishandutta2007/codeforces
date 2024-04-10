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

struct brawl_stars {
    vector<array<int, 2>> has;
    int bad, nice;
    
    brawl_stars(int n) {
        has.resize(n, {0, 0});
        bad = 0, nice = n;
    }
    
    void insert(int x, int y, int t, int type) {
        if (has[x][0] && has[x][1]) bad--;
        if (has[x][0] + has[x][1] == 0) nice--;
        has[x][(t + y) % 2] += type;
        if (has[x][0] && has[x][1]) bad++;
        if (has[x][0] + has[x][1] == 0) nice++;
    }
};

const int mod = 998244353;

int binpow(int x, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        n /= 2;
        x = x * x % mod;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    brawl_stars A(n), B(m);
    int bad_chess[2] = {0, 0};
    map<pii, int> dp;
    forn (i, q) {
        int x, y, t;
        cin >> x >> y >> t;
        x--, y--;
        if (dp.find({x, y}) != dp.end()) {
            A.insert(x, y, dp[{x, y}], -1);
            B.insert(y, x, dp[{x, y}], -1);
            bad_chess[(x + y + dp[{x, y}]) % 2]--;
            dp.erase({x, y});
        }
        if (t != -1) {
            dp[{x, y}] = t;
            A.insert(x, y, dp[{x, y}], +1);
            B.insert(y, x, dp[{x, y}], +1);
            bad_chess[(x + y + dp[{x, y}]) % 2]++;
        }
        //debug(A.bad, A.nice, B.bad, B.nice);
        int ans = 0;
        if (A.bad == 0) {
            ans = (ans + binpow(2, A.nice)) % mod;
        }
        if (B.bad == 0) {
            ans = (ans + binpow(2, B.nice)) % mod;
        }
        forn (j, 2) {
            if (!bad_chess[j]) ans = (ans + mod - 1) % mod;
        }
        cout << ans << '\n';
    }
}
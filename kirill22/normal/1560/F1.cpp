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

int solve(int k, ve<int> used, int n) {
    int cnt = 0;
    forn (i, 10) if (used[i]) cnt++;
    if (cnt > k) return -1;
    if (n == 0 || used[0] || k > cnt) return 0;
    int x = 0;
    while (!used[x]) x++;
    int ans = 0;
    forn (i, n) ans = ans * 10 + x;
    return ans;
}

int solve(int n, int k) {
    string S = to_string(n);
    string T = S; sort(all(T)); T.resize(unique(all(T)) - T.begin());
    if (sz(T) <= k) {
        return n;
    }
    int ans = 1;
    forn (i, sz(S)) ans = ans * 10 + 1;
    if (k >= 2) {
        ans = 1;
        forn (i, sz(S)) ans *= 10;
    }
    ve<int> used(10);
    int tmp = 0;
    for (int j = 0; j < sz(S); j++) {
        for (int c = S[j] - '0' + 1; c < 10; c++) {
            used[c]++;
            int z = c;
            for (int v = 0; v < sz(S) - j - 1; v++) z *= 10;
            int x = solve(k, used, sz(S) - j - 1);
            if (x != -1) {
                ans = min(ans, tmp + x + z);
            }
            used[c]--;
        }
        used[S[j] - '0']++;
        int x = S[j] - '0';
        for (int v = 0; v < sz(S) - j - 1; v++) x *= 10;
        tmp += x;
    }
    return ans;
}

int slow(int n, int k) {
    while (1) {
        string S = to_string(n);
        string T = S; sort(all(T)); T.resize(unique(all(T)) - T.begin());
        if (sz(T) <= k) {
            return n;
        }
        n++;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (0) {
        for (int n = 1; ; n++) {
            if (slow(n, 1) != solve(n, 1)) {
                debug(n, 1, slow(n, 1), solve(n, 1));
                return 0;
            }
            if (slow(n, 2) != solve(n, 2)) {
                debug(n, 2, slow(n, 2), solve(n, 2));
                return 0;
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
}
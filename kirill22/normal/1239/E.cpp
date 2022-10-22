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
//#define int long long
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

bitset<25000 * 48 + 1> dp[49][49];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ve<int> a(2 * n);
    forn (i, 2 * n) cin >> a[i];
    sort(all(a));
    ve<ve<int>> ans(2, ve<int> (n));
    ans[0][0] = *a.begin(); a.erase(a.begin());
    ans[1][n - 1] = *a.begin(); a.erase(a.begin());
    int s = sz(a);
    int sum = accumulate(all(a), 0ll) / 2;
    dp[0][0][0] = 1;
    for (int i = 1; i <= s; i++) {
        forn (j, s + 1) dp[i][j] = dp[i - 1][j];
        for (int j = 1; j <= s; j++) {
            dp[i][j] |= (dp[i - 1][j - 1] << a[i - 1]);
        }
    }
    int c = sum;
    while (!dp[s][s / 2][c]) c--;
    ve<int> L, R;
    int ts = s, tc = s / 2;
    while (ts) {
        if (dp[ts - 1][tc][c]) {
            R.pb(a[ts - 1]);
            ts--;
        } else {
            L.pb(a[ts - 1]);
            ts--, tc--;
            c -= a[ts];
        }
    }
    sort(all(L));
    sort(all(R));
    for (int i = 1; i < n; i++) ans[0][i] = L[i - 1];
    for (int i = n - 2; i >= 0; i--) ans[1][i] = R[n - 2 - i];
    forn (i, 2) {
        forn (j, n) cout << ans[i][j] << " ";
        cout << '\n';
    }
}
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
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i;
    sort(all(a), [&] (int x, int y) { return (r[x] == r[y] ? l[x] < l[y] : r[x] < r[y]); });
    vector<int> b(n);
    for (int i = 0; i < n; i++) b[i] = i;
    sort(all(b), [&] (int x, int y) { return (r[x] - l[x] == r[y] - l[y] ? x < y : r[x] - l[x] < r[y] - l[y]); });
    vector<int> dp(n, 0), dp2(n, 0);
    for (int i = 0; i < n; i++) {
        dp2[b[i]] = 1;
        vector<int> c;
        for (int j = 0; j < i; j++) {
            if (l[b[i]] <= l[b[j]] && r[b[j]] <= r[b[i]]) {
                c.pb(b[j]);
            }
        }
        sort(all(c), [&] (int x, int y) { return (r[x] == r[y] ? l[x] < l[y] : r[x] < r[y]); });
        vector<int> dp3(c.size(), 0);
        for (int j = 0; j < c.size(); j++) {
            dp3[j] = dp2[c[j]];
            int lv = -1, rv = j;
            while (lv + 1 < rv) {
                int mid = (lv + rv) / 2;
                if (r[c[mid]] < l[c[j]]) {
                    lv = mid;
                }
                else rv = mid;
            }
            if (lv != -1) {
                dp3[j] += dp3[lv];
            }
            if (j) dp3[j] = max(dp3[j], dp3[j - 1]);
            dp2[b[i]] = max(dp3[j] + 1, dp2[b[i]]);
        }
    }
    for (int i = 0; i < n; i++) {
        dp[i] = dp2[a[i]];
        for (int j = 0; j < i; j++) {
            if (r[a[j]] < l[a[i]]) {
                dp[i] = max(dp[i], dp[j] + dp2[a[i]]);
            }
        }
    }
    int ans = 0;
    for (auto x : dp) ans = max(ans, x);
    cout << ans << endl;
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
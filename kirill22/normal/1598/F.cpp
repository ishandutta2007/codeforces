#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<int, vector<int>> a;
    int mn[n], b[n], cnt[n];
    gp_hash_table<int, int> A[n];
    forn (i, n) {
        a.clear();
        string s;
        cin >> s;
        int bal = 0;
        mn[i] = 1e18;
        forn (j, sz(s)) {
            bal += (s[j] == '(' ? 1 : -1);
            mn[i] = min(mn[i], bal);
            a[bal].push_back(j);
        }
        b[i] = bal;
        cnt[i] = sz(a[mn[i]]);
        for (auto& [x, y] : a) {
            int pos = y[0];
            if (a.find(x + 1) == a.end()) continue;
            int it = lower_bound(all(a[x + 1]), pos) - a[x + 1].begin();
            A[i][x + 1] = it;
        }
    }
    int sum[(1 << n)];
    forn (msk, (1 << n)) {
        sum[msk] = 0;
        forn (j, n) if (msk >> j & 1) {
            sum[msk] += b[j];
        }
    }
    int dp[(1 << n)];
    dp[0] = 0;
    int ans = 0;
    forn (msk, (1 << n)) {
        if (msk == 0) continue;
        dp[msk] = -1;
        forn (j, n) {
            if (msk >> j & 1) {
                int msk2 = msk ^ (1 << j);
                if (dp[msk2] == -1) continue;
                int bal = sum[msk2];
                if (mn[j] + bal >= 0) {
                    int res = dp[msk2];
                    if (mn[j] + bal == 0) res += cnt[j];
                    dp[msk] = max(dp[msk], res);
                } else {
                    if (A[j].find(-bal) != A[j].end()) {
                        ans = max(ans, dp[msk2] + A[j][-bal]);
                    }
                }
            }
        }
        ans = max(ans, dp[msk]);
        //debug(msk, dp[msk]);
    }
    cout << ans;
}
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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s + s;
    ve<int> pref(2 * n + 1);
    forn (i, 2 * n) {
        pref[i + 1] = pref[i] + (t[i] == '(' ? 1 : -1); 
    }
    multiset<int> tmp;
    int p = -1;
    for (int i = 2 * n - 1; i >= 0; i--) {
        if (sz(tmp) > n) tmp.erase(tmp.find(pref[i + n + 1]));
        if (*tmp.begin() >= pref[i] && i < n && pref[i + n] == pref[i]) {
            p = i;
        }
        tmp.insert(pref[i]);
    }
    if (p == -1) {
        cout << 0 << '\n';
        cout << 1 << " " << 1;
        return 0;
    }
    int ans = 0, x = 0, y = 0;
    forn (i, n) s[i] = t[i + p];
    int bal = 0, tt = 0;
    ve<int> used(n), used2(n);
    for (auto c : s) {
        bal += (c == '(' ? 1 : -1);
        if (bal == 0) ans++, used[tt] = 1;
        if (bal <= 1) used2[tt] = 1;
        tt++;
    }
    vector<pii> temp;
    ve<int> dp(n), dp2(n);
    forn (i, n) {
        if (s[i] == '(') {
            temp.pb({i, 1});
        }
        else {
            dp[i] = temp.back().se;
            dp2[i] = temp.back().fi;
            temp.pop_back();
            if (sz(temp)) {
                temp.back().se += 1;
            }
        }
    }
    int j = -1;
    forn (i, n) {
        if ((j == -1 || dp[i] > dp[j]) && !used[i] && s[i] == ')' && used2[i]) j = i;
    }
    //debug(dp, dp2, j, p);
    if (j != -1) {
        ans += dp[j];
        x = j, y = dp2[j];
    }
    forn (i, n) {
        if (used[i] && dp[i] > ans) {
            ans = dp[i];
            x = i, y = dp2[i];
        }
    }
    cout << ans << '\n';
    cout << (x + p) % n + 1 << " " << (y + p) % n + 1;
}
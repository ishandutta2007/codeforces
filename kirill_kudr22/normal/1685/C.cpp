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

bool check(string s) {
    int bal = 0;
    for (auto c : s) {
        if (c == '(') bal++;
        else bal--;
        if (bal < 0) return  false;
    }
    return true;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (check(s)) {
        cout << 0 << '\n';
        return;
    }
    n *= 2;
    int bal = 0, mbal = 0;
    vector<int> dp(n + 1);
    int v = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') bal++;
        else bal--;
        mbal = min(mbal, bal);
        dp[i + 1] = bal;
        if (mbal >= 0) {
            v = i + 1;
        }
    }
    int pic = 0;
    for (int i = 0; i <= v; i++) {
        if (dp[i] > dp[pic]) {
            pic = i;
        }
    }
    int j = n;
    while (dp[j - 1] >= 0) {
        j--;
    }
    j--;
    int pic2 = j;
    for (int i = j; i <= n; i++) {
        if (dp[i] > dp[pic2]) {
            pic2 = i;
        }
    }
    string t = s;
    reverse(t.begin() + pic, t.begin() + pic2);
    if (check(t)) {
        cout << 1 << '\n' << pic + 1 << " " << pic2 << '\n';
        return;
    }
    pic = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[i] > dp[pic]) {
            pic = i;
        }
    }
    cout << 2 << '\n' << 1 << " " << pic << '\n';
    reverse(s.begin(), s.begin() + pic);
    reverse(s.begin() + pic, s.end());
    //debug(s);
    assert(check(s));
    cout << pic + 1 << " " << n << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
#include<bits/stdc++.h>

using namespace std;

template<typename A, typename B>
string to_string(pair<A, B> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char& c) {
    string res = "'";
    res += c;
    return res + "'";
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template<typename A>
string to_string(A a) {
    string res = "{";
    int f = 0;
    for (const auto& x : a) {
        if (f) {
            res += ", ";
        }
        f = 1;
        res += to_string(x);
    }
    return res + "}";
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
    return "{" + to_string(p.first) + ", " + to_string(p.second) + "}";
}

void debug_out() { cerr << endl; }

template<typename Head, typename... Tail>
void debug_out(Head h, Tail... t) {
    cerr << " " << to_string(h);
    debug_out(t...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << ":] ", debug_out(__VA_ARGS__)
//#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int) (x).size()
#define ld long double
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)

int K = 1024;
int n, m;
string s;
vector<int> opt[1024];
vector<int> dp[1024];
string d[1024];

string get(string s, int j) {
    string res(sz(s), 'a');
    for (int i = 0; i < sz(s); i++) {
        res[(i ^ j)] = s[i];
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    m = (1 << n);
    cin >> s;
    if (m <= 1024) {
        string ans = s;
        forn (i, m) ans = min(ans, get(s, i));
        cout << ans;
        return 0;
    }
    int X = 1024, Y = 10;
    for (int i = 0; i < m; i += X) {
        //debug(i);
        string t = s.substr(i, X);
        opt[i / X].resize(X);
        dp[i / X].resize(X);
        iota(all(opt[i / X]), 0);
        for (int j = 0; j < X; j++) {
            d[j] = get(t, j);
        }
        //debug(t, get(t, 0));
        sort(all(opt[i / X]), [&] (int i, int j) { return d[i] < d[j]; });
        //debug(opt[i / X]);
        int k = 0;
        for (int j = 0; j < X; j++) {
            //debug(i, opt[i / X][j], d[opt[i / X][j]]);
            if (j == 0 || d[opt[i / X][j]] == d[opt[i / X][j - 1]]) {
                dp[i / X][opt[i / X][j]] = k;
            } else {
                k++;
                dp[i / X][opt[i / X][j]] = k;
            }
        }
    }
    string ans = s;
    //debug(ans);
    int k = n - Y;
    forn (msk2, (1 << k)) {
        vector<pii> tmp;
        for (int i = 0; i < m; i += X) {
            tmp.pb({(i ^ (msk2 << Y)), i});
        }
        sort(all(tmp));
        //debug(tmp);
        vector<int> can(X, 1);
        for (auto [x, y] : tmp) {
            int z = y / X;
            int mn = 1e9;
            forn (j, X) if (can[j]) mn = min(mn, dp[z][j]);
            forn (j, X) if (can[j] && dp[z][j] != mn) can[j] = 0;
        }
        //debug(can);
        int msk = 0;
        while (!can[msk]) msk++;
        string res = "";
        for (auto [x, y] : tmp) {
            res += get(s.substr(y, X), msk);
        }
        ans = min(ans, res);
    }
    cout << ans;
}
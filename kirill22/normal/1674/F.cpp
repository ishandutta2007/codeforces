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

const int N = 1000;
char a[N][N];

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    auto id = [&] (int x, int y) {
        return y * n + x;
    };
    int cnt = 0;
    forn (i, n) {
        forn (j, m) {
            cin >> a[i][j];
            cnt += (a[i][j] == '*');
        }
    }
    int ans = 0;
    forn (i, n) forn (j, m) {
        if (a[i][j] == '*' && id(i, j) >= cnt) {
            ans++;
        }
    }
    forn (t, q) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (a[x][y] == '*' && id(x, y) >= cnt) {
            ans--;
        }
        if (a[x][y] == '*') a[x][y] = '.';
        else a[x][y] = '*';
        if (a[x][y] == '*' && id(x, y) >= cnt) {
            ans++;
        }
        if (a[x][y] == '*') {
            cnt++;
            if (a[(cnt - 1) % n][(cnt - 1) / n] == '*') {
                ans--;
            }
        } else {
            if (a[(cnt - 1) % n][(cnt - 1) / n] == '*') {
                ans++;
            }
            cnt--;
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    if (0) cin >> t;
    while (t--) solve();
}
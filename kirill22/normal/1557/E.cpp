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

ve<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0}, dy = {-1, 0, 1, 1, 1, 0, -1, -1};
int n = 8;
int x = 0, y = 0;

int check(pii a) {
    if (a.fi < 0 || a.se < 0 || a.fi >= n || a.se >= n) return 0;
    if (a.fi == x || a.se == y) return 0;
    if (a.fi - a.se == x - y) return 0;
    if (a.fi + a.se == x + y) return 0;
    return 1;
}

int ask() {
    string s;
    cin >> s;
    if (s == "Up-Left") return 0;
    if (s == "Up") return 1;
    if (s == "Up-Right") return 2;
    if (s == "Right") return 3;
    if (s == "Down-Right") return 4;
    if (s == "Down") return 5;
    if (s == "Down-Left") return 6;
    if (s == "Left") return 7;
    return 8;
}

pii get(pii a, int t) {
    return {a.fi + dx[t], a.se + dy[t]};
}

void solve() {
    ve<pii> a;
    forn (i, n) forn (j, n) a.pb({i, j});
    x = 0, y = 0;
    while (1) {
        pii res = a.back();
        y = res.se;
        cout << x + 1 << " " << y + 1 << endl;
        int ans = ask();
        if (ans == 8) return;
        ve<pii> b;
        forn (i, sz(a)) {
            if (check(get(a[i], ans))) b.pb(get(a[i], ans));
        }
        if (sz(b) != sz(a)) {
            a = b;
            continue;
        }
        a = b; b.clear();
        x = a.back().fi;
        cout << x + 1 << " " << y + 1 << endl;
        ans = ask();
        if (ans == 8) return;
        forn (i, sz(a)) {
            if (check(get(a[i], ans))) b.pb(get(a[i], ans));
        }
        if (sz(b) != sz(a)) {
            a = b;
            continue;
        }
        a = b; b.clear();
        while (1) {
            x = a.back().fi;
            if (y > a.back().se) y = a.back().se + 1;
            else y = a.back().se - 1;
            cout << x + 1 << " " << y + 1 << endl;
            int ans = ask();
            if (ans == 8) return;
            forn (i, sz(a)) {
                if (check(get(a[i], ans))) b.pb(get(a[i], ans));
            }
            if (sz(b) != sz(a)) {
                a = b;
                break;
            }
            a = b; b.clear();
        }
    }
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
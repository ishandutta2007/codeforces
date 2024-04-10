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

string s;
vector<int> a;
int tmp = 0;

void solve(int l, int r) {
    if (l + 1 == r) {
        return;
    }
    int m = (l + r) / 2;
    solve(l, m);
    solve(m, r);
    int k = 1, i = l, j = m;
    vector<int> b;
    while (i < m && j < r) {
        if (tmp >= sz(s)) {
            tmp = sz(s) + 1;
            return;
        }
        if (s[tmp] == '0') {
            tmp++;
            b.pb(a[i]);
            i++;
        }
        else {
            tmp++;
            b.pb(a[j]);
            j++;
        }
    }
    for (int v = i; v < m; v++) b.pb(a[v]);
    for (int v = j; v < r; v++) b.pb(a[v]);
    for (int v = l; v < r; v++) a[v] = b[v - l];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int l = 0, r = 100001;
    while (true) {
        int m = (l + r) / 2;
        a.clear();
        tmp = 0;
        a.resize(m);
        iota(all(a), 0);
        solve(0, m);
        if (tmp > sz(s)) {
            r = m;
        }
        else if (tmp < sz(s)) {
            l = m;
        }
        else {
            cout << m << endl;
            ve<int> ans(m);
            forn (i, m) ans[a[i]] = i + 1;
            for (auto x : ans) cout << x << " ";
            return 0;
        }
    }
}
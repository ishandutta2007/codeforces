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

vector<int> f;

void build() {
    f.resize(1e6 + 1);
    for (auto& x : f) x = 0;
}

void upd(int x, int d = 1) {
    while (x < f.size()) f[x] += d, x = (x | (x + 1));
}

int get(int x) {
    int res = 0;
    while (x >= 0) {
        res += f[x];
        x = (x & (x + 1)) - 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = 1;
    int y[n], lx[n], rx[n];
    for (int i = 0; i < n; i++) cin >> y[i] >> lx[i] >> rx[i];
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (lx[i] == 0) {
            a.pb(i);
        }
        else {
            b.pb(i);
        }
    }
    if (a.size() > 0) sort(all(a), [&] (int i, int j) { return (y[i] == y[j] ? i < j : y[i] < y[j]); });
    if (b.size() > 0) sort(all(b), [&] (int i, int j) { return (y[i] == y[j] ? i < j : y[i] < y[j]); });
    int x[m], ly[m], ry[m];
    for (int i = 0; i < m; i++) cin >> x[i] >> ly[i] >> ry[i];
    for (int i = 0; i < m; i++) {
        if (ly[i] == 0 && ry[i] == 1e6) ans++;
    }
    for (int i = 0; i < n; i++) {
        if (lx[i] == 0 && rx[i] == 1e6) ans++;
    }
    vector<int> a2, b2;
    for (int i = 0; i < m; i++) {
        if (ly[i] == 0) {
            a2.pb(i);
        }
        else {
            b2.pb(i);
        }
    }
    if (a2.size() > 0) sort(all(a2), [&] (int i, int j) { return (ry[i] == ry[j] ? i < j : ry[i] < ry[j]); });
    if (b2.size() > 0) sort(all(b2), [&] (int i, int j) { return (ly[i] == ly[j] ? i < j : ly[i] > ly[j]); });
    build();
    int tmp = 0;
    for (auto v : a2) {
        while (tmp < a.size() && y[a[tmp]] <= ry[v]) {
            upd(rx[a[tmp]]);
            tmp++;
        }
        ans += get(1e6) - get(x[v] - 1);
    }
    build();
    tmp = 0;
    for (auto v : a2) {
        while (tmp < b.size() && y[b[tmp]] <= ry[v]) {
            upd(lx[b[tmp]]);
            tmp++;
        }
        ans += get(x[v]);
    }
    build();
    tmp = (int) a.size() - 1;
    for (auto v : b2) {
        while (tmp >= 0 && y[a[tmp]] >= ly[v]) {
            upd(rx[a[tmp]]);
            tmp--;
        }
        ans += get(1e6) - get(x[v] - 1);
    }
    build();
    tmp = (int) b.size() - 1;
    for (auto v : b2) {
        while (tmp >= 0 && y[b[tmp]] >= ly[v]) {
            upd(lx[b[tmp]]);
            tmp--;
        }
        ans += get(x[v]);
    }
    cout << ans;
}
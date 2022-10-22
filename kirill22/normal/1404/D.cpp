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

vector<vector<int>> g;
vector<int> color;

void dfs(int v, int c) {
    color[v] = c;
    for (auto x : g[v]) {
        if (color[x] == -1) dfs(x, 1 - c);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "First" << endl;
        for (int i = 0; i < 2 * n; i++) {
            cout << i % n + 1 << " ";
        }
        cout << endl;
        int x;
        cin >> x;
        return 0;
    }
    cout << "Second" << endl;
    g.resize(2 * n);
    color.resize(2 * n, -1);
    vector<vector<int>> a(n);
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        x--;
        a[x].pb(i);
        if (i < n) {
            g[i].pb(i + n);
            g[i + n].pb(i);
        }
        if (a[x].size() == 2) {
            g[a[x][0]].pb(a[x][1]);
            g[a[x][1]].pb(a[x][0]);
        }
    }
    for (int i = 0; i < 2 * n; i++) if (color[i] == -1) dfs(i, 0);
    int s = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (color[i] == 0) s += i + 1;
    }
    for (int x = 0; x < n; x++) {
        if (s % (2 * n) == 0) {
            if (color[a[x][0]] == 0) cout << a[x][0] + 1 << " ";
            else cout << a[x][1] + 1 << " ";
        }
        else {
            if (color[a[x][0]] == 1) cout << a[x][0] + 1 << " ";
            else cout << a[x][1] + 1 << " ";
        }
    }
    cout << endl;
    int x;
    cin >> x;
}
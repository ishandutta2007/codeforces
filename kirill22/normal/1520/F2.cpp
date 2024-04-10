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

vector<int> f;

void update(int i, int x) {
    while (i < sz(f)) f[i] += x, i |= (i + 1);
}

int get(int x) {
    int res = 0;
    while (x >= 0) {
        res += f[x];
        x = (x & (x + 1)) - 1;
    }
    return res;
}

void solve() {
    int n, t;
    cin >> n >> t;
    int mx = (n - 1) / 10 + 1;
    f.resize(mx);
    bool f = 0;
    while (t--) {
        int k;
        cin >> k;
        if (!f) {
            f = 1;
            forn (i, mx) {
                int l = i * 10, r = min(n - 1, l + 9);
                cout << "? " << l + 1 << " " << r + 1 << endl;
                int res;
                cin >> res;
                update(i, res);
            }
        }
        int l = 0, r = mx;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            int res = m * 10 - get(m - 1);
            if (res < k) l = m;
            else r = m;
        }
        r--;
        int vl = r * 10, vr = min(n - 1, vl + 9) + 1;
        while (vl + 1 < vr) {
            int m = (vl + vr) / 2;
            cout << "? " << 1 << " " << m << endl;
            int res;
            cin >> res;
            if (m - res >= k) {
                vr = m;
            }
            else {
                vl = m;
            }
        }
        cout << "! " << vr << endl;
        update(r, 1);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    test = 1;
    forn (Clash_Royale_Brawl_Stars_Clash_of_Clans, test) {
        solve();
    }
}
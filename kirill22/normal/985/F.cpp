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
//#define int long long
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

const int mod = 1e9 + 7, p = 101;

ve<int> tmp[26];
ve<int> h[26];
ve<int> pw(3e5 + 1, 1);

int get(int j, int l, int r) {
    r--;
    return (h[j][r + 1] - 1ll *h[j][l] * pw[r - l + 1] + 1ll * mod * mod) % mod;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    forn (i, n) pw[i + 1] = 1ll * pw[i] * p % mod;
    forn (i, n) {
        tmp[s[i] - 'a'].pb(i);
    }
    forn (i, 26) {
        if (sz(tmp[i]) <= 0) continue;
        h[i].resize(sz(tmp[i]));
        for (int j = 1; j < sz(tmp[i]); j++) {
            h[i][j] = (1ll * h[i][j - 1] * p + (tmp[i][j] - tmp[i][j - 1])) % mod;
        }
    }
    while (m--) {
        int x, y, l;
        cin >> x >> y >> l;
        x--, y--;
        int f = 1;
        ve<ve<int>> a, b;
        forn (j, 26) {
            auto it = lower_bound(all(tmp[j]), x) - tmp[j].begin();
            if (it == sz(tmp[j]) || tmp[j][it] > x + l - 1) continue;
            auto it2 = upper_bound(all(tmp[j]), x + l - 1) - tmp[j].begin();
            a.pb({j, it, it2 - 1});
        }
        forn (j, 26) {
            auto it = lower_bound(all(tmp[j]), y) - tmp[j].begin();
            if (it == sz(tmp[j]) || tmp[j][it] > y + l - 1) continue;
            auto it2 = upper_bound(all(tmp[j]), y + l - 1) - tmp[j].begin();
            b.pb({j, it, it2 - 1});
        }
        //debug(a, b);
        if (sz(a) != sz(b)) {
            f = 0;
        }
        else {
            sort(all(a), [&] (ve<int>& A, ve<int>& B) {
                return tmp[A[0]][A[1]] < tmp[B[0]][B[1]];
            });
            sort(all(b), [&] (ve<int>& A, ve<int>& B) {
                return tmp[A[0]][A[1]] < tmp[B[0]][B[1]];
            });
            forn (i, sz(a)) {
                int res = get(a[i][0], a[i][1], a[i][2]);
                int res2 = get(b[i][0], b[i][1], b[i][2]);
                //debug(x, y, res, res2);
                if (res != res2) {
                    f = 0;
                    break;
                }
            }
        }
        if (f) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
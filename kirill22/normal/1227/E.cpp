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

ve<ve<int>> pref;

int get(int x, int y, int x2, int y2) {
    return pref[x2 + 1][y2 + 1] - pref[x2 + 1][y] - pref[x][y2 + 1] + pref[x][y];  
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    ve<ve<char>> a(n, ve<char> (m));
    forn (i, n) {
        forn (j, m) {
            cin >> a[i][j];
        }
    }
    pref.resize(n + 1, ve<int> (m + 1));
    forn (i, n) forn (j, m) {
        pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + (a[i][j] == 'X');
    }
    int l = -1, r = 1e6;
    ve<pii> res, ans;
    ve<ve<int>> used(n + 1, ve<int> (m + 1));
    auto p = used;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        int x = mid * 2 + 1;
        int ok = 1;
        ans.clear();
        forn (i, n + 1) forn (j, m + 1) used[i][j] = p[i][j] = 0;
        forn (i, n) forn (j, m) {
            if (i + x <= n && j + x <= m) {
                if (get(i, j, i + x - 1, j + x - 1) == x * x) {
                    used[i][j]++;
                    used[i][j + x]--;
                    used[i + x][j]--;
                    used[i + x][j + x]++;
                    ans.pb({i + x / 2, j + x / 2});
                }
            }
        }
        //if (mid == 1) debug(ans);
        forn (i, n) {
            forn (j, m) {
                p[i + 1][j + 1] = p[i + 1][j] + p[i][j + 1] - p[i][j] + used[i][j];
                if (a[i][j] == 'X' && p[i + 1][j + 1] == 0) ok = 0;
            }
        }
        if (ok) {
            l = mid;
            res = ans;
        }
        else {
            r = mid;
        }
    }
    cout << l << '\n';
    forn (i, n) forn (j, m) a[i][j] = '.';
    for (auto [x, y] : res) a[x][y] = 'X';
    forn (i, n) {
        forn (j, m) cout << a[i][j];
        cout << '\n';
    }
}
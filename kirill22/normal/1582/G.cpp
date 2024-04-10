#pragma GCC target("popcnt")
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

const int N = 1e6 + 1;
ve<pii> g[N];
ve<int> z[N];

vector<int> eratosfen(int n) {
    vector<int> d(n + 1, 1);
    vector<int> prime;
    for (int i = 2; i <= n; i++) {
        if (d[i] == 1) {
            d[i] = i;
            prime.push_back(i);
        }
        for (auto x : prime) {
            if (x * i > n || x > d[i]) break;
            d[x * i] = x;
        }
    }
    return d;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    auto d = eratosfen(1e6 + 5);
    int n;
    cin >> n;
    int a[n];
    char b[n];
    forn (i, n) cin >> a[i];
    forn (i, n) cin >> b[i];
    forn (i, n) {
        int x = a[i];
        while (x > 1) {
            int c = d[x], cnt = 0;
            while (x % c == 0) {
                x /= c, cnt++;
            }
            if (b[i] == '/') cnt *= -1;
            g[c].pb({i, cnt});
        }
    }
    vector<array<int, 3>> tmp;
    forn (i, N) {
        if (sz(g[i]) == 0) continue;
        //debug(g[i]);
        tmp.clear();
        int s = 0;
        if (g[i][0].fi != 0) {
            tmp.pb({-s, 0, g[i][0].fi - 1});
        }
        forn (j, sz(g[i])) {
            if (j > 0 && g[i][j - 1].fi + 1 <= g[i][j].fi - 1) {
                tmp.pb({-s, g[i][j - 1].fi + 1, g[i][j].fi - 1});
            }
            if (g[i][j].se > 0) {
                s += g[i][j].se;
                tmp.pb({-s + g[i][j].se, g[i][j].fi, g[i][j].fi});
            } else {
                z[g[i][j].fi].pb(g[i][j].fi + 5);
                z[g[i][j].fi + 1].pb(-g[i][j].fi - 5);
                s += g[i][j].se;
                while (sz(tmp) && tmp.back()[0] + s < 0) {
                    z[tmp.back()[1]].pb(g[i][j].fi + 5);
                    z[tmp.back()[2] + 1].pb(-g[i][j].fi - 5);
                    tmp.pop_back();
                }
            }
        }
    }
    long long ans = 0;
    multiset<int> A;
    forn (i, n) {
        for (auto x : z[i]) {
            if (x > 0) {
                A.insert(x - 6);
            } else {
                A.erase(A.find(-1 * x - 6));
            }
        }
        if (sz(A) == 0) {
            ans += n - 1 - i + 1;
            continue;
        }
        ans += (*A.begin()) - i + 1;
    }
    cout << ans;
}
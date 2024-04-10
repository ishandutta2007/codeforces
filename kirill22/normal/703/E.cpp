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

void upd(pair<int, long long>& x, pair<int, long long> y, long long z) {
    if (x.fi == -1) {
        x = {y.fi + 1, y.se + z};
    }
    else {
        x = min(x, {y.fi + 1, y.se + z});
    }
}

pair<int, long long> pr[1000 + 1][7000];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long k;
    cin >> n >> k;
    if (k == 1) {
        cout << 1 << '\n';
        ve<int> a(n);
        forn (i, n) cin >> a[i];
        cout << min_element(all(a)) - a.begin() + 1;
        return 0;
    }
    ve<long long> d;
    for (long long i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            d.pb(i);
            if (k / i != i) d.pb(k / i);
        }
    }
    sort(all(d));
    ve<long long> z;
    forn (i, sz(d)) {
        int f = 1;
        forn (j, i) {
            if (d[i] % d[j] == 0 && d[j] != 1) f = 0;
        }
        if (f) z.pb(d[i]);
    }
    unordered_map<long long, int> uk;
    forn (i, sz(d)) uk[d[i]] = i;
    int m = sz(d);
    ve<pair<pair<int, long long>, int>> tmp(m, {{-1, -1}, -1});
    ve<ve<int>> go(m, ve<int> (sz(z)));
    forn (i, m) {
        forn (j, sz(z)) {
            if (d[i] % z[j] != 0) {
                go[i][j] = i;
            }
            else go[i][j] = uk[d[i] / z[j]];
        }
    }
    tmp[m - 1] = {{0, 0}, 0};
    ve<pair<int, long long>> dp(m);
    ve<long long> cnt(m);
    for (int i = 1; i <= n; i++) {
        long long value;
        cin >> value;
        fill(all(dp), make_pair(-1, -1));
        iota(all(cnt), 0);
        forn (v, sz(z)) {
            int p = z[v];
            if (p == 1) continue;
            int c = 0;
            long long tmp = value;
            while (tmp % p == 0) c++, tmp /= p;
            forn (i, m) {
                forn (V, c) {
                    if (go[cnt[i]][v] == cnt[i]) break;
                    cnt[i] = go[cnt[i]][v];
                }
            }
        }
        forn (j, m) {
            if (tmp[j].se == -1) continue;
            int x = cnt[j];
            pair<int, long long> res = dp[x];
            upd(dp[x], tmp[j].fi, value);
            if (dp[x] != res) {
                pr[i][x] = {tmp[j].se, j};
            }
        }
        forn (j, m) {
            if (dp[j].fi == -1) continue;
            if (tmp[j].se == -1 || dp[j] < tmp[j].fi) {
                tmp[j] = {dp[j], i};
            }
        }
    }
    if (tmp[0].se == -1) {
        cout << -1;
        return 0;
    }
    ve<int> ans;
    int id = tmp[0].se, j = 0;
    while (id > 0) {
        ans.pb(id);
        tie(id, j) = pr[id][j];
    }
    cout << sz(ans) << '\n';
    for (auto x : ans) cout << x << " ";
}
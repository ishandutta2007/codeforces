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

void solve() {
    int n, m;
    cin >> n >> m;
    ve<ve<int>> a(n, ve<int> (m));
    forn (i, n) {
        forn (j, m) {
            cin >> a[i][j];
        }
    }
    ve<ve<int>> pmx(n, ve<int> (m + 1));
    ve<ve<int>> pmn(n, ve<int> (m + 1, 1e9));
    forn (i, n) {
        forn (j, m) {
            pmx[i][j + 1] = max(pmx[i][j], a[i][j]);
            pmn[i][j + 1] = min(pmn[i][j], a[i][j]);
        }
    }
    ve<ve<int>> smx(n, ve<int> (m + 1));
    ve<ve<int>> smn(n, ve<int> (m + 1, 1e9));
    forn (i, n) {
        for (int j = m - 1; j >= 0; j--) {
            smx[i][j] = max(smx[i][j + 1], a[i][j]);
            smn[i][j] = min(smn[i][j + 1], a[i][j]);
        }
    }
    ve<int> BL(n), BR(n);
    ve<int> d;
    for (int k = 1; k < m; k++) {
        int RR = 0, RL = 1e9;
        d.clear();
        forn (i, n) {
            d.pb(i);
        }
        sort(all(d), [&] (int x, int y) { return smx[x][k] < smx[y][k]; });
        for (int i = n - 1; i >= 0; i--) {
            BL[i] = pmx[d[i]][k];
            BR[i] = smn[d[i]][k];
            if (i + 1 < n) {
                BL[i] = max(BL[i], BL[i + 1]);
                BR[i] = min(BR[i], BR[i + 1]);
            }
        }
        int j = 0;
        ve<int> tmp;
        while (j < sz(d)) {
            int c = smx[d[j]][k];
            while (j < sz(d) && smx[d[j]][k] == c) {
                int i = d[j];
                j++;
                tmp.pb(i);
                RL = min(RL, pmn[i][k]);
                RR = max(RR, smx[i][k]);
            }
            //if (k == 3) debug(RL, j, d, BL, BR, RR);
            if (sz(tmp) > 0 && sz(tmp) < n && RL > BL[j] && BR[j] > RR) {
                string ans(n, 'B');
                for (auto x : tmp) ans[x] = 'R';
                cout << "YES\n" << ans << " " << k << '\n';
                return;
            }
        }
    }
    cout << "NO\n";
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
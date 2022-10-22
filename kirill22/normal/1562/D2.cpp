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

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    ve<int> pa(n + 1), pb(n + 1);
    forn (i, n) {
        pa[i + 1] = pa[i];
        pb[i + 1] = pb[i];
        if ((s[i] == '+' && i % 2 == 0) || (s[i] == '-' && i % 2 == 1)) {
            pa[i + 1]++;
            pb[i + 1]--;
        }
        else {
            pa[i + 1]--;
            pb[i + 1]++;
        }
    }
    map<pii, vector<int>> dpa, dpb;
    forn (i, n) {
        dpa[{pa[i], pa[i + 1]}].pb(i);
        dpb[{pb[i], pb[i + 1]}].pb(i);
    }
    auto get = [&] (int l, int r) {
        int res;
        if (l % 2 == 0) {
            res = pa[r + 1] - pa[l];
        }
        else {
            res = pb[r + 1] - pb[l];
        }
        for (auto x : {-1, 1}) {
            int need = (res - x) / 2;
            if (l % 2 == 0) {
                need += pa[l];
                pii key = {need, need + x};
                int it = lower_bound(all(dpa[key]), l) - dpa[key].begin();
                if (it != sz(dpa[key]) && dpa[key][it] <= r) {
                    return dpa[key][it];
                }
            }
            else {
                need += pb[l];
                pii key = {need, need + x};
                int it = lower_bound(all(dpb[key]), l) - dpb[key].begin();
                if (it != sz(dpb[key]) && dpb[key][it] <= r) {
                    return dpb[key][it];
                }
            }
        }
        assert(false);
        return (int) 228;
    };
    forn (i, q) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ok = 1;
        if (l % 2 == r % 2) {
            ok = 0;
        }
        int res;
        if (l % 2 == 0) {
            res = pa[r + 1] - pa[l];
        }
        else {
            res = pb[r + 1] - pb[l];
        }
        if (res != 0) {
            ok = 0;
        }
        if (ok) {
            cout << 0 << '\n';
            continue;
        }
        if (l % 2 == r % 2) {
            cout << 1 << '\n';
            cout << get(l, r) + 1 << '\n';
        }
        else {
            cout << 2 << '\n';
            cout << l + 1 << " " << get(l + 1, r) + 1 << '\n';
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
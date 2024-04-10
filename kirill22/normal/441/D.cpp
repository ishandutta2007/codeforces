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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ve<int> p(n);
    forn (i, n) {
        cin >> p[i];
        p[i]--;
    }
    int k;
    cin >> k;
    k = n - k;
    ve<pii> ans;
    while (1) {
        ve<int> used(n);
        ve<ve<int>> c;
        forn (i, n) {
            if (used[i]) continue;
            ve<int> z;
            while (!used[i]) {
                z.pb(i);
                used[i] = 1;
                i = p[i];
            }
            c.pb(z);
        }
        //debug(c);
        if (sz(c) == k) break;
        if (sz(c) < k) {
            pii res = {1e18, 1e18};
            forn (i, sz(c)) {
                if (sz(c[i]) == 1) continue;
                sort(all(c[i]));
                res = min(res, {c[i][0], c[i][1]});
            }
            swap(p[res.fi], p[res.se]);
            ans.pb(res);
        }
        else {
            pii res = {1e18, 1e18};
            forn (i, sz(c)) {
                int x = 1e18;
                for (auto j : c[i]) x = min(x, j);
                if (res.fi > x) {
                    res.se = res.fi, res.fi = x;
                }
                else res.se = min(res.se, x);
            }
            swap(p[res.fi], p[res.se]);
            ans.pb(res);
        }
    }
    cout << sz(ans) << '\n';
    for (auto [x, y] : ans) cout << x + 1 << " " << y + 1 << " ";
}
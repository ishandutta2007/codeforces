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

template<typename T, class F = function<T(const T&, const T&)>>

class SparseTable {
public :
    int n;
    vector<vector<T>> st;
    F func;

    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = (int) a.size();
        int maxlg = 32 - __builtin_clz(n);
        st.resize(maxlg);
        st[0] = a;
        for (int i = 1; i < maxlg; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j < n - (1 << i) + 1; j++) {
                st[i][j] = func(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T get(int l, int r) const {
        assert(0 <= l && l <= r && r <= n - 1);
        int lg = 32 - __builtin_clz(r - l + 1) - 1;
        return func(st[lg][l], st[lg][r - (1 << lg) + 1]);
    }
}; // SparseTable<int> A(a, [&] (int x, int y) {return max(x, y);}); - c

pii merge(pii x, pii y) {
    if (x.fi < y.fi) return x;
    if (x.fi > y.fi) return y;
    return pair{x.fi, x.se + y.se};
}
 
class SparseTable2 {
public :
    int n;
    vector<pii> t;
    
    void build(int v, int l, int r, const vector<pii>& a) {
        if (l + 1 == r) {
            t[v] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m, a);
        build(v * 2 + 2, m, r, a);
        t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
    } 
    SparseTable2(const vector<pii>& a) {
        n = (int) a.size();
        t.resize(4 * n);
        build(0, 0, n, a);
    }
 
    pii get(int v, int l, int r, int l1, int r1) {
        if (l >= r1 || l1 >= r) return {1e18, 1};
        if (l1 <= l && r <= r1) return t[v];
        int m = (l + r) / 2;
        return merge(get(v * 2 + 1, l, m, l1, r1), get(v * 2 + 2, m, r, l1, r1));
    }
    
    pii get(int l, int r) {
        return get(0, 0, n, l, r + 1);
    }
}; // SparseTable<int> A(a, [&] (int x, int y) {return max(x, y);}); - c

void solve() {
    int n;
    cin >> n;
    ve<int> a(n);
    forn (i, n) cin >> a[i];
    ve<pii> p0(n + 1, {1e18, 1}), p1(n + 1, {1e18, 1});
    p0[0].fi = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            p1[i].fi = a[i - 1] - p0[i - 1].fi;
        } else {
            p0[i].fi = a[i - 1] - p1[i - 1].fi;
        }
    }
    SparseTable<pii> A(p0, [&] (pii x, pii y) {
        if (x.fi < y.fi) return x;
        if (x.fi > y.fi) return y;
        return pair{x.fi, x.se + y.se};
        });
    SparseTable<pii> B(p1, [&] (pii x, pii y) {
        if (x.fi < y.fi) return x;
        if (x.fi > y.fi) return y;
        return pair{x.fi, x.se + y.se};
        });
    SparseTable2 AA(p0);
    SparseTable2 BB(p1);
    int ans = 0;
    forn (i, n) {
        int l = i - 1, r = n;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            int ok = 1;
            int s = 0;
            if (i % 2 == 0) {
                pii res = B.get(i + 1, m + 1);
                if (res.fi + p0[i].fi < 0) ok = 0;
                //if (res.fi + p0[i].fi == 0) s += res.se;
            } else {
                pii res = B.get(i + 1, m + 1);
                if (res.fi - p1[i].fi < 0) ok = 0;
                //if (res.fi - p1[i].fi == 0) s += res.se;
            }
            //debug(i, l, r, m, s);
            if (i % 2 == 0) {
                pii res = A.get(i + 1, m + 1);
                if (res.fi - p0[i].fi < 0) ok = 0;
                //if (res.fi - p0[i].fi == 0) s += res.se;
            } else {
                pii res = A.get(i + 1, m + 1);
                if (res.fi + p1[i].fi < 0) ok = 0;
                //if (res.fi + p1[i].fi == 0) s += res.se;
            }
            //debug(i, l, r, m, s);
            if (ok) l = m;
            else r = m;
        }
        int m = l;
        int s = 0;
        if (i % 2 == 0) {
            pii res = BB.get(i + 1, m + 1);
            if (res.fi + p0[i].fi == 0) s += res.se;
        } else {
            pii res = BB.get(i + 1, m + 1);
            if (res.fi - p1[i].fi == 0) s += res.se;
        }
        //debug(i, l, r, m, s);
        if (i % 2 == 0) {
            pii res = AA.get(i + 1, m + 1);
            //debug(res);
            if (res.fi - p0[i].fi == 0) s += res.se;
        } else {
            pii res = AA.get(i + 1, m + 1);
            if (res.fi + p1[i].fi == 0) s += res.se;
        }
        //debug(i, l, r, m, s);
        ans += s;
    }
    cout << ans << '\n';
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
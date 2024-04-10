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
#define eb emplace_back
#define ld long double

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    SparseTable<int> mx(a, [&] (int x, int y) { return max(x, y); });
    SparseTable<int> mn(a, [&] (int x, int y) { return min(x, y); });
    int x = -1, y = -1, z = -1;
    for (int i = 2; i < n; i++) {
        int res = mx.get(i, n - 1);
        int l = -1, r = i - 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            int res2 = mx.get(0, m);
            int res3 = mn.get(m + 1, i - 1);
            if (res2 >= res && res3 >= res) r = m;
            else l = m;
        }
        if (r != i - 1) {
            int res2 = mx.get(0, r);
            int res3 = mn.get(r + 1, i - 1);
            if (res == res2 && res2 == res3) {
                x = r + 1, z = n - i;
                y = n - x - z;
            }
        }
    }
    if (x == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << x << " " << y << " " << z << '\n';
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
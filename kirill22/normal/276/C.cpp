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

template<typename T>
struct fenwick_tree {
    int n = 0;
    T sum = 0;
    vector<T> tree;

    fenwick_tree(int _n = -1) {
        if (_n >= 0) init(_n);
    }

    void init(int _n) {
        n = _n;
        sum = 0;
        tree.assign(n, 0);
    }

    template<typename T_array>
    void build(const T_array& a) {
        assert((int) a.size() == n);
        tree[0] = a[0];
        for (int i = 1; i < n; i++) tree[i] = tree[i - 1] + a[i];
        for (int i = n - 1; i > 0; i--) {
            int li = (i & (i + 1)) - 1;
            if (li >= 0) tree[i] -= tree[li];
        }
    }

    T getpref(int i) const {
        assert(i < n);
        T res = 0;
        while (i >= 0) {
            res += tree[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }

    T getsuf(int i) const {
        assert(0 <= i);
        if (i >= n) return 0;
        return sum - getpref(i - 1);
    }

    T get(int l, int r) const {
        assert(0 <= l && l <= r && r < n);
        return getpref(r) - getpref(l - 1);
    }

    int find_last_prefix(T x) const {
        if (x < 0) return -1;
        int r = -1;
        int bit = (n == 0 ? -1 : 31 - __builtin_clz(n));
        for (int k = bit; k >= 0; k--) {
            if (r + (1 << k) < n && tree[r + (1 << k)] < x) {
                r += (1 << k);
                x -= tree[r];
            }
        }
        return r + 1;  //  sum[0, r] < x and sum[0, r + 1] >= x
    }

    void update(int i, const T& change) {
        assert(0 <= i && i < n);
        sum += change;
        while (i < n) {
            tree[i] += change;
            i = (i | (i + 1));
        }
    }

    void set(int i, T value) {
        assert(0 <= i && i < n);
        T current = get(i, i);
        update(i, value - current);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    fenwick_tree<int> st(n + 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        st.update(l, 1);
        st.update(r + 1, -1);
    }
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) cnt[i] = st.getpref(i);
    sort(all(cnt));
    int ans = 0;
    for (int i = 0; i < n; i++) ans += cnt[i] * a[i];
    cout << ans;
}
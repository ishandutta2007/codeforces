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
    string s;
    cin >> s;
    map<char, int> st;
    for (auto c : s) st[c]++;
    for (auto el : st) {
        char c = el.fi;
        if (el.se == 1) {
            cout << c;
            string t = "";
            for (auto v : s) if (v != c) t.pb(v);
            sort(all(t));
            cout << t << '\n';
            return;
        }
    }
    if (sz(st) == 1) {
        cout << s << '\n';
        return;
    }
    auto tmp = *st.begin();
    char c = tmp.fi;
    string t = "", ans = "";
    for (auto v : s) if (v != c) t.pb(v);
    sort(rall(t));
    ans.pb(c), ans.pb(c);
    tmp.se -= 2;
    while (tmp.se && sz(t)) {
        ans.pb(t.back());
        ans.pb(c);
        t.pop_back();
        tmp.se--;
    }
    if (tmp.se == 0) {
        reverse(all(t));
        ans = ans + t;
        cout << ans << '\n';
        return;
    }
    if (sz(st) == 2) {
        auto el = *st.begin(), el2 = *st.rbegin();
        cout << el.fi << el2.fi;
        cout << string(el2.se - 1, el2.fi) << string(el.se - 1, el.fi) << '\n';
        return;
    }
    auto it = st.begin(); it++;
    auto it2 = st.begin(); it2++; it2++;
    auto A = *st.begin(), B = *it, C = *it2;
    cout << A.fi << B.fi << string(A.se - 1, A.fi) << C.fi;
    st[B.fi]--, st[A.fi] = 0, st[C.fi]--;
    for (auto el : st) {
        while (el.se--) {
            cout << el.fi;
        }
    }
    cout << '\n';
}

signed main() {
    //
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
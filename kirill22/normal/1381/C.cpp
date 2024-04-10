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
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<int> gist(n + 2, 0);
    set<pii> st;
    for (int i = 0; i < n; i++) gist[b[i]]++;
    int r = -1;
    for (int i = 1; i <= n + 1; i++) {
        if (gist[i] == 0) r = i;
        st.insert({gist[i], i});
    }
    for (int i = 0; i < x; i++) {
        auto el = *st.rbegin();
        st.erase(el);
        el.fi--;
        st.insert(el);
    }
    int z = (*st.rbegin()).fi;
    vector<int> gist2(n + 2, 0), gist3;
    for (auto x : st) gist2[x.se] = x.fi;
    gist3 = gist2;
    vector<int> upd;
    for (int i = 0; i < n; i++) {
        if (gist2[b[i]] < gist[b[i]]) {
            a[i] = b[i];
            gist2[b[i]]++;
        }
        else {
            a[i] = r;
            upd.pb(i);
        }
    }
    sort(all(upd), [&] (int x, int y) {
         if (b[x] == b[y]) return x < y;
         if (gist3[b[x]] == gist3[b[y]]) return b[x] < b[y];
         return gist3[b[x]] > gist3[b[y]];
    });
    int N = upd.size();
    for (int i = 0; i < N; i++) {
        a[upd[i]] = b[upd[(i + z) % N]];
    }
    for (int i = 0; i < n - y; i++) a[upd[((i - z) % N + N) % N]] = r;
    for (int i = 0; i < n; i++) if (a[i] == b[i]) x--;
    for (int i = 0; i < n; i++) {
        if (gist[a[i]] > 0) {
            y--;
            gist[a[i]]--;
        }
    }
    if (x == 0 && y == 0) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
    else {
        cout << "NO" << endl;
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
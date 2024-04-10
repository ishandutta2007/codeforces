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

string to_string(const char* s) {
    return to_string((string) s);
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
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

pii query(vector<int>& a) {
    cout << "? " << a.size() << " ";
    for (auto x : a) cout << x + 1 << " ";
    cout << endl;
    pii ans;
    cin >> ans.fi >> ans.se;
    ans.fi--;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> g[n], gl[n], h(n, 1e9);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    vector<int> tmp;
    for (int i = 0; i < n; i++) tmp.pb(i);
    auto res = query(tmp);
    int root = res.fi, d = res.se, maxh = 0;
    queue<int> st;
    st.push(root);
    h[root] = 0;
    while (!st.empty()) {
        int x = st.front();
        st.pop();
        gl[h[x]].pb(x);
        for (auto v : g[x]) {
            if (h[v] == 1e9) {
                h[v] = h[x] + 1;
                st.push(v);
            }
        }
    }
    maxh = *max_element(all(h));
    int l = (d - 1) / 2, r = min(d, maxh) + 1, ans1 = -1, ans2 = -1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        res = query(gl[m]);
        //debug(l, r, m, res);
        if (res.se > d) {
            r = m;
        }
        else {
            l = m;
            ans1 = res.fi;
        }
    }
    fill(all(h), 1e9);
    h[ans1] = 0;
    st.push(ans1);
    while (!st.empty()) {
        int x = st.front();
        st.pop();
        for (auto v : g[x]) {
            if (h[v] == 1e9) {
                h[v] = h[x] + 1;
                st.push(v);
            }
        }
    }
    vector<int> z;
    for (int i = 0; i < n; i++) if (h[i] == d) z.pb(i);
    res = query(z);
    ans2 = res.fi;
    cout << "! " << ans1 + 1 << " " << ans2 + 1 << endl;
    string s;
    cin >> s;
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
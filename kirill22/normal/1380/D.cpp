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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, k, y;
    cin >> n >> m >> x >> k >> y;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int j = 0, pr = -1;
    vector<pii> c;
    for (int i = 0; i < n; i++) {
        if (j < m && a[i] == b[j]) {
            if (j == 0) {
                c.pb({0, i - 1});
            }
            else {
                c.pb({pr + 1, i - 1});
            }
            if (j == m - 1) {
                c.pb({i + 1, n - 1});
            }
            j++;
            pr = i;
        }
    }
    if (j != m) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    for (auto el : c) {
        int l = el.fi, r = el.se;
        if (r < l) continue;
        if (r - l + 1 < k) {
            int mx = -1, mx2 = -1;
            for (int i = l; i <= r; i++) mx = max(mx, a[i]);
            if (l != 0) mx2 = max(mx2, a[l - 1]);
            if (r != n - 1) mx2 = max(mx2, a[r + 1]);
            if (mx2 >= mx) {
                ans += (r - l + 1) * y;
            }
            else {
                cout << -1;
                return 0;
            }
        }
        else if (y * k >= x) {
            ans += ((r - l + 1) / k) * x + ((r - l + 1) % k) * y;
        }
        else {
            int mx = -1, mx2 = -1;
            for (int i = l; i <= r; i++) mx = max(mx, a[i]);
            if (l != 0) mx2 = max(mx2, a[l - 1]);
            if (r != n - 1) mx2 = max(mx2, a[r + 1]);
            if (mx2 >= mx) {
                ans += (r - l + 1) * y;
            }
            else {
                ans += x + (r - l + 1 - k) * y;
            }
        }
        //debug(l, r, ans);
    }
    cout << ans;
}
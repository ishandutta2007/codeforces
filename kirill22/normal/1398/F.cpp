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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pii> a = {{0, n - 1}};
    char c = 'a';
    for (int i = 0; i < n; i++) {
        if (c == s[i]) {
            a[(int) a.size() - 1].se = i - 1;
            a.pb({i, n - 1});
            c = (s[i] == '1' ? '0' : '1');
        }
        else {
            if (c == 'a' && s[i] != '?') c = (s[i] == '1' ? '0' : '1');
        }
    }
    for (int j = 0; j < a.size(); j++) {
        int x = a[j].se - a[j].fi + 1;
        int y = 0;
        for (int i = a[j].se; i >= a[j].fi && s[i] == '?'; i--) y++;
        a[j] = {x, y};
    }
    for (int j = 1; j <= n; j++) {
        int ans = 0, t = 0;
        for (auto el : a) {
            //debug(el, t);
            int p = el.fi + t;
            ans += p / j;
            t = min(p % j, el.se);
        }
        cout << ans << " ";
        vector<pii> b;
        t = 0;
        int z = 0;
        for (auto el : a) {
            el.fi += z;
            int p = el.fi + t;
            if (p <= j) {
                if (b.size() > 0) b[(int) b.size() - 1].se = 0;
                t = 0;
                z = el.se;
            }
            else {
                z = 0;
                b.pb(el);
                t = el.se;
            }
        }
        a = b;
    }
}
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

vector<int> eratosfen(int n) {
    vector<int> d(n + 1, 1);
    vector<int> prime;
    for (int i = 2; i <= n; i++) {
        if (d[i] == 1) {
            d[i] = i;
            prime.push_back(i);
        }
        for (auto x : prime) {
            if (x * i > n || x > d[i]) break;
            d[x * i] = x;
        }
    }
    return d;
}

vector<int> kek;

void solve() {
    int n;
    cin >> n;
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int res = 1, pr = 1, cnt = 0;
        while (x != 1) {
            int d = kek[x];
            x /= d;
            if (pr != d) {
                if (cnt % 2 == 1) res *= pr;
                cnt = 1, pr = d;
            }
            else {
                cnt++;
            }
        }
        if (cnt % 2 == 1) res *= pr;
        a[res]++;
    }
    map<int, int> b;
    int ans1 = 0, ans2 = 0, ans3 = 0;
    for (auto el : a) {
        ans1 = max(ans1, el.se);
        if (el.se % 2 == 0) {
            ans2 += el.se;
        }
        else {
            ans3 = max(ans3, el.se);
            if (el.fi == 1) ans2 += el.se;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (x == 0) {
            cout << ans1 << '\n';
        }
        else {
            cout << max(ans2, ans3) << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    kek = eratosfen(1000000);
    while (q--) {
        solve();
    }
}
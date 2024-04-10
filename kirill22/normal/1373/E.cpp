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
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

int f(int s) {
    if (s <= 9) return s;
    int res = 0, cnt = 1;
    while (s > 9) {
        res = res * 10 + 9;
        s -= 9;
        cnt *= 10;
    }
    res += cnt * (s % 10);
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = -1;
    for (int lst = 0; lst < 10; lst++) {
        if (lst + k < 10) {
            int z = n;
            for (int i = 0; i <= k; i++) z -= lst + i;
            if (z >= 0 && z % (k + 1) == 0) {
                int x = f(z / (k + 1)) * 10 + lst;
                if (ans == -1) ans = x;
                else ans = min(ans, x);
            }
            continue;
        }
        for (int j = 0; j < 9; j++) {
            int z = n;
            for (int i = 0; i <= k; i++) z -= (lst + i) % 10;
            int c = (10 - lst);
            z -= j * c;
            z -= (j + 1) * (k + 1 - c);
            if (z >= 0 && z % (k + 1) == 0) {
                int x = f(z / (k + 1)) * 100 + j * 10 + lst;
                if (ans == -1) ans = x;
                else ans = min(ans, x);
            }
        }
        for (int v = 1; v <= n / 9; v++) {
            int z = n;
            for (int i = 0; i <= k; i++) z -= (lst + i) % 10;
            int c = (10 - lst);
            z -= 9 * c * v;
            z -= k + 1 - c;
            if (z >= 0 && z % (k + 1) == 0) {
                int x = f(z / (k + 1));
                if (x % 10 == 9) continue;
                for (int i = 1; i <= v + 1; i++) x *= 10;
                x += lst;
                int p = 9;
                for (int i = 0; i < v; i++) {
                    p *= 10;
                    x += p;
                }
                if (ans == -1) ans = x;
                else ans = min(ans, x);
            }
        }
    }
    cout << ans << endl;
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
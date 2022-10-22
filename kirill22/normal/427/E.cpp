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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    ve<int> a(n);
    forn (i, n) cin >> a[i];
    sort(all(a));
    if (m == 1) {
        ve<int> dpl(n);
        for (int i = 0; i < n; i++) {
            dpl[i] = a[i];
            if (i) dpl[i] += dpl[i - 1];
        }
        ve<int> dpr(n);
        for (int i = n - 1; i >= 0; i--) {
            dpr[i] = a[i];
            if (i + 1 < n) dpr[i] += dpr[i + 1];
        }
        int ans = 1e18;
        forn (i, n) {
            int res = 0;
            if (i) res += i * a[i] - dpl[i - 1];
            if (i + 1 < n) res += dpr[i + 1] - a[i] * (n - i - 1);
            ans = min(ans, res * 2);
        }
        cout << ans;
        return 0;
    }
    auto solve = [&] (int i) {
        int j = i;
        while (j >= 0 && a[j] == a[i]) j--;
        int ans = 0;
        while (j >= 0) {
            j = j - m + 1;
            j = max(0ll, j);
            ans += a[i] - a[j] + a[i] - a[j];
            j--;
        }
        int ans2 = 0;
        j = i;
        while (j < n && a[j] == a[i]) j++;
        while (j < n) {
            j = j + m - 1;
            j = min(j, n - 1);
            ans2 += a[j] - a[i] + a[j] - a[i];
            j++;
        }
        return ans + ans2;
    };
    sort(all(a));
    int ans = 1e18;
    ve<int> dpl(n);
    forn (i, n) {
        int cnt = i + 1;
        if (cnt <= m) {
            dpl[i] = a[0];
        }
        else {
            int x = (cnt - 1) / m;
            if (m * x == cnt) {
                dpl[i] = a[i - m + 1] + dpl[i - m];
            }
            else {
                dpl[i] = dpl[m * x - 1] + a[m * x];
            }
        }
    }
    ve<int> dpr(n);
    reverse(all(a));
    forn (i, n) {
        int cnt = i + 1;
        if (cnt <= m) {
            dpr[i] = a[0];
        }
        else {
            int x = cnt / m;
            if (m * x == cnt) {
                dpr[i] = a[i - m + 1] + dpr[i - m];
            }
            else {
                dpr[i] = dpr[m * x - 1] + a[m * x];
            }
        }
    }
    reverse(all(dpr));
    reverse(all(a));
    //debug(dpl, dpr);
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        int res = 0;
        if (i) {
            int g = (i + m - 1) / m;
            res += 2 * (g * a[i] - dpl[i - 1]);
        }
        if (j != n) {
            int g = (n - j + m - 1) / m;
            res += 2 * (dpr[j] - g * a[i]);
        }
        ans = min(ans, res);
        i = j + 1;
    }
    //forn (i, n) ans = min(ans, solve(i));
    cout << ans;
}
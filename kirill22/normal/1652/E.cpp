#include<bits/stdc++.h>

using namespace std;

template<typename A, typename B>
string to_string(pair<A, B> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char& c) {
    string res = "'";
    res += c;
    return res + "'";
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template<typename A>
string to_string(A a) {
    string res = "{";
    int f = 0;
    for (const auto& x : a) {
        if (f) {
            res += ", ";
        }
        f = 1;
        res += to_string(x);
    }
    return res + "}";
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
    return "{" + to_string(p.first) + ", " + to_string(p.second) + "}";
}

void debug_out() { cerr << endl; }

template<typename Head, typename... Tail>
void debug_out(Head h, Tail... t) {
    cerr << " " << to_string(h);
    debug_out(t...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << ":] ", debug_out(__VA_ARGS__)
//#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int) (x).size()
#define ld long double
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)

const int N = 2e5, K = 300, K2 = N / K + 10;
const int M = 6e7 + 22, M2 = 3e7 + 11;
int cnt[M];
int a[N], n, ans;
unordered_map<int, int> st;

void solve() {
    for (int z = 0; z <= K; z++) {
        for (int i = 0; i < n; i++) {
            cnt[a[i] - z * i + M2]++;
            ans = min(ans, n - cnt[a[i] - z * i + M2]);
        }
        for (int i = 0; i < n; i++) {
            cnt[a[i] - z * i + M2]--;
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = j + 1; i < min(n, j + K2); i++) {
            int p = a[i] - a[j], p2 = i - j;
            if (abs(p) % p2) continue;
            p /= p2;
            cnt[p + M2]++;
            ans = min(ans, n - cnt[p + M2] - 1);
        }
        for (int i = j + 1; i < min(n, j + K2); i++) {
            int p = a[i] - a[j], p2 = i - j;
            if (abs(p) % p2) continue;
            p /= p2;
            cnt[p + M2]--;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    forn (i, n) cin >> a[i];
    if (n <= 2) {
        cout << 0;
        return 0;
    }
    ans = n;
    for (int t = 0; t < 2; t++) {
        forn (i, n) a[i] *= -1;
        solve();
    }
    cout << ans;
}
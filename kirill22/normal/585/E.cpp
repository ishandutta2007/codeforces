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
//#define int long long
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

const int mod = 1e9 + 7, N = 1e7 + 5;
int dp[N], gist[N], sum[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> D(N + 1, 1);
    vector<int> prime;
    for (int i = 2; i <= N; i++) {
        if (D[i] == 1) {
            D[i] = i;
            prime.push_back(i);
        }
        for (auto x : prime) {
            if (x * i > N || x > D[i]) break;
            D[x * i] = x;
        }
    }
    int n;
    cin >> n;
    ve<int> a(n), pw(n + 1, 1);
    for (int i = 1; i <= n; i++) pw[i] = 1ll * pw[i - 1] * 2 % mod;
    forn (i, n) {
        cin >> a[i];
        gist[a[i]]++;
    }
    sort(all(a));
    int ANS = 0;
    for (int i = N - 1; i >= 1; i--) {
        int cnt = 0;
        for (int j = 1; j * i < N; j++) cnt += gist[j * i];
        dp[i] = (pw[cnt] + mod - 1) % mod;
        sum[i] = dp[i];
        for (int j = 2; j * i < N; j++) dp[i] = (dp[i] - dp[j * i] + mod) % mod;
        if (i != 1) ANS = (ANS + dp[i]) % mod;
    }
    int ans = 0, tmp = 0;
    forn (i, n) {
        if (i && a[i] == a[i - 1]) {
            ans = (ans + tmp) % mod;
            continue;
        }
        tmp = ANS;
        //debug(tmp);
        int x = a[i];
        ve<int> d;
        while (x > 1) {
            d.pb(D[x]);
            x /= D[x];
        }
        sort(all(d));
        d.resize(unique(all(d)) - d.begin());
        for (int msk = 1; msk < (1 << sz(d)); msk++) {
            int p = 1, cnt = 0;
            forn (j, sz(d)) if (msk >> j & 1) {
                cnt++, p *= d[j];
            }
            if (cnt % 2 == 1) tmp = (tmp - sum[p] + mod) % mod;
            else tmp = (tmp + sum[p]) % mod;
            //debug(p, tmp);
        }
        //debug(tmp);
        ans = (ans + tmp) % mod;
    }
    cout << ans;
}
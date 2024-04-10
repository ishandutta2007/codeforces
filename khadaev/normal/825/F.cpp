#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 8888;
int dp[N];

int _log(int n) {
    int ans = 0;
    while (n) {
        ++ans;
        n /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    dp[0] = 0;
    fore(i, 1, n) dp[i] = INF;
    forn(i, 0, n) {
        setmin(dp[i + 1], dp[i] + 2);
        vector<int> pi(n);
        forn(j, i + 1, n) {
            int x = pi[j - 1 - i];
            while (x && s[i + x] != s[j]) {
                x = pi[x - 1];
            }
            if (s[i + x] == s[j]) ++x;
            pi[j - i] = x;
            int len = j - i + 1;
            int k = len - x;
            if (len % k == 0) {
                setmin(dp[i + len], dp[i] + k + _log(len / k));
            } else {
                setmin(dp[i + len], dp[i] + len + 1);
            }
        }
    }
    cout << dp[n] << '\n';
}
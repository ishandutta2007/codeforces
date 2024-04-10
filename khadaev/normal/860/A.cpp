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

const string vowels = "aeiou";

bool vowel(char c) {
    forn(i, 0, 5) if (c == vowels[i]) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    string s;
    cin >> s;
    int n = s.length();
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    fore(i, 1, n) {
        int j = i - 1;
        bool same = true;
        int cnt = 0;
        while (j >= 0) {
            if (vowel(s[j])) {
                same = true;
                cnt = 0;
            } else {
                if (cnt && s[j] != s[j + 1]) same = false;
                ++cnt;
                if (cnt >= 3 && !same) break;
            }
            setmin(dp[i], dp[j] + 1);
            --j;
        }
    }
    vector<int> bnd;
    int i = n, nxt = dp[n];
    while (i) {
        if (dp[i] == nxt) {
            bnd.eb(i);
            nxt--;
        }
        --i;
    }
    reverse(all(bnd));
    int j = 0;
    for (int x : bnd) {
        while (j < x) cout << s[j++];
        cout << ' ';
    }
}
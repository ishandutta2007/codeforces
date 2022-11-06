#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
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

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, p;
    cin >> s >> p;
    int n = s.length(), k = p.length();
    vector<int> nxt(n, -1);
    forn(i, 0, n) {
        int pos = 0;
        forn(j, i, n) {
            if (s[j] == p[pos]) ++pos;
            if (pos == k) {
                nxt[i] = j + 1;
                break;
            }
        }
    }
    int max_cnt = n / k;
    vector<vector<int>> dp(n + 1, vector<int> (max_cnt + 1, INF));
    dp[0][0] = 0;
    forn(i, 0, n) {
        fore(j, 0, max_cnt) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (nxt[i] != -1 && j < max_cnt)
                dp[nxt[i]][j + 1] = min(dp[nxt[i]][j + 1], dp[i][j] + nxt[i] - i - k);
        }
    }
    vector<int> need(max_cnt + 1, INF);
    fore(i, 0, n) {
        fore(j, 0, max_cnt) {
            need[j] = min(need[j], dp[i][j]);
        }
    }
    //for (int x : need) cout << x << ' ';
    vector<int> ans(n + 1);
    int pos = 0;
    fore(i, 0, n) {
        while (pos < max_cnt && need[pos + 1] <= i) ++pos;
        ans[i] = pos;
    }
    fore(i, 0, n) {
        ans[i] = min(ans[i], (n - i) / k);
    }
    fore(i, 0, n) cout << ans[i] << ' ';
}
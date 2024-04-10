#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)
#define rand_int ((rand() << 15) | rand())

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-10;
const ll prime = 31;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int BIG = 1e9 + 239;
const int MAX_N = 5002;
const int MAX_LOG = 19;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

string s, t;
int n, dp[MAX_N][MAX_N];
ll pref[MAX_N], pref2[MAX_N], st[MAX_N];

void init()
{
    pref[0] = 0, pref2[0] = 0;
    st[0] = 1;
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = (pref[i] * prime + (s[i] - 'a' + 1)) % MOD;
        pref2[i + 1] = (pref2[i] * prime + (t[i] - 'a' + 1)) % MOD;
        st[i + 1] = (st[i] * prime) % MOD;
    }
}

ll gett(int l, int r)
{
    ll ans = (pref[r + 1] - pref[l] * st[r - l + 1]) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
}

ll gett2(int l, int r)
{
    ll ans = (pref2[r + 1] - pref2[l] * st[r - l + 1]) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
}

bool check_ok(int l, int r)
{
    int h = (r - l + 1) >> 1;
    if (h == 0) return 0;
    return (gett(l, l + h - 1) == gett(r - h + 1, r));
}

bool check_pal(int l, int r)
{
    return (gett(l, r) == gett2(n - 1 - r, n - 1 - l));
}

int main()
{
    #ifndef ONLINE_JUDGE //*
    #define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout);/**/
    #endif
    cin.sync_with_stdio(0);
    cin >> s;
    n = s.size();
    if (n == 1)
    {
        cout << "1";
        return 0;
    }
    t = s;
    reverse(t.begin(), t.end());
    init();
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int len = 2; len <= n; len++)
        for (int l = 0; l <= n - len; l++)
        {
            int r = (l + len - 1);
            if (!check_pal(l, r))
            {
                dp[l][r] = 0;
                continue;
            }
            dp[l][r] = 1;
            if (!check_ok(l, r))
                continue;
            int h = (r - l + 1) >> 1;
            dp[l][r] = min(dp[l][l + h - 1], dp[r - h + 1][r]) + 1;
        }
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (dp[i][j] > 0)
                ans[dp[i][j] - 1]++;
    for (int i = n - 2; i >= 0; i--)
        ans[i] += ans[i + 1];
    for (int i : ans)
        cout << i << " ";
    return 0;
}
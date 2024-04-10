/*
    Author: isaf27 (Ivan Safonov)
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC

//permanent constants
const ld pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 30;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const int BIG = 2e9 + 239;
const ll MOD = 1e9 + 7; //998244353; //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //rnd(chrono::high_resolution_clock::now().time_since_epoch().count())

//constants
const int M = 2e5 + 239;
const int N = 2e3 + 239;
const int L = 60;
const int LT = 100;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

ll n;
int k;
ll dp[L][X], inv[LT];

ll power(ll a, int k)
{
    if (k == 0) return 1;
    ll t = power(a, k >> 1);
    t = (t * t) % MOD;
    if (k & 1) t = (t * a) % MOD;
    return t;
}

void solve(int s)
{
    for (int i = 0; i <= s; i++) dp[i][0] = 0;
    dp[s][0] = 1;
    for (int i = 0; i < k; i++)
    {
        for (int x = 0; x <= s; x++)
            dp[x][i + 1] = 0;
        for (int x = 0; x <= s; x++)
        {
            for (int y = 0; y <= x; y++)
            {
                dp[y][i + 1] += dp[x][i] * inv[x + 1];
                if (dp[y][i + 1] >= MOD2) dp[y][i + 1] -= MOD2;
            }
        }
        for (int x = 0; x <= s; x++)
            dp[x][i + 1] %= MOD;
    }
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    cin >> n >> k;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < LT; i++) inv[i] = power(i, MOD - 2);
    ll nn = n;
    ll ans = 1;
    for (ll i = 2; i * i <= nn; i++)
        if (n % i == 0)
        {
            int x = 0;
            while (n % i == 0)
            {
                n /= i;
                x++;
            }
            solve(x);
            ll sum = 0;
            for (int t = 0; t <= x; t++)
            {
                ll now = power((i % MOD), t);
                now *= dp[t][k];
                now %= MOD;
                sum += now;
                if (sum >= MOD) sum -= MOD;
            }
            ans = (ans * sum) % MOD;
        }
    if (n > 1)
    {
        solve(1);
        ll sum = 0;
        for (int t = 0; t <= 1; t++)
        {
            ll now = power((n % MOD), t);
            now *= dp[t][k];
            now %= MOD;
            sum += now;
            if (sum >= MOD) sum -= MOD;
        }
        ans = (ans * sum) % MOD;
    }
    cout << ans;
    return 0;
}
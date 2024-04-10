#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll btc = 30;
const ld eps = 1e-10;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7; //(int)(1e9 + 7); //;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 11;
const int T = (1 << 18) + 239;
const int B = 700;
const int X = 5010;

bool is_prime(int x)
{
    if (x == 1)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int kol[X][B], w[X], k, sum[X][B];
int lcp[X][X];
ll f[B], cf[B];

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> prime;
    for (int i = 1; i <= 5000; i++)
        if (is_prime(i))
            prime.push_back(i);
    k = prime.size();
    for (int i = 0; i <= 5000; i++)
        for (int j = 0; j < k; j++)
        {
            int c = 0;
            int x = i;
            while (x)
            {
                x /= prime[j];
                kol[i][j] += x;
            }
        }
    for (int t = 0; t <= 5000; t++)
    {
        sum[t][0] = 0;
        for (int i = 0; i < k; i++)
            sum[t][i + 1] = sum[t][i] + kol[t][i];
    }
    for (int t = 0; t <= 5000; t++)
    {
        for (int i = 5000; i >= t; i--)
        {
            lcp[t][i] = 0;
            if (i < 5000)
                lcp[t][i] = lcp[t][i + 1];
            int cnt = 0;
            for (int x = k - lcp[t][i] - 1; x >= 0; x--, cnt++)
                if (kol[t][x] != kol[i][x])
                    break;
            lcp[t][i] += cnt;
            lcp[i][t] = lcp[t][i];
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        w[x]++;
    }
    ll ans = (ll)(1e18);
    for (int t = 0; t <= 5000; t++)
    {
        for (int i = 0; i <= k; i++)
            f[i] = 0, cf[i] = 0;
        ll cur = 0;
        for (int i = 0; i <= 5000; i++)
        {
            cur += (ll)w[i] * sum[i][k - lcp[t][i]];
            f[k - lcp[t][i]] += w[i];
            if (lcp[t][i] < k)
                cf[k - lcp[t][i] - 1] += 2LL * w[i] * min(kol[t][k - lcp[t][i] - 1], kol[i][k - lcp[t][i] - 1]);
        }
        for (int i = k - 1; i >= 0; i--)
            cf[i] += cf[i + 1];
        ll sl = 0;
        ll cl = 0;
        ll sr = 0;
        ll cr = 0;
        for (int i = 0; i <= k; i++)
        {
            cr += f[i];
            sr += sum[t][i] * f[i];
        }
        for (int i = 0; i <= k; i++)
        {
            cl += f[i];
            sl += sum[t][i] * f[i];
            cr -= f[i];
            sr -= sum[t][i] * f[i];
            ll now = (cl - cr) * sum[t][i] - sl + sr - cf[i];
            ans = min(ans, now + cur);
        }
    }
    cout << ans << "\n";
    return 0;
}
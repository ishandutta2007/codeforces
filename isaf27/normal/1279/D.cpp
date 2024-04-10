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
const int MOD = 998244353; //(int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e6 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20);
const int B = 500;
const int X = 1e4 + 239;

int power(int a, int k)
{
    if (k == 0)
        return 1;
    int t = power(a, k >> 1);
    t = 1LL * t * t % MOD;
    if (k & 1)
        t = 1LL * t * a % MOD;
    return t;
}

int cnt[M];
vector<int> a[M];
int fact[M], inv[M];
int n;

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    fact[0] = 1;
    for (int i = 0; i < M; i++)
        fact[i + 1] = 1LL * fact[i] * (i + 1) % MOD;
    int cur = power(fact[M - 1], MOD - 2);
    for (int i = M - 1; i >= 1; i--)
    {
        inv[i] = 1LL * fact[i - 1] * cur % MOD;
        cur = 1LL * cur * i % MOD;
    }
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        a[i].resize(s);
        for (int j = 0; j < s; j++)
        {
            cin >> a[i][j];
            a[i][j]--;
            cnt[a[i][j]]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j : a[i])
        {
            cur += cnt[j];
            if (cur >= MOD)
                cur -= MOD;
        }
        cur = 1LL * cur * inv[n] % MOD;
        ans += 1LL * cur * inv[(int)a[i].size()] % MOD;
        if (ans >= MOD)
            ans -= MOD;
    }
    ans = 1LL * ans * inv[n] % MOD;
    cout << ans << "\n";
    return 0;
}
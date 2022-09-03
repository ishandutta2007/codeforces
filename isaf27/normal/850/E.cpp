//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0
//#define int ll

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
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const ll MOD = (int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 19);
const int B = 500;
const int X = (1 << 20) + 239;

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

string s;
int n, pw2[X];

void hadamart(vector<int>& b)
{
    for (int t = 1; t < (1 << n); t *= 2)
        for (int s = 0; s < (1 << n); s += 2 * t)
            for (int i = 0; i < t; i++)
            {
                int x = b[s + i];
                int y = b[s + t + i];
                b[s + i] = x + y;
                if (b[s + i] >= MOD) b[s + i] -= MOD;
                b[s + t + i] = x - y;
                if (b[s + t + i] < 0) b[s + t + i] += MOD;
            }
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pw2[0] = 1;
    for (int i = 1; i < X; i++)
    {
        pw2[i] = pw2[i - 1] * 2;
        if (pw2[i] >= MOD)
            pw2[i] -= MOD;
    }
    cin >> n >> s;
    /*int ans = 0;
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < (1 << n); j++)
            if (s[i] == '1' && s[j] == '0')
            {
                ans += pw2[__builtin_popcount(i ^ j)];
                if (ans >= MOD)
                    ans -= MOD;
            }*/
    vector<int> a((1 << n), 0);
    for (int i = 0; i < (1 << n); i++)
        a[i] = (s[i] == '1');
    vector<int> b((1 << n), 0);
    for (int i = 0; i < (1 << n); i++)
        b[i] = (s[i] == '0');
    hadamart(a);
    hadamart(b);
    for (int i = 0; i < (1 << n); i++)
        a[i] = 1LL * a[i] * b[i] % MOD;
    hadamart(a);
    int u = power((1 << n), MOD - 2);
    for (int i = 0; i < (1 << n); i++)
        a[i] = 1LL * a[i] * u % MOD;
    int ans = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        ans += 1LL * a[i] * pw2[__builtin_popcount(i)] % MOD;
        if (ans >= MOD)
            ans -= MOD;
    }
    cout << (3LL * ans % MOD);
    return 0;
}
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
const int BIG = (int)(2e9 + 239);
const int MOD = (int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(4e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 19;
const int T = (1 << 20);
const int B = 500;
const int X = 1e6 + 239;

string s;
int n, p[M], cnt[M];
int a[M];

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll ans = 0;
    cin >> s;
    n = s.size();
    p[0] = 0;
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + (s[i] - '0');
    int sep = min(2 * (int)sqrt(n) + 1, n);
    int mult = n / (sep + 1);
    for (int d = 1; d <= mult; d++)
    {
        for (int i = 0; i <= n; i++)
            a[i] = p[i] * d - i;
        sort(a, a + n + 1);
        int l = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] != a[i - 1])
            {
                ans += ((ll)(i - l) * (ll)(i - l - 1)) / 2LL;
                l = i;
            }
        ans += ((ll)(n + 1 - l) * (ll)(n - l)) / 2LL;
    }
    for (int d = 1; d <= sep; d++)
    {
        for (int i = 0; i < min(n, d); i++)
        {
            int uk = (n - i) / d;
            for (int t = i; t <= n; t += d)
            {
                cnt[p[t]] = 0;
                cnt[p[t] + d] = 0;
            }
            int ad = (mult + 1) * d;
            for (int t = i + uk * d; t >= i; t -= d)
            {
                if (t + ad <= n)
                    cnt[p[t + ad]]++;
                ans += cnt[p[t] + d];
            }
        }
    }
    cout << ans;
    return 0;
}
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
const int X = 2 * (1e6 + 239);
const int Y = (1e6 + 239);

bool prime[X];
int n;
ll pref1[X], pref2[X], x, y;

ll getkol(int l, int r)
{
    if (r < l)
        return 0;
    if (l == 0)
        return pref1[r];
    return pref1[r] - pref1[l - 1];
}

ll getsum(int l, int r)
{
    if (r < l)
        return 0;
    if (l == 0)
        return pref2[r];
    return pref2[r] - pref2[l - 1];
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 2; i < X; i++)
        prime[i] = true;
    for (int i = 2; i < X; i++)
        if (prime[i])
            for (int j = i + i; j < X; j += i)
                prime[j] = false;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pref1[a]++;
        pref2[a] += a;
    }
    for (int i = 1; i < X; i++)
    {
        pref1[i] += pref1[i - 1];
        pref2[i] += pref2[i - 1];
    }
    ll ans = INF;
    int d = (x / y);
    for (int p = 2; p < Y; p++)
        if (prime[p])
        {
            ll sum = 0;
            for (int i = p; i < X; i += p)
            {
                sum += getkol(i - p + 1, i - d - 1) * x;
                int l = max(i - p + 1, i - d);
                sum += (i * getkol(l, i) - getsum(l, i)) * y;
            }
            ans = min(ans, sum);
        }
    cout << ans;
    return 0;
}
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
const int MOD = (int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 19;
const int T = (1 << 20);
const int B = 500;
const int X = 2510;

ll x[X], y[X];
int n, k;
ll cx[X], cy[X];

int mult(ll x1, ll y1, ll x2, ll y2)
{
    ll pr = x1 * y2 - x2 * y1;
    if (pr == 0)
    {
        if (x1 * x2 + y1 * y2 > 0)
            return 0;
        return 2;
    }
    if (pr > 0)
        return 1;
    return 3;
}

ll hx, hy;

bool cmp(tuple<ll, ll, int>& t1, tuple<ll, ll, int>& t2)
{
    ll x1 = get<0>(t1);
    ll y1 = get<1>(t1);
    ll x2 = get<0>(t2);
    ll y2 = get<1>(t2);
    int tp1 = mult(hx, hy, x1, y1);
    int tp2 = mult(hx, hy, x2, y2);
    if (tp1 != tp2)
        return tp1 < tp2;
    return mult(x1, y1, x2, y2) == 1;
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        k = 0;
        for (int j = 0; j < n; j++)
            if (j != i)
            {
                cx[k] = x[j] - x[i];
                cy[k] = y[j] - y[i];
                k++;
            }
        int cnt = 0;
        vector<tuple<ll, ll, int>> al;
        for (int j = 0; j < k; j++)
        {
            int type = mult(cx[0], cy[0], cx[j], cy[j]);
            if (type < 2)
                cnt++;
            al.push_back(make_tuple(cx[j], cy[j], -1));
            al.push_back(make_tuple(-cx[j], -cy[j], 1));
        }
        hx = cx[0];
        hy = cy[0];
        sort(al.begin(), al.end(), cmp);
        for (tuple<ll, ll, int> t : al)
        {
            if (get<2>(t) == -1)
            {
                cnt--;
                sum += (ll)cnt * (ll)(k - 1 - cnt);
            }
            else
                cnt++;
        }
    }
    sum /= 2;
    ll k4 = ((ll)n * (ll)(n - 1) * (ll)(n - 2) * (ll)(n - 3)) / 24LL;
    sum -= k4 * 2;
    sum *= (ll)(n - 4);
    cout << (sum / 2LL) << "\n";
    return 0;
}
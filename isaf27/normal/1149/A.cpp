#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev

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
const ll bt = 31;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(5e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18);
const int B = (int)(trunc(sqrt(M)) + 1);
const int X = (int)(1e4 + 239);

int n, k1, k2, a;

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    k1 = 0;
    k2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 1)
            k1++;
        else
            k2++;
    }
    if (k1 == 0)
    {
        for (int i = 0; i < n; i++)
            cout << "2 ";
        return 0;
    }
    if (k2 == 0)
    {
        for (int i = 0; i < n; i++)
            cout << "1 ";
        return 0;
    }
    cout << "2 1 ";
    for (int i = 0; i < k2 - 1; i++)
        cout << "2 ";
    for (int i = 0; i < k1 - 1; i++)
        cout << "1 ";
    return 0;
}
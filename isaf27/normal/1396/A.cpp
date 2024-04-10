//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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
const int two = 2;
const ld eps = 1e-10;
const ll INF = (ll)(2e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20) + 239;
const int B = 500;
const int X = 1e4 + 239;

int n;
ll a[M];

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << "1 1\n0\n";
        cout << "1 1\n0\n";
        cout << "1 1\n" << -a[0] << "\n";
        return 0;
    }
    cout << 1 << " " << n - 1 << "\n";
    for (int i = 0; i < n - 1; i++)
        cout << (ll)(n - 1) * a[i] << " ";
    cout << "\n";
    cout << 2 << " " << n << "\n";
    for (int i = 1; i < n - 1; i++)
        cout << 0 << " ";
    cout << (ll)(n - 1) * a[n - 1] << "\n";
    cout << 1 << " " << n << "\n";
    for (int i = 0; i < n; i++)
        cout << -(ll)n * a[i] << " ";
    cout << "\n";
    return 0;
}
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
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
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(5e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 19;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = (int)(1e7 + 239);

int n, a[M], b[M], c[M];
int mn[X];

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(mn, -1, sizeof(mn));
    for (int i = 2; i < X; i++)
        if (mn[i] == -1)
            for (int j = i; j < X; j += i)
                if (mn[j] == -1)
                    mn[j] = i;
    memset(b, -1, sizeof(b));
    memset(c, -1, sizeof(c));
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        vector<int> p;
        while (x != 1)
        {
            int t = mn[x];
            while (x % t == 0)
                x /= t;
            p.push_back(t);
        }
        if (p.size() < 2)
            continue;
        b[i] = p[0];
        c[i] = p[1];
        if (a[i] % 2 != 0)
            continue;
        c[i] = a[i];
        while (c[i] % 2 == 0)
            c[i] /= 2;
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << "\n";
    return 0;
}
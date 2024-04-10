#pragma GCC optimize("O3")
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
const int two = 2;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(2e9 + 239);
const ll MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20) + 239;
const int B = 500;
const int X = 110;

int n, k;
vector<int> p;
ll sum;

void gen(int b, vector<int> q)
{
    if (b == k)
    {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                sum += (q[i] > q[j]);
        return;
    }
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            reverse(q.begin() + i, q.begin() + j + 1);
            gen(b + 1, q);
            reverse(q.begin() + i, q.begin() + j + 1);
        }
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    p.resize(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sum = 0;
    gen(0, p);
    ld ans = sum;
    for (int i = 0; i < k; i++)
        ans /= (n * (n + 1)) / 2;
    cout << fixed << setprecision(20);
    cout << ans << "\n";
    return 0;
}
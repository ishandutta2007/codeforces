//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 y00

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
const ll bt = 30;
const ld eps = 1e-9;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(2e9 + 239);
const int MOD = 1e9 + 7; //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20);
const int B = (int)sqrt(M);
const int X = 1e7 + 239;

int prime[X], kol[X];

bool check(int n)
{
    int l = n;
    int r = 0;
    while (n)
    {
        r = 10 * r + (n % 10);
        n /= 10;
    }
    return (l == r);
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
                prime[j] = 0;
    for (int i = 1; i < X; i++)
        prime[i] += prime[i - 1];
    for (int i = 1; i < X; i++)
        kol[i] = kol[i - 1] + check(i);
    int p, q;
    cin >> p >> q;
    for (int i = X - 1; i >= 0; i--)
        if ((ll)q * (ll)prime[i] <= (ll)p * (ll)kol[i])
        {
            cout << i;
            return 0;
        }
    cout << "Palindromic tree is better than splay tree";
    return 0;
}
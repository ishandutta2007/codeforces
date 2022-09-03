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
const int X = 2e3 + 239;


vector<int> get_order(int n)
{
    vector<int> order;
    int l = 0;
    int r = n - 1;
    while (r >= l)
    {
        order.push_back(l);
        l++;
        if (r > l)
        {
            order.push_back(r);
            r--;
        }
    }
    return order;
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> x = get_order(n);
    for (int t = 0; t + 1 < n; t += 2)
    {
        for (int j = 0; j < m; j++)
        {
            cout << x[t] + 1 << " " << j + 1 << "\n";
            cout << x[t + 1] + 1 << " " << m - j << "\n";
        }
    }
    if (n & 1)
    {
        vector<int> y = get_order(m);
        for (int j = 0; j < m; j++)
            cout << x.back() + 1 << " " << y[j] + 1 << "\n";
    }
    return 0;
}
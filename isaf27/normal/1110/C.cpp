/*
    Author: isaf27 (Ivan Safonov)
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 30;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const int BIG = 1e9 + 239;
const int MOD = 1e9 + 7; //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //rnd(chrono::high_resolution_clock::now().time_since_epoch().count())

//constants
const int M = 1e5 + 239;
const int N = 2e3 + 239;
const int L = 20;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

vector<int> ans = {1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};

int slow(int a)
{
    int ans = 0;
    for (int b = 1; b < a; b++)
        ans = max(ans, __gcd((a ^ b), (a & b)));
    return ans;
}

int func(int a)
{
    if ((a & (a + 1)) == 0)
    {
        for (int k = 2; k <= 25; k++)
            if ((1 << k) - 1 == a)
                return ans[k - 2];
        return 1;
    }
    for (int k = 2; k <= 25; k++)
        if ((1 << k) - 1 >= a)
            return (1 << k) - 1;
}

void solve()
{
    int a;
    cin >> a;
    cout << func(a) << "\n";
}

int32_t main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    //for (int k = 2; k <= 25; k++)
    //    cout << slow((1 << k) - 1) << ", ";
    //for (int i = 2; i <= 10000; i++)
    //    if (func(i) != slow(i))
    //        cerr << i << "!!\n";
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
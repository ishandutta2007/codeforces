#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)
#define rand_int ((rand() << 15) | rand())

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-10;
const ll prime = 239;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int BIG = 1e9 + 239;
const int MAX_N = 2 * 1e3 + 1;
const int MAX_T = (1 << 18);
const int MAX_LOG = 19;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
const int two = 2;

int n, m, k;
string s[MAX_N];

int main()
{
    #ifndef ONLINE_JUDGE //*
    #define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout);/**/
    #endif
    cin.sync_with_stdio(0);
    int ans = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
    {
        int b = 0;
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '*')
            {
                ans += max(0, b - k + 1);
                b = 0;
            }
            else
                b++;
        }
        ans += max(0, b - k + 1);
    }
    for (int i = 0; i < m; i++)
    {
        int b = 0;
        for (int j = 0; j < n; j++)
        {
            if (s[j][i] == '*')
            {
                ans += max(0, b - k + 1);
                b = 0;
            }
            else
                b++;
        }
        ans += max(0, b - k + 1);
    }
    if (k == 1)
        ans /= 2;
    cout << ans;
    return 0;
}
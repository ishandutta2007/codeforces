#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

int64 d[110][1100];

int n;

int x[110], y[110];

const int64 mod = 1000 * 1000 * 1000 + 7;

int64 rf[2000];
int64 f[2000];

int64 pw(int64 x, int64 y)
{
    int64 res = 1;
    while (y)
    {
        if (y % 2)
            res = (res * x) % mod, y--;
        else
            x = (x * x) % mod, y /= 2;
    }
    return res;
}

int64 inv(int64 x)
{
    return pw(x, mod - 2);
}

int64 C[1100][1100];
int64 D[110][1100];

int sum[1100];

int main()
{
    rf[0] = 1;
    f[0] = 1;
    for (int i = 1; i < 2000; ++i)
    {
        rf[i] = (rf[i - 1] * inv(i)) % mod;
        f[i] = (f[i - 1] * i) % mod;
    }
    C[0][0] = 1;
    for (int i = 1; i < 1100; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j < 1100; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    memset(d, 0, sizeof(d));
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
        s += x[i];
    }
    reverse(x, x + n);
    sum[n] = 0;
    for (int i = n - 1; i >= 0; --i)
        sum[i] = x[i] + sum[i + 1];
    for (int i = 0; i < n; ++i)
    {
        cin >> y[i];
    }
    reverse(y, y + n);
    /*D[n][0] = 1;
    for (int i = n - 1; i >= 0; --i)
        for (int j = 0; j <= s; ++j)
        {
            if (j == 0)
            {
                D[i][j] = 1;
                continue;
            }
            for (int k = 0; k <= x[i] && k <= j; ++k)
                D[i][j] = (D[i][j] + D[i + 1][j - k]) % mod;
        }*/
    d[0][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= s; ++j)
        {
            if (!d[i][j]) continue;
            for (int t = 0; t <= y[i]; ++t)
            {
                if (j + t - x[i] < 0) continue;
                if (j > sum[i]) continue;
                int64 cur = (d[i][j] * C[sum[i] - j][t]) % mod;
                cur = (cur * C[j + t][x[i]]) % mod;
                d[i + 1][j + t - x[i]] += cur;
                d[i + 1][j + t - x[i]] %= mod;
            }
        }
    }
    int64 res = d[n][0];
    cout << res << "\n";
    return 0;
}
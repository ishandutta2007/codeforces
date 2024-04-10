#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int mod = 2520;

int gcd(int x, int y)
{
    if (!y) return x;
    return gcd(y, x % y);
}

int mods[1 << 9];

int64 p10[25];

int64 d[20][1 << 9][mod];

int64 get(int64 n)
{
    if (n <= 0) return 0;
    int64 res = 0;
    int64 a[25];
    int64 x;
    int cnt = 0;
    x = n;
    while (x)
        a[cnt++] = x % 10LL, x /= 10LL;
    reverse(a, a + cnt);
    for (int i = 0; i < cnt; ++i)
    {
        int64 ost = 0;
        int m = 0;
        for (int j = 0; j < i; ++j)
        {
            if (a[j]) m |= (1 << (a[j] - 1));
            ost = (ost + p10[cnt - j - 1] * a[j]) % mod;
        }
        for (int dig = 0; dig < a[i]; ++dig)
        {
            int m0 = m;
            if (dig) m0 |= (1 << (dig - 1));
            int ost0 = (ost + p10[cnt - i - 1] * dig) % mod;
            int l = cnt - i - 1;
            for (int mask = 0; mask < (1 << 9); ++mask)
            {
                int nm = mask | m0;
                int start = (-ost0) % mods[nm];
                while (start < 0) start += mods[nm];
                for (int o = start; o < mod; o += mods[nm])
                {
                    res += d[l][mask][o];
                }
            }
        }
    }
    return res;
}

int64 stupid(int64 l, int64 r)
{
    int64 res = 0;
    for (int64 i = l; i <= r; ++i)
    {
        int64 x = i;
        bool ok = true;
        while (x) 
        {
            if (x % 10 > 0 && (i % (x % 10) != 0))
            {
                ok = false;
                break;
            }
            x /= 10;
        }
        if (ok) ++res;
    }
    return res;
}

int main()
{
    p10[0] = 1;
    for (int i = 1; i < 25; ++i)
        p10[i] = (p10[i - 1] * 10) % mod;
    for (int i = 0; i < (1 << 9); ++i)
    {
        int t = 1;
        for (int j = 0; j < 9; ++j)
            if ((i >> j) & 1)
            {
                int tmp = gcd(t, j + 1);
                t *= j + 1;
                t /= tmp;
            }
        mods[i] = t;
    }

    d[0][0][0] = 1;
    for (int i = 0; i < 19; ++i)
        for (int j = 0; j < (1 << 9); ++j)
            for (int k = 0; k < mod; ++k)
            {
                if (d[i][j][k] == 0) continue;
                for (int t = 0; t < 10; ++t)
                {
                    int nj = j;
                    if (t) nj |= (1 << (t - 1));
                    d[i + 1][nj][(k * 10 + t) % mod] += d[i][j][k];
                }
            }
    
    int nc;
    cin >> nc;
    for (int it = 0; it < nc; ++it)
    {
        int64 l, r;
        cin >> l >> r;
        cout << (get(r + 1) - get(l)) << "\n";
//      cerr << stupid(l, r) << "\n";
    }
    return 0;
}
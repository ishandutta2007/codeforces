#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>

#define int long long
//#define double long double

using namespace std;

const long long MOD = 998244353;

long long n;
long long x[500000];
long long y[500000];

long long inq(long long a, long long x)
{
    if (x == 0) return 1;
    long long l = inq(a, x / 2);
    if (x % 2) return l * l % MOD * a;
    return l * l % MOD;
}

struct SegTree{
    int v[(1 << 20)];
    private :
    void add(int p, int L, int R, int V)
    {
        if (p + 1 <= L || R <= p)
            return;
        if (L + 1 == R)
        {
            v[V]++;
            return;
        }
        long long M = (L + R) / 2;
        add(p, L, M, 2 * V + 1);
        add(p, M, R, 2 * V + 2);
        v[V] = v[2 * V + 1] + v[2 * V + 2];
    }
    long long summ(int l, int r, int L, int R, int V)
    {
        if (r <= L || R <= l)
            return 0;
        if (l <= L && R <= r)
            return v[V];
        int M = (L + R) / 2;
        return summ(l, r, L, M, 2 * V + 1) + summ(l, r, M, R, 2 * V + 2);
    }
    public :
    long long summ(int l, int r)
    {
        return summ(l, r, 0, n, 0);
    }
    void add(int p)
    {
        add(p, 0, n, 0);
    }
};

signed main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c;
        cin >> d >> e;
        long long ans = 0;
        a = a / 2;

        while (1)
        {
            if (b == 0 && c == 0)
                break;
            if (a == 0)
                break;
            if (b > 0 && c == 0)
            {
                ans += d;
                b--, a--;
            }
            else
            if (c > 0 && b == 0)
            {
                ans += e;
                c--, a--;
            }
            else
            {
                if (d > e)
                {
                    ans += d;
                    b--, a--;
                }
                else
                {
                    ans += e;
                    c--, a--;
                }
            }
        }
        cout << ans << endl;
    }
}
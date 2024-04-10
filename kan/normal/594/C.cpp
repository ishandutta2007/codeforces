#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define fi first
#define se second

struct pt
{
    int x, y, id;
};

inline bool cmpl(const pt &a, const pt &b)
{
    return a.x < b.x;
}

inline bool cmpr(const pt &a, const pt &b)
{
    return a.x > b.x;
}

inline bool cmpu(const pt &a, const pt &b)
{
    return a.y < b.y;
}

inline bool cmpd(const pt &a, const pt &b)
{
    return a.y > b.y;
}

const int maxn = 100005;

pt pl[maxn], pr[maxn], pd[maxn], pu[maxn];
int was[maxn];
int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        pl[i].x = x1 + x2;
        pl[i].y = y1 + y2;
        pl[i].id = i;
        pr[i] = pl[i];
        pu[i] = pl[i];
        pd[i] = pl[i];
    }
    sort(pl, pl + n, cmpl);
    sort(pr, pr + n, cmpr);
    sort(pu, pu + n, cmpu);
    sort(pd, pd + n, cmpd);
    ll answer = 1e18;
    int IT = 1;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int t = 0; t <= k; t++)
            {
                for (int q = 0; q <= k; q++, IT++)
                {
//                     cout << "here " << t << endl;
                    int del = 0;
                    for (int z = 0; z < i; z++) if (was[pl[z].id] < IT)
                    {
                        del++;
                        was[pl[z].id] = IT;
                    }
                    for (int z = 0; z < j; z++) if (was[pr[z].id] < IT)
                    {
                        del++;
                        was[pr[z].id] = IT;
                    }
                    for (int z = 0; z < t; z++) if (was[pu[z].id] < IT)
                    {
                        del++;
                        was[pu[z].id] = IT;
                    }
                    for (int z = 0; z < q; z++) if (was[pd[z].id] < IT)
                    {
                        del++;
                        was[pd[z].id] = IT;
                    }
//                     cout << i << ' ' << j << ' ' << t << ' ' << q << ' ' << del << endl;
                    if (del > k) continue;
                    int minx, miny, maxx, maxy;
                    for (int z = 0; ; z++) if (was[pl[z].id] != IT)
                    {
                        minx = pl[z].x;
                        break;
                    }
                    for (int z = 0; ; z++) if (was[pr[z].id] != IT)
                    {
                        maxx = pr[z].x;
                        break;
                    }
                    for (int z = 0; ; z++) if (was[pu[z].id] != IT)
                    {
                        miny = pu[z].y;
                        break;
                    }
                    for (int z = 0; ; z++) if (was[pd[z].id] != IT)
                    {
                        maxy = pd[z].y;
                        break;
                    }
//                     cout << minx << ' ' << miny << ' ' << maxx << ' ' << maxy << endl;
                    answer = min(answer, (ll)max(1, (maxx - minx + 1) / 2) * max(1, (maxy - miny + 1) / 2));
                }
            }
        }
    }
    cout << answer << endl;
    return 0;
}
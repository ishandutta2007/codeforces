#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

const int inf = 1e9;

int m;

pair<ll, ll> solve()
{
    int h, a, x, y;
    scanf("%d%d", &h, &a);
    scanf("%d%d", &x, &y);
    int was = -1;
    ll cur = h;
    for (int IT = 1; IT < 1e7; IT++)
    {
        cur = (cur * x + y) % m;
        if (cur == a)
        {
            if (was != -1) return {was, IT - was};
            was = IT;
        }
    }
    if (was == -1) return {inf, inf};
    return {was, inf};
}

int main()
{
    scanf("%d", &m);
    auto ans1 = solve();
    auto ans2 = solve();
    if (ans1.first == inf || ans2.first == inf)
    {
        printf("-1\n");
        return 0;
    }
    if (ans1.second == inf)
    {
        if (ans1.first >= ans2.first && (ans1.first - ans2.first) % ans2.second == 0)
        {
            printf(LLD "\n", ans1.first);
        } else printf("-1\n");
        return 0;
    }
    if (ans2.second == inf)
    {
        if (ans2.first >= ans1.first && (ans2.first - ans1.first) % ans1.second == 0)
        {
            printf(LLD "\n", ans2.first);
        } else printf("-1\n");
        return 0;
    }
    for (int IT = 0; IT < 1e7; IT++)
    {
        if (ans1.second * IT + ans1.first >= ans2.first && (ans1.second * IT + ans1.first - ans2.first) % ans2.second == 0)
        {
            printf(LLD "\n", ans1.second * IT + ans1.first);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
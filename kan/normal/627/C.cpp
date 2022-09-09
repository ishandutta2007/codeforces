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

struct tz
{
    int x, p;
};

inline bool operator<(const tz &a, const tz &b)
{
    return a.x < b.x;
}

const int maxn = 200010;
const int inf = 1e9;

tz z[maxn];
deque<tz> q;
int d, n, m;

int main()
{
    scanf("%d%d%d", &d, &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &z[i].x, &z[i].p);
    }
    sort(z + 1, z + m + 1);
    z[0] = {0, inf};
    z[m + 1] = {d, inf};
    m += 2;
    int pos = n;
    ll ans = 0;
    for (int i = 1; i < m; i++)
    {
        if (z[i].x > n)
        {
            while (pos < z[i].x)
            {
                while (!q.empty() && q.front().x <= pos - n) q.pop_front();
                if (q.empty())
                {
                    printf("-1\n");
                    return 0;
                }
                int curd = min(z[i].x - pos, q.front().x - (pos - n));
                ans += (ll)curd * q.front().p;
                pos += curd;
            }
        }
        while (!q.empty() && q.back().p > z[i].p) q.pop_back();
        q.push_back(z[i]);
    }
    cout << ans << endl;
    return 0;
}
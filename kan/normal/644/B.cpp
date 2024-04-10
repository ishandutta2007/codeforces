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

const int maxn = 200005;

pair<int, int> q[maxn];
int n, b;
ll ans[maxn];

int main()
{
    scanf("%d%d", &n, &b);
    ll cur = 0;
    int ql = 0, qr = 0;
    for (int i = 0; i < n; i++)
    {
        int t, d;
        scanf("%d%d", &t, &d);
        while (qr > ql && cur <= t)
        {
            cur += q[ql].fi;
            ans[q[ql].se] = cur;
            ql++;
        }
        if (qr - ql == b)
        {
            ans[i] = -1;
            continue;
        }
        if (ql < qr)
        {
            q[qr++] = {d, i};
        } else
        {
            if (cur > t) q[qr++] = {d, i};
            else {
                cur = t + d;
                ans[i] = cur;
            }
        }
    }
    while (qr > ql)
    {
        cur += q[ql].fi;
        ans[q[ql].se] = cur;
        ql++;
    }
    for (int i = 0; i < n; i++) printf(LLD " ", ans[i]);
    return 0;
}
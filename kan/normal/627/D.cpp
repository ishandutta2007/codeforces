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

int maxd[maxn], maxd2[maxn], sum[maxn], ans[maxn], badfull[maxn];
vector<int> gr[maxn];
int a[maxn];
int mina;
bool poss;
int n, k;

void calcdown(int cur, int pr)
{
    maxd[cur] = 0;
    maxd2[cur] = 0;
    sum[cur] = a[cur] >= mina;
    badfull[cur] = 0;
    ans[cur] = a[cur] >= mina;
    for (auto x : gr[cur]) if (x != pr)
    {
        calcdown(x, cur);
        if (badfull[x] == 0) sum[cur] += ans[x];
        else
        {
//             cout << cur << ' ' << x << endl;
            badfull[cur]++;
            if (ans[x] > maxd[cur])
            {
                maxd2[cur] = maxd[cur];
                maxd[cur] = ans[x];
            } else if (ans[x] > maxd2[cur])
            {
                maxd2[cur] = ans[x];
            }
        }
    }
    if (badfull[cur] == 0) ans[cur] = sum[cur];
    else ans[cur] = sum[cur] + maxd[cur];
    if (a[cur] < mina)
    {
        badfull[cur] = 1;
        ans[cur] = 0;
    }
//     cout << "calcdown " << cur << ' ' << badfull[cur] << ' ' << ans[cur] << endl;
}

void go(int cur, int pr, bool canfullup, int ansup)
{
//     cout << "go " << cur << endl;
    if (poss) return;
    if (canfullup) sum[cur] += ansup;
    else
    {
        badfull[cur]++;
        if (ansup > maxd[cur])
        {
            maxd2[cur] = maxd[cur];
            maxd[cur] = ansup;
        } else if (ansup > maxd2[cur])
        {
            maxd2[cur] = ansup;
        }
    }
    if (a[cur] >= mina)
    {
        int answer = 0;
        if (badfull[cur] == 0) answer = sum[cur];
        else answer = sum[cur] + maxd[cur];
        if (answer >= k)
        {
            poss = true;
            return;
        }
    }
    for (auto x : gr[cur]) if (x != pr)
    {
        if (a[cur] < mina) go(x, cur, false, 0);
        else
        {
            if (badfull[x] == 0)
            {
                if (badfull[cur] == 0) go(x, cur, true, sum[cur] - sum[x]);
                else go(x, cur, false, sum[cur] - sum[x] + maxd[cur]);
            } else
            {
                if (badfull[cur] == 1) go(x, cur, true, sum[cur]);
                else
                {
                    if (maxd[cur] == ans[x]) go(x, cur, false, sum[cur] + maxd2[cur]);
                    else go(x, cur, false, sum[cur] + maxd[cur]);
                }
            }
        }
    }
}

bool can(int b)
{
//     cout << "can " << b << endl;
    mina = b;
    poss = false;
    calcdown(0, -1);
    go(0, -1, true, 0);
    return poss;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    int l = 1;
    int r = 1000001;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (can(m)) l = m;
        else r = m;
    }
    cout << l << endl;
    return 0;
}
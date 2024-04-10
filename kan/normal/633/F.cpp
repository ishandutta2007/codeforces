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

const int maxn = 100005;

ll down1[maxn], down2[maxn];
ll path[maxn];
vector<int> gr[maxn];
int n;
int a[maxn];
ll answer;

void go(int cur, int pr)
{
    down1[cur] = a[cur];
    path[cur] = a[cur];
    ll bestpathsofar = 0;
    for (auto x : gr[cur]) if (x != pr)
    {
        go(x, cur);
        answer = max(answer, path[cur] + path[x]);
        answer = max(answer, down2[x] + down1[cur]);
        answer = max(answer, down1[x] + down2[cur]);
        down2[cur] = max(down2[cur], down2[x] + a[cur]);
        down2[cur] = max(down2[cur], path[x] + down1[cur]);
        down2[cur] = max(down2[cur], bestpathsofar + down1[x] + a[cur]);
        path[cur] = max(path[cur], path[x]);
        path[cur] = max(path[cur], down1[cur] + down1[x]);
        bestpathsofar = max(bestpathsofar, path[x]);
        down1[cur] = max(down1[cur], down1[x] + a[cur]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    go(0, -1);
    cout << answer << endl;
    return 0;
}
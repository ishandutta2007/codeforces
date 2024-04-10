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

const int maxn = 105;

int ans[maxn][maxn];
pair<int, int> a[maxn][maxn];
int n, m, q;


int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) a[i][j] = {i, j};
    }
    for (int i = 0; i < q; i++)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int x;
            scanf("%d", &x);
            x--;
            rotate(a[x], a[x] + 1, a[x] + m);
        } else if (t == 2)
        {
            int x;
            scanf("%d", &x);
            x--;
            auto tmp = a[0][x];
            for (int j = 1; j < n; j++) a[j - 1][x] = a[j][x];
            a[n - 1][x] = tmp;
        } else
        {
            int x, y, v;
            scanf("%d%d%d", &x, &y, &v);
            x--, y--;
            tie(x, y) = a[x][y];
            ans[x][y] = v;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}